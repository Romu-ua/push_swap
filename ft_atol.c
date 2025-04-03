/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:01:48 by hyamamot          #+#    #+#             */
/*   Updated: 2025/02/22 13:01:48 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	check_sign(const char **nptr)
{
	int	is_negative;

	is_negative = 0;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			is_negative = 1;
		(*nptr)++;
	}
	return (is_negative);
}

long	ft_atol(const char *nptr)
{
	int			is_negative;
	long		result;

	while (ft_isspace(*nptr))
		nptr++;
	is_negative = check_sign(&nptr);
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
		if (is_negative && - result < LONG_MIN)
			return (LONG_MAX);
		else if (!is_negative && result > LONG_MAX)
			return (LONG_MAX);
	}
	if (is_negative)
		return (-result);
	else
		return (result);
}
