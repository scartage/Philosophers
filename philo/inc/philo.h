/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:00:04 by scartage          #+#    #+#             */
/*   Updated: 2023/02/03 13:52:52 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>	//memset
# include <unistd.h>	//write
# include <stdio.h>		//printf
# include <stdlib.h>	//malloc, free
# include <stdbool.h>	//bool functions


typedef struct s_data
{
	int number_philo;
	int time_die;
	int time_eat;
	int time_sleep;
	int times_must_eat;
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
