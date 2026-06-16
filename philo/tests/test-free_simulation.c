#include "tests.h"
#include "../philosophers.h"

int	should_free_simulation(void)
{
	char	*av[] = {"name", "30", "200", "300", "400", NULL};
	t_sim	*sim;

	sim = set_simulation(av);
	free_simulation(&sim);
	if (sim == NULL)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_free_simulation);
}