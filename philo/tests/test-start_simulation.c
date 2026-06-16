#include "tests.h"
#include "../philosophers.h"
#include <string.h>

int	should_create_and_join_all_threads(void)
{
	char	*av[] = {"name", "5", "800", "200", "200", NULL};
	t_sim	*sim;
	int		result;

	sim = set_simulation(av);
	if (sim == NULL)
		return (EXIT_FAILURE);
	result = start_simulation(sim);
	free_simulation(&sim);
	if (result == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_run_eat_sleep_think_cycle(void)
{
	char	*av[] = {"name", "5", "800", "200", "200", NULL};
	t_sim	*sim;
	int		saved;
	char	*out;
	int		ok;

	sim = set_simulation(av);
	if (sim == NULL)
		return (EXIT_FAILURE);
	saved = start_capture();
	start_simulation(sim);
	fflush(stdout);
	out = end_capture(saved);
	free_simulation(&sim);
	ok = (out && strstr(out, "is eating") && strstr(out, "is sleeping")
			&& strstr(out, "is thinking") && strstr(out, "has taken a fork"));
	free(out);
	if (ok)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_handle_single_thread(void)
{
	char	*av[] = {"name", "1", "800", "200", "200", NULL};
	t_sim	*sim;
	int		result;

	sim = set_simulation(av);
	if (sim == NULL)
		return (EXIT_FAILURE);
	result = start_simulation(sim);
	free_simulation(&sim);
	if (result == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_create_and_join_all_threads);
	RUN_TEST(should_run_eat_sleep_think_cycle);
	RUN_TEST(should_handle_single_thread);
}
