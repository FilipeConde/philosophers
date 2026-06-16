/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 03:44:08 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 03:53:11 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	set_philosophers(t_sim *sim)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < sim->philo_qty)
	{
		philo = &sim->philos[i];
		philo->index = i + 1;
		philo->start_time = sim->start_time;
		philo->l_fork = &sim->forks[i];
		philo->r_fork = &sim->forks[(i + 1) % sim->philo_qty];
		philo->time_last_meal = sim->start_time;
		philo->meal_count = 0;
		philo->time_to_eat = sim->time_to_eat;
		philo->time_to_sleep = sim->time_to_sleep;
		philo->print_lock = &sim->print_lock;
		philo->stop_sim_lock = &sim->stop_sim_lock;
		philo->stop_sim = &sim->stop_sim_flag;
		if (pthread_mutex_init(&philo->philo_lock, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
