#include "../inc/philo.h"

int init_data(t_data *data, char **av)
{
	data->number_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);

	if (av[5])
	{
		data->times_must_eat = ft_atoi(av[5]);
		if (data->times_must_eat <= 0)
		{
			printf("Error: la cantidad de repeticiones debe ser => 1\n");
			return (-1);
		}
	}
	if (data->number_philo <= 0 || data->time_die <= 0 ||
			data->time_eat <= 0 || data->time_sleep <= 0)
	{
		printf("Error: los parametros deben ser => 1\n");
		return (-1);
	}	
	return (0);
}


int init_mutex(t_data *data)
{
	int count;

	count = 0;
	if (pthread_mutex_init(&data->m_death, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->m_print, NULL) != 0)
		return (-1);
	data->m_fork = malloc(sizeof(pthread_mutex_t) * data->number_philo);
	if (!data->m_fork)
		return (-1);
	while (count <= data->number_philo)
	{
		if (pthread_mutex_init(&data->m_fork[count], NULL) != 0)
			return (-1);
		count++;
	}
	return 0;
}

int init_philos(t_data *data)
{
	int count;

	count = 0; 
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->number_philo);
	if (!data->philo)
		return (-1);
	while (count < data->number_philo)
	{
		data->philo[count].id = count + 1;
		data->philo[count].left_fork = count;
		data->philo[count].right_fork= count - 1; 
		data->philo[count].data = data;
		count++;
	}
	data->philo[0].right_fork = count - 1;
	
	/* Con esto revisamos que esten bien sentados
	 * count = 0;
	while (count < data->number_philo)
	{
		printf("idx philo: %d, left_f: %d, right_f: %d\n", data->philo[count].id,
				data->philo[count].left_fork, data->philo[count].right_fork);
		count++;
	}*/
	return 0;
}

int init(t_data *data, char **av)
{
	if (init_data(data, av) == -1)
		return (-1);
	if (init_mutex(data) == -1)
		return (-1);
	if (init_philos(data) == -1)
		return (-1);
	return (0);
}
