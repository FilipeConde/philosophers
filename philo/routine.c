/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 05:30:00 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 05:30:00 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	wait_until_start(t_philo *philo)
{
	while (get_current_time() < philo->start_time)
		usleep(100);
}

static void	take_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
	}
}

static void	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->philo_lock);
	philo->time_last_meal = get_current_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->philo_lock);
	ft_usleep(philo->time_to_eat, philo->stop_sim_lock, philo->stop_sim);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	sleep_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep, philo->stop_sim_lock, philo->stop_sim);
	print_status(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_until_start(philo);
	if (philo->l_fork == philo->r_fork)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork");
		while (!has_sim_stoped(philo->stop_sim, philo->stop_sim_lock))
			usleep(200);
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}
	while (!has_sim_stoped(philo->stop_sim, philo->stop_sim_lock))
	{
		take_forks(philo);
		eat(philo);
		sleep_think(philo);
	}
	return (NULL);
}
