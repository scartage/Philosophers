/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:16:21 by scartage          #+#    #+#             */
/*   Updated: 2023/05/03 18:17:38 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if ((check_ac(ac - 1) == -1) || (check_av(av) == -1))
		return (-1);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	if (init(data, av) == -1)
		return (-1);
	data->start_time = get_time();
	data->start_routine = data->start_time + (data->number_philos * 20);
	create_pthread(data);
	ft_clean(data);
	return (0);
}
