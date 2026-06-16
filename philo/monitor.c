/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 06:30:00 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 06:30:00 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	stop_simulation(t_sim *sim)
{
	pthread_mutex_lock(&sim->stop_sim_lock);
	sim->stop_sim_flag = 1;
	pthread_mutex_unlock(&sim->stop_sim_lock);
}

static int	philo_is_dead(t_philo *philo, long time_to_die)
{
	unsigned long	last_meal;

	pthread_mutex_lock(&philo->philo_lock);
	last_meal = philo->time_last_meal;
	pthread_mutex_unlock(&philo->philo_lock);
	return (get_current_time() - last_meal > (unsigned long)time_to_die);
}

static int	all_ate_enough(t_sim *sim)
{
	int		i;
	long	count;

	if (sim->max_meals <= 0)
		return (0);
	i = 0;
	while (i < sim->philo_qty)
	{
		pthread_mutex_lock(&sim->philos[i].philo_lock);
		count = sim->philos[i].meal_count;
		pthread_mutex_unlock(&sim->philos[i].philo_lock);
		if (count < sim->max_meals)
			return (0);
		i++;
	}
	return (1);
}

static void	announce_death(t_sim *sim, t_philo *philo)
{
	stop_simulation(sim);
	pthread_mutex_lock(&sim->print_lock);
	printf("%lu %d died\n", get_current_time() - philo->start_time,
		philo->index);
	pthread_mutex_unlock(&sim->print_lock);
}

void	monitor(t_sim *sim)
{
	int	i;

	while (get_current_time() < sim->start_time)
		usleep(100);
	while (1)
	{
		i = 0;
		while (i < sim->philo_qty)
		{
			if (philo_is_dead(&sim->philos[i], sim->time_to_die))
				return (announce_death(sim, &sim->philos[i]));
			i++;
		}
		if (all_ate_enough(sim))
			return (stop_simulation(sim));
		usleep(200);
	}
}
