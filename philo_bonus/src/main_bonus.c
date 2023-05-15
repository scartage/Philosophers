/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:15:28 by scartage          #+#    #+#             */
/*   Updated: 2023/05/13 18:15:56 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_data	data;
	t_philo	philo;

	if (check_ac(ac) == -1 || check_av(av) == -1)
		return (-1);
	if (init(&data, &philo, av) == -1)
		return (-1);
	create_process(&data, &philo);
	ft_clean(&data, &philo);
	return (0);
}
