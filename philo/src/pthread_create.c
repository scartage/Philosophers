/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phtread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:33:57 by scartage          #+#    #+#             */
/*   Updated: 2023/04/12 16:50:34 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*Documentacion sobre los hilos: https://yewtu.be/watch?v=NAKrOZCcJ4A*/

bool ft_one_philo(t_philo *philo)
{
	if (philo->data->number_philo == 1)
	{
		pthread_mutex_lock(&philo->data->m_fork[philo->left_fork]);
		ft_print_fork(philo);
		ft_usleep(philo->data->time_die + 1);
		return (true);
	}	
	return (false);
}

void *ft_routine(void *arg)
{
	t_philo *philo;
	int		counter;

	philo = (t_philo *)arg;

	//es necesario que los philos pares esperen un rato antes de comenzar
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat);
	//philo->last_eat = (get_time() - philo->data->time_start);
	while (philo->data->death == 0)
	{
		if (ft_one_philo(philo))
			break;
		if (ft_eat(philo) == -1 || ft_sleep(philo) == -1
				|| ft_think(philo) == -1)
			break;
	}

	counter = 0;
	while (counter < philo->data->number_philo)
	{
		pthread_mutex_unlock(&philo->data->m_fork[counter]);
		counter++;
	}
	return philo;
}

int create_pthread(t_data *data)
{
	pthread_t *pthread;
	int counter;

	counter = 0;
	pthread = (pthread_t *)malloc(sizeof(pthread_t) * data->number_philo);
	if (!pthread)
		return (-1);
	while (counter < data->number_philo)
	{
		if (pthread_create(&pthread[counter], NULL, ft_routine, &data->philo[counter]) != 0)
			return (-1);
		counter++;
	}

	ft_check_finish(data);	//bucle infinito checkea si mueren o comen n cantidad
	printf("sale");
	pthread_mutex_unlock(&data->m_print); 
	pthread_mutex_unlock(&data->m_death); 
	counter = 0;
	/*esperamos a que cada hilo finalice antes de volver al main*/
	while (counter < data->number_philo)
	{
		pthread_join(pthread[counter], NULL);
		counter++;
	}
	free(pthread);		//liberamos el array de filosofos
	return 0;
}
