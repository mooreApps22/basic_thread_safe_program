#include "includes.h"

int	main(void)
{
	t_data *t;

	t = malloc(sizeof(t_data));
	// no args
	init_data(t);
	thread_start(t);
	main_func(t);
	free_data(t);
	return (EXIT_SUCCESS);
}
