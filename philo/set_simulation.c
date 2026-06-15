/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:30:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/15 20:04:34 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	return (simulation);
}
