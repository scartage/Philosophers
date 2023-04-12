/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:00:04 by scartage          #+#    #+#             */
/*   Updated: 2023/04/12 16:50:36 by scartage         ###   ########.fr       */
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
# include <sys/time.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int id;
	int left_fork;
	int right_fork;
	int t_eat;
	long long int	last_eat;

	t_data *data;
}		t_philo;

typedef struct s_data
{
	int number_philo;
	long long int time_die;
	long long int time_eat;
	long long int time_sleep;
	int times_must_eat;
	int death;

	long long int time_start;
	t_philo	*philo;

	pthread_mutex_t	*m_fork;
	pthread_mutex_t  m_print;
	pthread_mutex_t  m_death;
}		t_data;

//checkers
bool check_ac(int ac);
bool check_av(char **av);

//Utils
int				ft_isnum(char n);
int				ft_atoi(char *s);
long long int	get_time(void);
void			ft_usleep(int nbr);

//inits
int init(t_data *data, char **av);		//init general
int init_data(t_data *data, char **av);
int init_mutex(t_data *data);
int init_philos(t_data *data);

//crear hilos
int create_pthread(t_data *data);

//rutinas
int ft_eat(t_philo *philo);
int ft_sleep(t_philo *philo);
int ft_think(t_philo *philo);

//printers info philo
void ft_print_fork(t_philo *philo);
void ft_print_eat(t_philo *philo);
void ft_print_sleep(t_philo *philo);
void ft_print_think(t_philo *philo);
void ft_print_death(t_philo *philo);

//bucle que comprueba que haya muerto o hayan comido x veces
void ft_check_finish(t_data *data);
int ft_die(t_data *data);
#endif
