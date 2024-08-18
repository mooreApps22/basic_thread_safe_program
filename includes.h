#ifndef INCLUDES_H
# define INCLUDES_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef struct s_guy	t_guy;

typedef struct s_data
{
	int					ct;
	int					next;
	bool				job_done;
	pthread_mutex_t		mtx_done;
	pthread_mutex_t		mtx_ct;
	t_guy				*guy;
}	t_data;

typedef struct s_guy
{
	pthread_t			tid;
	int					id;
	t_data				*t;
}	t_guy;

//main
int	main(void);
//args
//init data
void	init_data(t_data *t);
//threads start
void	thread_start(t_data *t);
//f1
void	*f1(void *v);
//main func
void	main_func(t_data *t);
//free data
void	free_data(t_data *t);

#endif
