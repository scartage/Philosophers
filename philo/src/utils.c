#include "../inc/philo.h"


/*La función ft_time() obtiene el tiempo actual en milisegundos
 * utilizando la estructura timeval de la librería <sys/time.h>.
 * Primero, declara una variable del tipo struct timeval y
 * otra variable de tipo long long int para almacenar el tiempo actual
 * en milisegundos. Luego, usa la función gettimeofday() para obtener 
 * la hora actual y guardarla en la estructura timeval.
 * Finalmente, multiplica los segundos por 1000 para convertirlos en
 * milisegundos, y suma los microsegundos divididos entre 1000 para agregar
 * la fracción de segundos adicional en milisegundos. 
 * El resultado se almacena en la variable de tiempo actual y se devuelve como resultado de la función.*/
long long int get_time(void)
{
	struct timeval time;
	long long int actual_time;

	gettimeofday(&time, NULL);
	actual_time = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (actual_time);
}

/*Para comprobar que cada caracter que nos pasan
 * esten en el rango de digitos*/
int ft_isnum(char n)
{
	if ((n >= '0' && n <= '9') || n == '-')
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
