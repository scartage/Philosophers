/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:14:51 by scartage          #+#    #+#             */
/*   Updated: 2023/05/22 18:22:21 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_print_msm(char *s, t_philo *philo)
{
	sem_wait(philo->print);
	printf("[%lld] [%d] %s\n", (get_time() - philo->time_start_p), philo->id, s);
	sem_post(philo->print);
}
