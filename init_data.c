#include "includes.h"

void	init_data(t_data *t);
void	init_guys(t_data *t);

void	init_data(t_data *t)
{
	t->ct = 0;
	t->next = 0;
	t->job_done = false;
	pthread_mutex_init(&t->mtx_ct, NULL);
	pthread_mutex_init(&t->mtx_done, NULL);
	init_guys(t);
}

void	init_guys(t_data *t)
{
	int	i;	

	i = 0;
	t->guy = malloc(sizeof(t_guy) * 5);
	if (!t->guy)
		printf("Guy Malloc Error\n");
	while (i < 5)
	{
		t->guy[i].t = t;
		t->guy[i].id = i + 1;
		i++;
	}
}
