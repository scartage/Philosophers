/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:45:31 by scartage          #+#    #+#             */
/*   Updated: 2023/05/15 17:36:56 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"
#include <stdbool.h>

static bool one_philo(t_philo *philo)
{
	if (philo->number_philos == 1)
	{
		sem_wait(philo->eat);
		sem_wait(philo->fork);
		ft_print_msm("has taken a fork", philo);
		ft_usleep(philo->time_die);
		sem_post(philo->fork);
		sem_post(philo->eat);
		return (true);
	}
	return (false);
}

static void ft_routine(t_philo *philo)
{
	while (philo->time_start_p > get_time())
		ft_usleep(5);
	if (one_philo(philo))
	{

		printf("adeu\n");
		exit (-1);

	}
	//if (philo->number_philos == 1)
}


int ft_pre_routine(t_philo *philo, int counter)
{
	philo->id = counter + 1;
	ft_routine(philo);
	return (0);
}

