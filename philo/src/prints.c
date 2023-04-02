/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:26:30 by scartage          #+#    #+#             */
/*   Updated: 2023/04/02 21:08:50 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void ft_print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld the philo %d has taken a fork\n", 
				(get_time() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void ft_print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld the philo %d is eating\n",
				(get_time() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void ft_print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld the philo %d is sleeping\n",
				(get_time() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void ft_print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld the philo %d is thinking\n",
				(get_time() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void ft_print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (philo->data->death == 0)
		printf("%lld the philo %d is DEAD\n",
				(get_time() - philo->data->time_start), philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}
