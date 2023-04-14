/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:14:32 by scartage          #+#    #+#             */
/*   Updated: 2023/04/14 17:25:35 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void ft_clean(t_data *data)
{
	int counter;

	counter = 0;

	pthread_mutex_unlock(&data->m_print);
	pthread_mutex_unlock(&data->m_death);
	pthread_mutex_unlock(data->m_fork);
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->m_death);
	while (counter < data->number_philo)
	{
		pthread_mutex_destroy(&data->m_fork[counter]);
		counter++;
	}
	free(data->philo);
	free(data->m_fork);
	free(data);
}
