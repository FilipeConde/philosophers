/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:32:44 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/15 20:32:30 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo
{
	int				index;
	unsigned long	start_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	unsigned long	time_last_meal;
	long			meal_count;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_mutex_t	philo_lock;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*stop_sim_lock;
	int				*stop_sim;
}	t_philo;

typedef struct s_sim
{
	int				philo_qty;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			max_meals;
	unsigned long	start_time;
	// int				stop_sim_flag;
	// pthread_mutex_t	print_lock;
	// pthread_mutex_t	stop_sim_lock;
	// pthread_mutex_t	*forks;
	// pthread_t		*thread_id;
	// t_philo			*philos;
}	t_sim;

int				sample(void);
unsigned long	get_current_time(void);
long			ft_atol(const char *nptr);
int				input_checker(int ac, char **av);
t_sim			*set_simulation(char **av);

#endif