/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:55:18 by scartage          #+#    #+#             */
/*   Updated: 2023/05/12 17:43:04 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	is_num(char c)
{
	if (c >= 48 && c <= 59)
		return (0);
	return (-1);
}

static int	only_num(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (is_num(s[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

/*Con estas dos funciones comprobamos que los parametros
 * que nos pasan sean los correctos.
 *
 * Solo pueden ser numeros positivos, aunque con esta funcion
 * lo unico que se revisa es que sean solo numeros.*/
int	check_av(char **av)
{
	int	i;

	i = 1;
	if (*av[1] == '0')
	{
		printf("Error: se necesitan filosofos\n");
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

int	check_ac(int ac)
{
	if (ac != 4 && ac != 5)
	{
		printf("Error: cantidad de argumentos invalida\n");
		return (-1);
	}
	return (0);
}
