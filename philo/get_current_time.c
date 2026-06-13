/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 14:55:54 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/13 15:11:53 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	get_current_time()
{
	struct timeval	time;
	unsigned long	curr_time;

	// free(&time);
	curr_time = 0;
	if (gettimeofday(&time, NULL) == -1)
		write(2, "Error\n", 6);
	curr_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (curr_time);
}