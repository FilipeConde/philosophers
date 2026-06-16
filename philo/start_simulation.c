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
	if (created == sim->philo_qty)
		monitor(sim);
	else
		stop_simulation(sim);
	i = 0;
	while (i < created)
		pthread_join(sim->thread_id[i++], NULL);
	if (created < sim->philo_qty)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
