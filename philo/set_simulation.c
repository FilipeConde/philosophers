/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:30:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 04:06:14 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	set_forks(t_sim *sim)
{
	long	i;

	i = 0;
	sim->forks = malloc(sim->philo_qty * sizeof(pthread_mutex_t));
	if (!sim->forks)
		return (EXIT_FAILURE);
	memset(sim->forks, 0, sim->philo_qty * sizeof(pthread_mutex_t));
	while (i < sim->philo_qty)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

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

int	preset_philos(t_sim *sim)
{
	sim->philos = malloc(sim->philo_qty * sizeof(t_philo));
	if (!sim->philos)
		return (EXIT_FAILURE);
	memset(sim->philos, 0, sim->philo_qty * sizeof(t_philo));
	sim->thread_id = malloc(sim->philo_qty * sizeof(pthread_t));
	if (!sim->thread_id)
		return (EXIT_FAILURE);
	memset(sim->thread_id, 0, sim->philo_qty * sizeof(pthread_t));
	return (EXIT_SUCCESS);
}

static void	set_values(t_sim *sim, char **av)
{
	sim->philo_qty = (int)ft_atol(av[1]);
	sim->time_to_die = ft_atol(av[2]);
	sim->time_to_eat = ft_atol(av[3]);
	sim->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		sim->max_meals = ft_atol(av[5]);
}

t_sim	*set_simulation(char **av)
{
	t_sim	*simulation;

	simulation = malloc(sizeof(t_sim));
	if (!simulation)
		return (NULL);
	memset(simulation, 0, sizeof(t_sim));
	set_values(simulation, av);
	if (set_lock_mutexes(simulation) == EXIT_FAILURE)
	{
		free(simulation);
		return (NULL);
	}
	simulation->start_time = get_current_time() + (5 * simulation->philo_qty);
	if (set_forks(simulation) == EXIT_FAILURE
		|| preset_philos(simulation) == EXIT_FAILURE
		|| set_philosophers(simulation) == EXIT_FAILURE)
	{
		free_simulation(&simulation);
		return (NULL);
	}
	return (simulation);
}
