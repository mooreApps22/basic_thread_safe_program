#include "includes.h"

void	thread_start(t_data *t);

void	thread_start(t_data *t)
{
	int i = 0;
	while (i < 5)
	{
		pthread_create(&t->guy[i].tid, NULL, f1, (void *)&t->guy[i]);
		i++;
	}
}
