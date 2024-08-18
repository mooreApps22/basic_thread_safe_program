#include "includes.h"

void	main_func(t_data *t);

void	main_func(t_data *t)
{
	while (true)
	{
		pthread_mutex_lock(&t->mtx_ct);
		if (t->ct > 100)
		{
			pthread_mutex_unlock(&t->mtx_ct);
			break ;
		}
		t->ct++;
		pthread_mutex_unlock(&t->mtx_ct);
		usleep(100);
	}
	pthread_mutex_lock(&t->mtx_done);
	t->job_done = true;
	pthread_mutex_unlock(&t->mtx_done);
	return ;
}
