/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_sim_stoped.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 04:23:12 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 04:29:41 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	has_sim_stoped(int *stop_sim, pthread_mutex_t *stop_sim_lock)
{
	int	curr_stop_sim;

	curr_stop_sim = 0;
	pthread_mutex_lock(stop_sim_lock);
	curr_stop_sim = *stop_sim;
	pthread_mutex_unlock(stop_sim_lock);
	return (curr_stop_sim);
}
