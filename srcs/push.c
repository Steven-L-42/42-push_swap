/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:26:17 by slippert          #+#    #+#             */
/*   Updated: 2023/11/12 18:28:00 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

// Push first element from origin to top of destination.
// Do nothing if origin is empty.
void	push_b(t_stacks *data)
{
	int	i;

	if (data->size_ab[0])
	{
		data->size_ab[1]++;
		i = data->size_ab[1];
		while (--i > 0)
			data->stack_b[i] = data->stack_b[i - 1];
		data->stack_b[0] = data->stack_a[0];
		i = -1;
		data->size_ab[0]--;
		while (++i < data->size_ab[0])
			data->stack_a[i] = data->stack_a[i + 1];
		ft_printf("pb\n");
	}
	else
		return ;
}

void	push_a(t_stacks *data)
{
	int	i;

	if (data->size_ab[1])
	{
		data->size_ab[0]++;
		i = data->size_ab[0];
		while (--i > 0)
			data->stack_a[i] = data->stack_a[i - 1];
		data->stack_a[0] = data->stack_b[0];
		i = -1;
		data->size_ab[1]--;
		while (++i < data->size_ab[1])
			data->stack_b[i] = data->stack_b[i + 1];
		ft_printf("pa\n");
	}
	else
		return ;
}

int	push_selector(t_stacks *collec, int len, int push)
{
	if (push == 0)
		push_b(collec);
	else
		push_a(collec);
	len--;
	return (len);
}
