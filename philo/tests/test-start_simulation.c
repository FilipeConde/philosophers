#include "tests.h"
#include "../philosophers.h"

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
	RUN_TEST(should_handle_single_thread);
}
