#include "inc/philo.h"

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
			printf("Error: cantidad de repeticiones no correcta\n");
			return (-1);
		}
	}
	if (data->number_philo <= 0 || data->time_die <= 0 ||
			data->time_eat <= 0 || data->time_sleep <= 0)
		return (-1);
	return (0);
}


int init(t_data *data, char **av)
{
	if (init_data(data, av) == -1)
		return (-1);
	return (0);
}
