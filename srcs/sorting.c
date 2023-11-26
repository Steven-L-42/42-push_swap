/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:29:48 by slippert          #+#    #+#             */
/*   Updated: 2023/11/25 10:54:11 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

int	sort_to_b(t_stacks *data, int len)
{
	int		median;
	int		size;
	int		rotated;

	rotated = 0;
	size = len;
	if (is_sorted_asc(data->stack_a, len))
		return (1);
	if (len <= 3)
		return (sort_three_a(data, len), 1);
	if (!get_median(data, data->stack_a, &median, len))
		return (0);
	while (len != size / 2 + size % 2)
	{
		if (data->stack_a[0] < median && (len--))
			push_b(data);
		else if (++rotated)
			rotate(data->stack_a, data->size_ab[0], 'a');
	}
	while (size / 2 + size % 2 != data->size_ab[0] && rotated--)
		re_rotate(data->stack_a, data->size_ab[0], 'a');
	return (sort_to_b(data, size / 2 + size % 2) && sort_to_a(data, size / 2));
	return (1);
}

int	sort_to_a(t_stacks *data, int len)
{
	int		median;
	int		size;
	int		rotated;

	rotated = 0;
	if (is_sorted_desc(data->stack_b, len))
		while (len--)
			push_a(data);
	if (len <= 3)
		return (sort_three_b(data, len), 1);
	size = len;
	if (!get_median(data, data->stack_b, &median, len))
		return (0);
	while (len != size / 2)
	{
		if (data->stack_b[0] >= median && (len--))
			push_a(data);
		else if (++rotated)
			rotate(data->stack_b, data->size_ab[1], 'b');
	}
	while (size / 2 != data->size_ab[1] && rotated--)
		re_rotate(data->stack_b, data->size_ab[1], 'b');
	return (sort_to_b(data, size / 2 + size % 2) && sort_to_a(data, size / 2));
}
