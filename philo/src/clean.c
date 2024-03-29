/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:48:46 by scartage          #+#    #+#             */
/*   Updated: 2023/05/03 18:17:38 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_clean(t_data *data)
{
	int	counter;

	counter = 0;
	pthread_mutex_unlock(&data->m_print);
	pthread_mutex_unlock(&data->m_death);
	pthread_mutex_unlock(data->m_forks);
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->m_death);
	while (counter < data->number_philos)
	{
		pthread_mutex_destroy(&data->m_forks[counter]);
		counter++;
	}
	free(data->m_forks);
	free(data->philos);
	free(data);
}
