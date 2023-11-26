/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:28:17 by slippert          #+#    #+#             */
/*   Updated: 2023/11/25 10:52:16 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

void	sort_three(int	*arr, int size, char c)
{
	if (arr[0] > arr[1] && arr[0] < arr[2]
		&& arr[1] < arr[2])
		swap(arr, size, c);
	if (arr[0] > arr[1] && arr[0] > arr[2]
		&& arr[1] > arr[2])
	{
		swap(arr, size, c);
		re_rotate(arr, size, c);
	}
	if (arr[0] > arr[1] && arr[0] > arr[2]
		&& arr[1] < arr[2])
		rotate(arr, size, c);
	if (arr[0] < arr[1] && arr[0] < arr[2]
		&& arr[1] > arr[2])
	{
		swap(arr, size, c);
		rotate(arr, size, c);
	}
	if (arr[0] < arr[1] && arr[0] > arr[2]
		&& arr[1] > arr[2])
		re_rotate(arr, size, c);
}

void	sort_three_a(t_stacks *data, int len)
{
	if (len == 3 && data->size_ab[0] == 3)
		sort_three(data->stack_a, data->size_ab[0], 'a');
	else if (len == 2)
	{
		if (data->stack_a[0] > data->stack_a[1])
			swap(data->stack_a, data->size_ab[0], 'a');
	}
	else if (len == 3)
	{
		while (len != 3 || !(data->stack_a[0] < data->stack_a[1]
				&& data->stack_a[1] < data->stack_a[2]))
		{
			if (len == 3 && data->stack_a[0] > data->stack_a[1]
				&& data->stack_a[2])
				swap(data->stack_a, data->size_ab[0], 'a');
			else if (len == 3 && !(data->stack_a[2] > data->stack_a[0]
					&& data->stack_a[2] > data->stack_a[1]))
				len = push_selector(data, len, 0);
			else if (data->stack_a[0] > data->stack_a[1])
				swap(data->stack_a, data->size_ab[0], 'a');
			else if (len++)
				push_a(data);
		}
	}
}

void	sort_three_b(t_stacks *data, int len)
{
	if (len == 1)
		push_a(data);
	else if (len == 2)
	{
		if (data->stack_b[0] < data->stack_b[1])
			swap(data->stack_b, data->size_ab[1], 'b');
		while (len--)
			push_a(data);
	}
	else if (len == 3)
	{
		while (len || !(data->stack_a[0] < data->stack_a[1]
				&& data->stack_a[1] < data->stack_a[2]))
		{
			if (len == 1 && data->stack_a[0] > data->stack_a[1])
				swap(data->stack_a, data->size_ab[0], 'a');
			else if (len == 1 || (len >= 2
					&& data->stack_b[0] > data->stack_b[1])
				|| (len == 3 && data->stack_b[0] > data->stack_b[2]))
				len = push_selector(data, len, 1);
			else
				swap(data->stack_b, data->size_ab[1], 'b');
		}
	}
}
