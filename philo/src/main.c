/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:33:30 by scartage          #+#    #+#             */
/*   Updated: 2023/04/02 19:38:18 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int main(int ac, char **av)
{
	t_data *data;

	if (!check_ac(ac) || !check_av(av))
		return (-1);
	data = (t_data*)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	if (init(data, av) == -1)
		return (-1);
	data->time_start = get_time();
	
	if (create_pthread(data) != 0)
		return (-1);
	printf("parametros exitosamente guardados\n");
	return 0;
}
