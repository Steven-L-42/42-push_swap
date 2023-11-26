/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:45:29 by slippert          #+#    #+#             */
/*   Updated: 2023/11/12 11:51:34 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

static void	find_min(t_stacks *data)
{
	int	i;

	i = 0;
	data->median = INT_MAX;
	while (i < data->size_ab[0])
	{
		if (data->median > data->stack_a[i])
			data->median = data->stack_a[i];
		i++;
	}
}

static void	min_on_top(t_stacks *data)
{
	find_min(data);
	if (data->stack_a[0] < data->median)
		while (data->stack_a[0] != data->median)
			rotate(data->stack_a, data->size_ab[0], 'a');
	else if (data->stack_a[0] > data->median)
		while (data->stack_a[0] != data->median)
			re_rotate(data->stack_a, data->size_ab[0], 'a');
}

void	sort_five(t_stacks *data, int len)
{
	if (len == 5)
	{
		min_on_top(data);
		push_b(data);
	}
	min_on_top(data);
	push_b(data);
	sort_three(data->stack_a, 3, 'a');
	push_a(data);
	push_a(data);
}
