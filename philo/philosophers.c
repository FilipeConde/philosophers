/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 13:24:50 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/16 02:45:25 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_sim	*simulation;

	if (input_checker(ac, av) == EXIT_FAILURE)
		return (1);
	printf("RUN PROGRAM");
	simulation = set_simulation(av);
	if (simulation == NULL)
		return (1);
	if (simulation)
		free_simulation(&simulation);
	return (0);
}
