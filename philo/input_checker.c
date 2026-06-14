/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:16:02 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/13 20:53:00 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	input_checker(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid number of arguments. Please, set quantity of \
1) philosophers, 2) time to die, 3) time to eat, 4) time to sleep and 5) \
amount of meals(optional).\n");
		return (EXIT_FAILURE);
	}
	while (i < ac)
	{
		if (ft_atol(av[i]) <= 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
