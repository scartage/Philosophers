/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:29 by scartage          #+#    #+#             */
/*   Updated: 2023/05/15 17:02:06 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static int	init_data(t_data *data, char **av)
{
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
			printf("Error: Rutina ya completada o argumento invaido\n");
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

static int	init_philo(t_philo *philo, t_data *data)
{
	philo->number_philos = data->number_philos;
	philo->time_eat = data->time_to_eat;
	philo->time_sleep = data->time_to_sleep;
	philo->time_die = data->time_to_die;
	philo->must_eat = data->must_eat;
	philo->id = 0;
	philo->time_start_p = get_time() + (50 * philo->number_philos);
	philo->last_eat = philo->time_start_p;
	data->time_start = philo->time_start_p;
	return (0);
}

/*los flags O_CREAT y O_EXCL que indican que se quiere
	crear un nuevo semáforo y que debe fallar si ya existe
	uno con el mismo nombre*/
static int	init_philos(t_philo *philo)
{
	sem_unlink("/sem_print");
	sem_unlink("/sem_eat");
	sem_unlink("/sem_fork");
	philo->print = sem_open("/sem_print", O_CREAT | O_EXCL, 0644, 1);
	philo->eat = sem_open("/sem_eat", O_CREAT | O_EXCL, 0644, 1);
	philo->fork = sem_open("/sem_fork", O_CREAT | O_EXCL,
			0644, philo->number_philos);
	if (philo->print == SEM_FAILED || philo->fork == SEM_FAILED
		|| philo->eat == SEM_FAILED)
	{
		printf("Error: en la creacion de semaforos\n");
		return (-1);
	}
	return (0);
}

int	init(t_data *data, t_philo *philo, char **av)
{
	if (init_data(data, av) == -1)
		return (-1);
	if (init_philo(philo, data) == -1)
		return (-1);
	if (init_philos(philo) == -1)
		return (-1);
	return (0);
}
