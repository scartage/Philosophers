/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:26:33 by scartage          #+#    #+#             */
/*   Updated: 2023/05/09 16:57:41 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>

bool	ft_one_philo(t_philo *philo)
{
	if (philo->data->number_philos == 1)
	{
		pthread_mutex_lock(&philo->data->m_forks[philo->left_fork]);
		ft_print_fork(philo);
		ft_usleep(philo->data->time_to_die + 1);
		pthread_mutex_unlock(&philo->data->m_forks[philo->left_fork]);
		return (true);
	}
	return (false);
}

static void	checker(t_data *data, pthread_t *pthread)
{
	int	counter;

	if (check_finish(data) == -1)
	{
		counter = 0;
		while (counter < data->number_philos)
		{
			pthread_mutex_unlock(&data->m_forks[counter]);
			counter++;
		}
		pthread_mutex_unlock(&data->m_print);
		counter = 0;
		while (counter < data->number_philos)
		{
			pthread_join(pthread[counter], NULL);
			counter++;
		}
	}
}

int	create_pthread(t_data *data)
{
	pthread_t	*pthread;
	int			counter;

	counter = 0;
	pthread = (pthread_t *)malloc(sizeof(pthread_t) * data->number_philos);
	if (pthread == NULL)
		return (-1);
	while (counter < data->number_philos)
	{	
		if (pthread_create(&pthread[counter], NULL,
				ft_rutine, &data->philos[counter]) != 0)
			return (-1);
		counter++;
	}
	while (data->start_routine > get_time())
		usleep(100);
	checker(data, pthread);
	free(pthread);
	return (0);
}
