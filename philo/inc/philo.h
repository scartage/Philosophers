/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:00:04 by scartage          #+#    #+#             */
/*   Updated: 2023/03/16 19:47:33 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>	//memset
# include <unistd.h>	//write
# include <stdio.h>		//printf
# include <stdlib.h>	//malloc, free
# include <stdbool.h>	//bool functions
# include <pthread.h>	//para usar process, hilos, mutex

typedef struct s_philo
{
	int id;
	int left_fork;
	int right_fork;

	t_data *data;
}		t_philo;

typedef struct s_data
{
	int number_philo;
	int time_die;
	int time_eat;
	int time_sleep;
	int times_must_eat;
	t_philo	*philo;

	pthread_mutex_t	*m_fork;
	pthread_mutex_t  m_print;
	pthread_mutex_t  m_death;
}		t_data;

//checkers
bool check_ac(int ac);
bool check_av(char **av);

//Utils
int ft_isnum(char n);
int ft_atoi(char *s);

//inits
int init(t_data *data, char **av);		//init general
int init_data(t_data *data, char **av); //init variables de parametros
#endif
