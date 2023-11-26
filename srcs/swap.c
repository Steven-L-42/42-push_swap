/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:27:33 by slippert          #+#    #+#             */
/*   Updated: 2023/11/12 18:19:35 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

// Swap the first 2 elements at the top.
void	swap(int *array, int size, char c)
{
	int	temp;

	if (size == 0 || size == 1)
		return ;
	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
}
