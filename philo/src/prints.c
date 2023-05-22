/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:00:35 by scartage          #+#    #+#             */
/*   Updated: 2023/05/22 18:04:51 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld %d has taken a fork\n",
			(get_time() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld %d is eating\n",
			(get_time() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld %d is sleeping\n",
			(get_time() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld %d is thinking\n",
			(get_time() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	ft_print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
	{
		printf(RED"%lld %d died\n"RESET,
			(get_time() - philo->data->start_time), philo->id);
		philo->data->death = 1;
	}
}
