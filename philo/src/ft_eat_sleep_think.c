/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_sleep_think.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:22:01 by scartage          #+#    #+#             */
/*   Updated: 2023/05/09 16:57:41 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_eat(t_philo *philo)
{
	if (philo->data->death == 1)
		return (-1);
	pthread_mutex_lock(&philo->data->m_forks[philo->left_fork]);
	ft_print_fork(philo);
	pthread_mutex_lock(&philo->data->m_forks[philo->right_fork]);
	ft_print_fork(philo);
	philo->last_eat = get_time();
	ft_print_eat(philo);
	philo->has_eaten++;
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->m_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->m_forks[philo->right_fork]);
	if (ft_sleep(philo) == -1)
		return (-1);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (philo->data->death == 1)
		return (-1);
	ft_print_sleep(philo);
	ft_usleep(philo->data->time_to_sleep);
	if (ft_think(philo) == -1)
		return (-1);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (philo->data->death == 1)
		return (-1);
	ft_print_think(philo);
	return (0);
}

int	mid_rutine(t_philo *philo)
{
	if (ft_eat(philo) == -1)
		return (-1);
	return (0);
}

void	*ft_rutine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat);
	while (philo->data->death == 0)
	{
		if (ft_one_philo(philo))
			break ;
		if (mid_rutine(philo) == -1)
			break ;
	}
	return (philo);
}
