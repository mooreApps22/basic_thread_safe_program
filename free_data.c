#include "includes.h"

void	free_data(t_data *t);

void	free_data(t_data *t)
{
	int	i = -1;
	
	while (++i < 5)
		pthread_join(t->guy[i].tid, NULL);
	pthread_mutex_destroy(&t->mtx_ct);
	pthread_mutex_destroy(&t->mtx_done);
	free(t->guy);
	free(t);
}
