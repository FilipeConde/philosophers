/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 04:34:23 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 04:42:42 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *str)
{
	long	curr_time;

	curr_time = 0;
	pthread_mutex_lock(philo->print_lock);
	curr_time = get_current_time();
	if (has_sim_stoped == 0)
		printf("%lu %d %s\n", curr_time - philo->start_time, philo->index, str);
	pthread_mutex_unlock(philo->print_lock);
}
