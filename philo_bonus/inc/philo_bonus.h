/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:28:18 by scartage          #+#    #+#             */
/*   Updated: 2023/05/15 17:21:16 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
    int     number_philos;
    int     time_eat;
    int     time_sleep;
    int     time_die;
    int     must_eat;

    sem_t   *fork;
    sem_t   *print;
    sem_t   *eat;

    int     id;
    long long int     last_eat;
    long long int     time_start_p;
}	t_philo;

typedef struct s_data
{
	int		        number_philos;
	int		        time_to_die;
	int		        time_to_eat;
	int		        time_to_sleep;
	int		        must_eat;
	long long int	time_start;
	pid_t	*pid;
}	t_data;

//utils
int ft_atoi(char *s);
void ft_usleep(int nbr);
long long int get_time(void);


//Check args
int	check_ac(int ac);
int check_av(char **av);

//init data
int init(t_data *data, t_philo *philo, char **av);

//creating process
int create_process(t_data *data, t_philo *philo);

//routine
int ft_pre_routine(t_philo *philo, int counter);

//prints (en este caso es una funcion general para los mensajes)
void ft_print_msm(char *s, t_philo *philo);

//Clean
void ft_clean(t_data *data, t_philo *philo);
#endif
