/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 18:54:43 by fconde-p          #+#    #+#             */
/*   Updated: 2026/06/13 19:35:22 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	check_overflow(long acc, int digit, int sign)
{
	long	max_div;
	int		max_rem;

	max_div = 9223372036854775807L / 10;
	if (sign == 1)
		max_rem = 9223372036854775807L % 10;
	else
		max_rem = (9223372036854775807L % 10) + 1;
	if (acc > max_div || (acc == max_div && digit > max_rem))
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	acc;
	int		sign;

	acc = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (check_overflow(acc, *nptr - '0', sign))
			return (0);
		acc = acc * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0')
		return (0);
	return (acc * sign);
}
