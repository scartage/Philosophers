/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:45:31 by scartage          #+#    #+#             */
/*   Updated: 2023/05/22 18:26:13 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"
#include <stdbool.h>
#include <pthread.h>

void	ft_sleep_think(t_philo *philo)
{
	ft_print_msm("is sleeping", philo);
	ft_usleep(philo->time_sleep);
	ft_print_msm("is thinking", philo);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->eat);
	sem_wait(philo->fork);
	ft_print_msm("has taken a fork", philo);
	sem_wait(philo->fork);
	ft_print_msm("has taken another fork", philo);
	philo->last_eat = get_time() - philo->time_start_p;
	ft_print_msm("is eating", philo);
	philo->must_eat--;
	if (philo->must_eat == 0)
	{
		sem_post(philo->fork);
		sem_post(philo->fork);
		sem_post(philo->eat);
		exit(1);
	}
	sem_post(philo->eat);
	ft_usleep(philo->time_eat);
	sem_post(philo->fork);
	sem_post(philo->fork);
	ft_sleep_think(philo);
}

static bool	one_philo(t_philo *philo)
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

void	*ft_routine(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	while (philo->time_start_p > get_time())
		ft_usleep(5);
	if (one_philo(philo))
		exit (0);
	while (philo->must_eat != 0)
		ft_eat(philo);
	return (NULL);
}

void	ft_pre_routine(t_philo *philo, int counter)
{
	pthread_t	thread;

	philo->id = counter + 1;
	if (pthread_create(&thread, NULL, ft_routine, philo) != 0)
	{
		sem_wait(philo->print);
		printf(RED"Error: creating thread\n"RESET);
		exit(0);
	}
	while (philo->must_eat != 0)
	{
		if (philo->time_die < death_time(philo))
		{
			sem_wait(philo->print);
			printf(RED"[%lld] [%d] died\n"RESET,
				(get_time() - philo->time_start_p), philo->id);
			exit(0);
		}
	}
	pthread_join(thread, NULL);
}
