/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:38:10 by scartage          #+#    #+#             */
/*   Updated: 2023/05/03 18:19:41 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "unistd.h"		//para el usleep()

/*La función ft_time() obtiene el tiempo actual en milisegundos
 * utilizando la estructura timeval de la librería <sys/time.h>.
 * Primero, declara una variable del tipo struct timeval y
 * otra variable de tipo long long int para almacenar el tiempo actual
 * en milisegundos. Luego, usa la función gettimeofday() para obtener 
 * la hora actual y guardarla en la estructura timeval.
 * Finalmente, multiplica los segundos por 1000 para convertirlos en
 * milisegundos, y suma los microsegundos divididos entre 1000 para agregar
 * la fracción de segundos adicional en milisegundos. 
 * El resultado se almacena en la variable de tiempo actual y se
 * devuelve como resultado de la función.*/
long long int	get_time(void)
{
	struct timeval	time;
	long long int	t_now;

	gettimeofday(&time, NULL);
	t_now = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (t_now);
}

void	ft_usleep(int nbr)
{
	long long int	new_time;

	new_time = get_time();
	while (get_time() - new_time < nbr)
		usleep(nbr / 2);
}

/*Para pasar de caracteres (ascii) a int
 * el atoi solo convierte a numeros hasta que encuentra otro
 * caracter (no numerico)*/
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_atoi(char *s)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		num = num * 10 + *s - '0';
		s++;
	}
	return (num * sign);
}
