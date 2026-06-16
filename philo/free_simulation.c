/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 02:07:31 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 02:34:21 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_simulation(t_sim **sim)
{
	int	i;

	if (sim == NULL || *sim == NULL)
		return ;
	pthread_mutex_destroy(&(*sim)->print_lock);
	pthread_mutex_destroy(&(*sim)->stop_sim_lock);
	if ((*sim)->forks != NULL)
	{
		i = 0;
		while (i < (*sim)->philo_qty)
			pthread_mutex_destroy(&(*sim)->forks[i++]);
		free((*sim)->forks);
	}
	if ((*sim)->thread_id != NULL)
		free((*sim)->thread_id);
	if ((*sim)->philos != NULL)
		free((*sim)->philos);
	free(*sim);
	*sim = NULL;
}
