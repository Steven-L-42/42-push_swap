/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:50:07 by slippert          #+#    #+#             */
/*   Updated: 2023/11/12 18:22:58 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

int	ft_is_onlydigit(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] != '+' && input[i][j] != '-')
				if (!ft_isdigit(input[i][j]))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = sign * (-2 * (*str == '-') + 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

int	ft_check_minmax(char **input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (ft_atol(input[i]) > INT_MAX || ft_atol(input[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_input(char ***argv)
{
	int	len;

	len = ft_arglen(*argv);
	if (len == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (ft_arglen(*argv) == 1)
			return (0);
	}
	else if (len >= 3)
		*argv += 1;
	if (!ft_is_onlydigit(*argv))
		return (ft_printf("Error: some arguments aren't integers\n"), 0);
	if (!ft_check_minmax(*argv))
		return (ft_printf
			("Error: some arguments are bigger or lower than an integer\n"), 0);
	return (1);
}
