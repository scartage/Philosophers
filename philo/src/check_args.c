#include "../inc/philo.h"

/*Revisamos que la cantidad de argumentos sea la correcta
 * sin parametro adicional son 5, con parametro adicional son 6*/
bool check_ac(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: cantidad de argumentos invalida\n");
		return (false);
	}
	return (true);
}

/*Revisamos que el contenido de cada argumento, que son chars
 * sean solo valores numericos (del 0 al 9) validos
 *
 * Tambien se revisa que exista filosofos*/
bool check_av(char **av)
{
	int counter;
	int i;
	
	counter = 1;
	if (*av[1] == '0')
	{
		printf("Error: se necestian filosofos\n");
		return (false);
	}
	while (av[counter])
	{
		i = 0;
		while (av[counter][i] != '\0')
		{
			if (ft_isnum(av[counter][i]) == 0)
			{
				printf("Error: los parametros solo pueden ser numeros\n");
				return (false);
			}
			i++;
		}
		counter++;
	}
	return (true);
}
