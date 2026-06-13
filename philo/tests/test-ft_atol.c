#include "tests.h"
#include "../philosophers.h"
#include <limits.h>

int	should_return_long_max_from_string(void)
{
	char	str[]= "9223372036854775807";
	long		long_max = 9223372036854775807;

	if (ft_atol(str) == long_max)
		return (EXIT_SUCCESS);
	printf("Expected: %lu\nReceived: %lu\n", long_max, ft_atol(str));
	return (EXIT_FAILURE);
}

int	should_return_long_min_from_string(void)
{
	char	str[] = "-9223372036854775808";
	long	long_min = LONG_MIN;

	if (ft_atol(str) == long_min)
		return (EXIT_SUCCESS);
	printf("Expected: %ld\nReceived: %ld\n", long_min, ft_atol(str));
	return (EXIT_FAILURE);
}

int	should_return_zero_for_min_minus_one(void)
{
	char	str[] = "-9223372036854775809";

	if (ft_atol(str) == 0)
		return (EXIT_SUCCESS);
	printf("Expected: %ld\nReceived: %ld\n", 0L, ft_atol(str));
	return (EXIT_FAILURE);
}

int	should_return_zero_for_max_plus_one(void)
{
	char	str[] = "9223372036854775808";

	if (ft_atol(str) == 0)
		return (EXIT_SUCCESS);
	printf("Expected: %ld\nReceived: %ld\n", 0L, ft_atol(str));
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_return_long_max_from_string);
	RUN_TEST(should_return_long_min_from_string);
	RUN_TEST(should_return_zero_for_min_minus_one);
	RUN_TEST(should_return_zero_for_max_plus_one);
}