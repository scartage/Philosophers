/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:43:45 by scartage          #+#    #+#             */
/*   Updated: 2023/05/15 17:36:39 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"
/* -1 muerte
	1 rutina terminda*/
int check_death(t_data *data)
{
	int counter;
	int status;

	counter = 0;
	while (counter < data->number_philos)
	{
		waitpid(-1, &status, WUNTRACED);
		if (WEXITSTATUS(status) == 65280)
			break ;
		if (WEXITSTATUS(status) == 1)
			counter++;
	}
	//kill_process(data);
	if (counter == data->number_philos)
		return (1);
	return (0);
}

int create_process(t_data *data, t_philo *philo)
{
	int counter;
	int i = 0;

	counter = 0;
	data->pid = malloc(sizeof(pid_t) * data->number_philos);
	if (!data->pid)
		return (-1);
	while (counter < data->number_philos)
	{
		data->pid[counter] = fork();
		if (data->pid[counter] > 0)
		{
			//printf("counter [%d] pid [%d]\n", counter, data->pid[counter]);
			counter++;
		}
		else if (data->pid[counter] == 0)
		{
			printf("soy el hijo de: %d counter[%d]\n", data->pid[counter], counter);
			ft_pre_routine(philo, counter);
			break ;
		}
		else
			return (-1);
	}
	if (check_death(data) == 1)
		printf("Rutina compleata\n");
	return (0);
}