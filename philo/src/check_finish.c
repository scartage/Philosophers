/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:40:14 by scartage          #+#    #+#             */
/*   Updated: 2023/04/12 16:50:32 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//en el bucle solo empezamos a sumar la variable "finish" cuando
//ya hay por lo menos un filosofo que ha comido mas de las n cantiddes
int ft_have_eaten(t_data *data)
{
	int counter;
	int finish;

	counter = 0;
	finish = 0;
	if (data->times_must_eat == 0)
		return (-1);
	while (counter < data->number_philo)
	{
		if (data->philo[counter].t_eat >= data->times_must_eat)
			finish++;
		else
			break ;
		counter++;
	}
	//si finish es igual al numero de philos es porque ya todos han
	//comido n numero de veces
	if (finish >= data->number_philo)
	{
		data->death = 1;
		pthread_mutex_lock(&data->m_print);
		return (0);
	}
	return (-1);
}
int ft_die(t_data *data)
{
	int count;

	count = 0;
	while (count < data->number_philo)
	{
		if (data->time_die < (long long int) (get_time() - data->time_start)
				- data->philo[count].last_eat)
		{
			pthread_mutex_lock(&data->m_death);
			ft_print_death(&data->philo[count]);
			pthread_mutex_lock(&data->m_print);
			pthread_mutex_lock(data->m_fork);
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
		if (ft_have_eaten(data) == 0)
		{
			printf("All the philos have eaten enough >:)");
			pthread_mutex_unlock(&data->m_print);
			break;
		}
		if (ft_die(data) == 0)
			break;
	}
}
