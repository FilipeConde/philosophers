/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:30:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/15 22:09:06 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	set_lock_mutexes(t_sim *sim)
{
	memset(&sim->print_lock, 0, sizeof(pthread_mutex_t));
	memset(&sim->stop_sim_lock, 0, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(&sim->print_lock, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&sim->stop_sim_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&sim->print_lock);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_sim	*set_simulation(char **av)
{
	t_sim	*simulation;

	simulation = malloc(sizeof(t_sim));
	if (!simulation)
		return (NULL);
	simulation->philo_qty = (int)atol(av[1]);
	simulation->time_to_die = atol(av[2]);
	simulation->time_to_eat = atol(av[3]);
	simulation->time_to_sleep = atol(av[4]);
	if (av[5])
		simulation->max_meals = atol(av[5]);
	else
		simulation->max_meals = atol("0");
	simulation->stop_sim_flag = 0;
	if (set_lock_mutexes(simulation) == EXIT_FAILURE)
		return (NULL);
	return (simulation);
}
