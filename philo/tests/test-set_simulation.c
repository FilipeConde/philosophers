#include "tests.h"
#include "../philosophers.h"

int	should_set_simulation_with_4_values(void)
{
	char	*av[] = {"name", "30", "200", "300", "400"};
	t_sim	*sim;

	sim = malloc(sizeof(t_sim));
	sim = set_simulation(av);
	if (sim->philo_qty == 30
		&& sim->time_to_die == (long)200
		&& sim->time_to_eat == (long)300
		&& sim->time_to_sleep == (long)400
		&& sim->max_meals == 0
		&& sim->stop_sim_flag == 0)
	{
		free(sim);
		return (EXIT_SUCCESS);
	}
	printf("Expected: %d\nReceived: %d\n", 30, sim->philo_qty);
	printf("Expected: %lu\nReceived: %lu\n", (long)200, sim->time_to_die);
	printf("Expected: %lu\nReceived: %lu\n", (long)300, sim->time_to_eat);
	printf("Expected: %lu\nReceived: %lu\n", (long)400, sim->time_to_sleep);
	printf("Expected: %d\nReceived: %lu\n", 0, sim->max_meals);
	printf("Expected: %d\nReceived: %d\n", 0, sim->stop_sim_flag);
	free(sim);
	return (EXIT_FAILURE);
}

int	should_set_simulation_with_5_values(void)
{
	char	*av[] = {"name", "30", "200", "300", "400", "600"};
	t_sim	*sim;

	sim = malloc(sizeof(t_sim));
	sim = set_simulation(av);
	if (sim->philo_qty == 30
		&& sim->time_to_die == (long)200
		&& sim->time_to_eat == (long)300
		&& sim->time_to_sleep == (long)400
		&& sim->max_meals == 600
		&& sim->stop_sim_flag == 0)
	{
		free(sim);
		return (EXIT_SUCCESS);
	}
	printf("Expected: %d\nReceived: %d\n", 30, sim->philo_qty);
	printf("Expected: %lu\nReceived: %lu\n", (long)200, sim->time_to_die);
	printf("Expected: %lu\nReceived: %lu\n", (long)300, sim->time_to_eat);
	printf("Expected: %lu\nReceived: %lu\n", (long)400, sim->time_to_sleep);
	printf("Expected: %lu\nReceived: %lu\n", (long)600, sim->max_meals);
	printf("Expected: %d\nReceived: %d\n", 0, sim->stop_sim_flag);
	free(sim);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_set_simulation_with_4_values);
	RUN_TEST(should_set_simulation_with_5_values);
}