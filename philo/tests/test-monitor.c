#include "tests.h"
#include "../philosophers.h"
#include <string.h>

static char	*run_and_capture(char **av)
{
	t_sim	*sim;
	int		saved;
	char	*out;

	sim = set_simulation(av);
	if (sim == NULL)
		return (NULL);
	saved = start_capture();
	start_simulation(sim);
	fflush(stdout);
	out = end_capture(saved);
	free_simulation(&sim);
	return (out);
}

int	should_report_death_when_starving(void)
{
	char	*av[] = {"name", "4", "60", "200", "200", NULL};
	char	*out;
	int		ok;

	out = run_and_capture(av);
	ok = (out && strstr(out, "died"));
	free(out);
	if (ok)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_stop_without_death_on_max_meals(void)
{
	char	*av[] = {"name", "5", "800", "100", "100", "2", NULL};
	char	*out;
	int		ok;

	out = run_and_capture(av);
	ok = (out && !strstr(out, "died") && strstr(out, "is eating"));
	free(out);
	if (ok)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_kill_single_philosopher(void)
{
	char	*av[] = {"name", "1", "200", "100", "100", NULL};
	char	*out;
	int		ok;

	out = run_and_capture(av);
	ok = (out && strstr(out, "died"));
	free(out);
	if (ok)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_handle_two_philosophers(void)
{
	char	*av[] = {"name", "2", "800", "200", "200", "5", NULL};
	char	*out;
	int		ok;

	out = run_and_capture(av);
	ok = (out && !strstr(out, "died") && strstr(out, "is eating"));
	free(out);
	if (ok)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_report_death_when_starving);
	RUN_TEST(should_stop_without_death_on_max_meals);
	RUN_TEST(should_kill_single_philosopher);
	RUN_TEST(should_handle_two_philosophers);
}
