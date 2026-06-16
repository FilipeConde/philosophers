/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 05:00:00 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 05:00:00 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* TEMP (Fase 2): sem monitor ainda, paramos a simulação após tempo fixo.
   Será substituído pelo monitor real na Fase 3. */
static void	temporary_timed_stop(t_sim *sim)
{
	ft_usleep(800, &sim->stop_sim_lock, &sim->stop_sim_flag);
	pthread_mutex_lock(&sim->stop_sim_lock);
	sim->stop_sim_flag = 1;
	pthread_mutex_unlock(&sim->stop_sim_lock);
}

int	start_simulation(t_sim *sim)
{
	int	i;
	int	created;

	created = 0;
	while (created < sim->philo_qty)
	{
		if (pthread_create(&sim->thread_id[created], NULL, philo_routine,
				&sim->philos[created]) != 0)
			break ;
		created++;
	}
	temporary_timed_stop(sim);
	i = 0;
	while (i < created)
		pthread_join(sim->thread_id[i++], NULL);
	if (created < sim->philo_qty)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
