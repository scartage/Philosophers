/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:26:05 by scartage          #+#    #+#             */
/*   Updated: 2023/05/09 16:57:42 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>		//para el usleep

int	init_data(t_data *data, char **av)
{
	data->death = 0;
	data->number_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat = 0;
	if (av[5])
	{
		data->must_eat = ft_atoi(av[5]);
		if (data->must_eat <= 0)
		{
			printf("Error: rutina ya compleata o parametro incorrrecto\n");
			return (-1);
		}
	}
	if (data->number_philos <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
	{	
		printf("Error: los parametros deben ser numeros positivos\n");
		return (-1);
	}
	return (0);
}

/*Inicializamos los mutex, hay tantos mutex (para la array de tenedores)
 * como cantidad de philos.
 */
int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->m_print, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->m_death, NULL) != 0)
		return (-1);
	data->m_forks = malloc(sizeof(pthread_mutex_t) * data->number_philos);
	if (data->m_forks == NULL)
		return (-1);
	while (i <= data->number_philos)
	{
		if (pthread_mutex_init(&data->m_forks[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	counter;

	counter = 0;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->number_philos);
	if (data->philos == NULL)
		return (-1);
	while (counter < data->number_philos)
	{
		data->philos[counter].id = counter + 1;
		data->philos[counter].left_fork = counter;
		data->philos[counter].right_fork = counter - 1;
		data->philos[counter].data = data;
		data->philos[counter].last_eat = 0;
		data->philos[counter].has_eaten = 0;
		counter++;
	}
	data->philos[0].right_fork = counter - 1;
	return (0);
}

/*Funcion general para incializar todo.
 * 1) Iniciamos valores de data
 * 2) Iniciamos mutex (forks, m_print, m_death)
 * 3) Iniciamos valores de filosofos */
int	init(t_data *data, char **av)
{
	if (init_data(data, av) == -1)
		return (-1);
	if (init_mutex(data) == -1)
		return (-1);
	if (init_philos(data) == -1)
		return (-1);
	return (0);
}
