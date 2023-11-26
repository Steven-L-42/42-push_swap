/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:44:44 by slippert          #+#    #+#             */
/*   Updated: 2023/11/12 11:28:52 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

static int	create_temp(int *arr, t_stacks *data, int size)
{
	int	i;

	data->temp_sorted = malloc(size * sizeof(int));
	if (!data->temp_sorted)
		return (0);
	i = 0;
	while (i < size)
	{
		data->temp_sorted[i] = arr[i];
		i++;
	}
	return (1);
}

int	get_median(t_stacks *data, int *arr, int *median, int size)
{
	int	i;
	int	j;
	int	temp;

	if (!create_temp(arr, data, size))
		return (0);
	i = 0;
	while (i < size && data->temp_sorted)
	{
		j = i + 1;
		while (j < size)
		{
			if (data->temp_sorted[i] > data->temp_sorted[j])
			{
				temp = data->temp_sorted[i];
				data->temp_sorted[i] = data->temp_sorted[j];
				data->temp_sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
	*median = data->temp_sorted[size / 2];
	free(data->temp_sorted);
	return (1);
}
