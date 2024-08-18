#include "includes.h"

void *f1(void *v);

void *f1(void *v)
{
	t_guy	*g;
	t_data	*t;
	int		i;

	g = (t_guy *)v;
	t = g->t;
	i = 0;
	while (true)
	{
		pthread_mutex_lock(&t->mtx_done);
		if (t->job_done == true)
		{
			pthread_mutex_unlock(&t->mtx_done);
			break ;
		}
		pthread_mutex_unlock(&t->mtx_done);
		pthread_mutex_lock(&t->mtx_ct);
		if (t->ct % 5 == 0 && t->ct == t->next && t->next < 110)
		{
			t->next = t->ct + 5;
			printf("%d is printing %d\n", g->id, t->ct);
		}
		pthread_mutex_unlock(&t->mtx_ct);
		usleep(100);
	}
	return (NULL);
}
