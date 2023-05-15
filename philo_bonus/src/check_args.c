/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:02:29 by scartage          #+#    #+#             */
/*   Updated: 2023/05/11 16:22:05 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static int is_num(char c)
{
	if (c >= 48 && c <= 59)
		return (0);
	return (-1);
}

static int only_num(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (is_num(s[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int check_av(char **av)
{
	int	i;

	i = 1;
	if (*av[1] == '0')
	{
		printf("Error: se necesitan philos\n");
		return (-1);
	}
	while (av[i])
	{
		if (only_num(av[i]) == -1)
		{
			printf("Error: los argumentos SOLO pueden ser numeros positivos\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int check_ac(int ac)
{
	if (ac != 4 && ac != 5)
	{
		printf("Error: cantidad de argmuentos invalida\n");
		return (-1);
	}
	return (0);
}
