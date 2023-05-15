/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:57:15 by scartage          #+#    #+#             */
/*   Updated: 2023/05/03 18:39:35 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>		//printf
# include <stdlib.h>		//malloc, free
# include <pthread.h>	//para hilos y mutex
# include <sys/time.h>
# include <stdbool.h>
# include "colors.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;

	int				has_eaten;
	long long int	last_eat;
	t_data			*data;
}	t_philo;

/*La variable death puede ser de type bool,
 * pero en este caso es un int donde 0 == viva y 1 == muerto*/
typedef struct s_data
{
	int				number_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				death;
	long long int	start_time;
	long long int	start_routine;
	t_philo			*philos;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_death;
}	t_data;

//utils
int				ft_atoi(char *s);
int				ft_strlen(char *s);
long long int	get_time(void);
void			ft_usleep(int nbr);

//revisamos parametros
int				check_av(char **av);
int				check_ac(int ac);

//Inicializamos variables de data e iniciamos philos
int				init(t_data *data, char **av);
int				init_data(t_data *data, char **av);
int				init_philos(t_data *data);

//Creamos los hilos y cada uno empieza la rutina
int				create_pthread(t_data *data);
bool			ft_one_philo(t_philo *philo);
void			*ft_rutine(void *arg);

//Rutina
int				ft_eat(t_philo *philo);
int				ft_sleep(t_philo *philo);
int				ft_think(t_philo *philo);

//Prints de rutina
void			ft_print_fork(t_philo *philo);
void			ft_print_eat(t_philo *philo);
void			ft_print_sleep(t_philo *philo);
void			ft_print_think(t_philo *philo);
void			ft_print_dead(t_philo *philo);

//Checker de muerte && que hayan comido
int				check_finish(t_data *data);

//para liberar memoria
void			ft_clean(t_data *data);
#endif
