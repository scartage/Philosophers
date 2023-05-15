/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:29:54 by scartage          #+#    #+#             */
/*   Updated: 2023/05/15 16:04:30 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void delete_sem(t_philo *philo)
{
    sem_close(philo->fork);
    sem_close(philo->eat);
    sem_close(philo->print);
}

int kill_process(t_data *data)
{
    int counter;

    counter = 0;
    while (counter < data->number_philos)
    {
        if (data->pid[counter])
            kill(data->pid[counter], SIGKILL);
        counter++;
    }
    return (1);
}


void ft_clean(t_data *data, t_philo *philo)
{

    kill_process(data);
    delete_sem(philo);
    free(data->pid);
    free(data);
    free(philo);
    return ;
}
