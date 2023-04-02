/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:40:14 by scartage          #+#    #+#             */
/*   Updated: 2023/04/02 20:48:32 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int ft_die(t_data *data)
{
	int count;

	int count = 0;
	while (count < data->number_philo)
	{
		if (data->time_die < (long long int) (get_time() - data->time_start)
				- data->philo[count].last_eat)
		{
			pthread_mutex_lock(&data->m_death);
			ft_print_death(&data->philo[count])
			pthread_mutex_lock(&data->m_print);
			pthread_mutex_lock(&data->m_forks);
			data->death = 1;
			return (0);
		}
		count++;
	}
	return (1);
}

/*esta funcion nos revisaria dos cosas, si los filosofos han comido n cantidad,
 * lo cual deberia cerrrar el porgrama de una forma y el check de muerte de filosofos.*/
void ft_check_finish(t_data *data)
{
	while (data->death == 0)
	{
		if (ft_die(data) == 0)
			break;
	}
}
