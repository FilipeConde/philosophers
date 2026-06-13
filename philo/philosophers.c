/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 13:24:50 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/13 18:49:06 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid number of arguments. Please, set quantity of \
1) philosophers, 2) time to die, 3) time to eat, 4) time to sleep and 5) \
amount of meals(optional).");
		return (1);
	}
	printf("RUN PROGRAM");
	return (0);
}
