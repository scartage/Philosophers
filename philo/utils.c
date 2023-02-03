#include "inc/philo.h"

/*Para comprobar que cada caracter que nos pasan
 * esten en el rango de digitos*/
int ft_isnum(char n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

/*Para crear pasar de carcteres ascii (string) a enteros (int)*/
int ft_atoi(char *s)
{
	int num;
	int sign;

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
