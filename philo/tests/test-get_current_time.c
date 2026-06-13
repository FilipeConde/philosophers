#include "tests.h"
#include "../philosophers.h"

int	should_return_2_sec(void)
{
	unsigned long start;
	unsigned long end;
	unsigned long res;

	start = get_current_time();
	usleep(2000);
	end = get_current_time();
	res = end - start;
	if (res == (unsigned long)2)
		return (EXIT_SUCCESS);
	printf("Expected: %lu\nReceived: %lu\n", (unsigned long)2, res);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_return_2_sec);
}