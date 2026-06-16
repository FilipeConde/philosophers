/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 04:46:08 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 04:51:48 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long duration, pthread_mutex_t *stop_sim_lock, int *stop_sim)
{
	long	start;
	long	end;

	start = 0;
	end = 0;
	start = get_current_time();
	end = start;
	while (end - start < duration)
	{
		usleep(200);
		end = get_current_time();
		if (has_sim_stoped(stop_sim, stop_sim_lock))
			break ;
	}
}
