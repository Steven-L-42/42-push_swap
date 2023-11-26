/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:28:52 by slippert          #+#    #+#             */
/*   Updated: 2023/11/12 18:19:20 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

// The first element becomes the last one.
void	rotate(int *array, int size, char c)
{
	int	i;
	int	temp;

	if (size == 0 || size == 1)
		return ;
	i = 0;
	temp = array[i];
	i++;
	while (i < size)
	{
		array[i - 1] = array[i];
		i++;
	}
	array[i - 1] = temp;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

// The last element becomes the first one.
void	re_rotate(int *array, int size, char c)
{
	int	i;
	int	temp;

	if (size == 0 || size == 1)
		return ;
	i = size - 1;
	temp = array[i];
	while (i)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[i] = temp;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}
