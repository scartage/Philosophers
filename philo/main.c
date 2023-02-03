#include "inc/philo.h"

int main(int ac, char **av)
{
	t_data *data;

	if (!check_ac(ac) || !check_av(av))
		return (-1);
	data = (t_data *)malloc(sizeof(data));
	if (data == NULL)
		return (-1);
	if (init(data, av) == -1)
		return (-1);
	printf("parametros exitosamente guardados\n");
	return 0;
}
