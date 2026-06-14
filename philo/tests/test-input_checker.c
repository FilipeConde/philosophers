#include "tests.h"
#include "../philosophers.h"

int	should_fail_for_value_over_max_long(void)
{
	int		ac = 5;
	char	*av[] = {"./philo", "2345", "3", "24352",
		"9223372036854775808", NULL};

	if (input_checker(ac, av) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_fail_for_negative_value(void)
{
	int		ac = 5;
	char	*av[] = {"./philo", "5", "800", "-200", "200", NULL};

	if (input_checker(ac, av) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_fail_for_zero_value(void)
{
	int		ac = 5;
	char	*av[] = {"./philo", "5", "0", "200", "200", NULL};

	if (input_checker(ac, av) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_fail_for_non_numeric_value(void)
{
	int		ac = 5;
	char	*av[] = {"./philo", "5", "abc", "200", "200", NULL};

	if (input_checker(ac, av) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_pass_for_valid_values(void)
{
	int		ac = 5;
	char	*av[] = {"./philo", "5", "800", "200", "200", NULL};

	if (input_checker(ac, av) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_fail_for_less_than_4_args(void)
{
	int		ac = 4;
	char	*av[] = {"./philo", "5", "800", "200", NULL};

	if (input_checker(ac, av) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_fail_for_more_than_6_args(void)
{
	int		ac = 7;
	char	*av[] = {"./philo", "5", "0", "200", "200", "666", "999", NULL};

	if (input_checker(ac, av) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_pass_for_5_args(void)
{
	int		ac = 6;
	char	*av[] = {"./philo", "5", "800", "200", "200", "666", NULL};

	if (input_checker(ac, av) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_pass_for_4_args(void)
{
	int		ac = 5;
	char	*av[] = {"./philo", "5", "800", "200", "666", NULL};

	if (input_checker(ac, av) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_fail_for_value_over_max_long);
	RUN_TEST(should_fail_for_negative_value);
	RUN_TEST(should_fail_for_zero_value);
	RUN_TEST(should_fail_for_non_numeric_value);
	RUN_TEST(should_pass_for_valid_values);
	RUN_TEST(should_fail_for_less_than_4_args);
	RUN_TEST(should_fail_for_more_than_6_args);
	RUN_TEST(should_pass_for_5_args);
	RUN_TEST(should_pass_for_4_args);
}
