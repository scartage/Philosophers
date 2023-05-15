/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:38:01 by scartage          #+#    #+#             */
/*   Updated: 2023/05/09 16:32:42 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*En caso de que el programa se ejecute con el parametro opcional
 * (data->must_eat), esta funcion busca que cada uno de los filosofos
 * haya comido tal cantidad de veces.
 *
 * Comprobamos que cada philo haya comido mirando si las veces que comieron
 * es igual al numero de philos.
 * 
 * Eaten es el numero de filosofos que han comido x cantidad de veces
 * NO las veces que han comido cada uno.*/
static int	have_eaten(t_data *data)
{
	int		counter;
	int		eaten;

	counter = 0;
	eaten = 0;
	if (data->must_eat > 0)
	{
		while (counter < data->number_philos)
		{
			if (data->philos[counter].has_eaten >= data->must_eat)
				eaten++;
			else
				break ;
			counter++;
		}
		if (eaten >= data->number_philos)
		{
			data->death = 1;
			pthread_mutex_lock(&data->m_print);
			return (-1);
		}
	}
	return (0);
}

/* Se muere cuando el tiempo para morir es menor a la resta del tiempo actual
 * menos la ultima vez que este philo comio*/
static int	ft_die(t_data *data)
{
	int	counter;

	counter = 0;
	while (counter < data->number_philos)
	{
		if ((get_time() - data->philos[counter].last_eat > data->time_to_die))
		{
			pthread_mutex_lock(&data->m_death);
			ft_print_dead(&data->philos[counter]);
			pthread_mutex_unlock(&data->m_death);
			return (-1);
		}
		counter++;
	}
	return (0);
}

/*Esta funcion tiene un bucle el cual se encarga de revisar
 si algun philo ha muerto o si los philo ya han comido las veces
 necesarias (data->must_eat) La unica opcion para salir de este bucle
 es cuando la variable data->death sea != 0*/
int	check_finish(t_data *data)
{
	while (data->death == 0)
	{
		if (have_eaten(data) == -1)
		{
			printf(YEL"Los philos han comido suficiente >:) (%d veces)\n"RESET,
				data->must_eat);
			pthread_mutex_unlock(&data->m_print);
			break ;
		}
		if (ft_die(data) == -1)
			break ;
	}
	return (-1);
}
