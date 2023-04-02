/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:25:25 by scartage          #+#    #+#             */
/*   Updated: 2023/04/02 20:24:30 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int ft_eat(t_philo *philo)
{
	if (philo->data->death != 0)
		return (-1);
	pthread_mutex_lock(&philo->data->m_fork[philo->left_fork]);
	ft_print_fork(philo);
	pthread_mutex_lock(&philo->data->m_fork[philo->right_fork]);
	ft_print_fork(philo);
	philo->last_eat = get_time() - philo->data->time_start;
	ft_print_eat(philo);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->data->m_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->m_fork[philo->right_fork]);
	return (0);
}

int ft_sleep(t_philo *philo)
{
	if (philo->data->death != 0)
		return (-1);
	ft_print_sleep(philo);
	ft_usleep(philo->data->time_sleep);
	return (0);
}

int ft_think(t_philo *philo)
{
	if (philo->data->death != 0)
		return (-1);
	ft_print_think(philo);
	return (0);
}
