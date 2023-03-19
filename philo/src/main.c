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
	printf("que hora es? %lld\n", data->time_start);
	printf("parametros exitosamente guardados\n");
	return 0;
}
