/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:28:52 by slippert          #+#    #+#             */
/*   Updated: 2023/11/13 10:56:01 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/sort.h"

// void	output_result(t_stacks *data)
// {
// 	ft_printf("\nSTACK_A: ");
// 	int i = 0;
// 	while (i < data->size_ab[0])
// 		ft_printf("%d ", data->stack_a[i++]);
// 	ft_printf("\n\nSTACK_B: ");
// 	i = 0;
// 	while (i < data->size_ab[1])
// 		ft_printf("%d ", data->stack_b[i++]);
// 	ft_printf("\nA_SIZE: %d |
// 	B_SIZE: %d\n", data->size_ab[0], data->size_ab[1]);
// 	if (is_sorted_asc(data->stack_a, data->size_ab[0]))
// 		ft_printf("\n\nSORTED");
// }

int	allocate(t_stacks *data, int size)
{
	data->size_ab[0] = size;
	data->size_ab[1] = 0;
	data->stack_a = malloc(size * sizeof(int));
	if (!data->stack_a)
		return (free(data), 0);
	data->stack_b = malloc(size * sizeof(int));
	if (!data->stack_b)
		return (free(data->stack_a), free(data), 0);
	return (1);
}

void	push_swap(char **input)
{
	t_stacks		*data;
	int				size;
	int				i;

	size = ft_arglen(input);
	data = (t_stacks *)malloc(sizeof(t_stacks));
	if (!allocate(data, size))
		return ;
	i = -1;
	while (++i < size)
		data->stack_a[i] = ft_atoi(input[i]);
	if (!is_doubled(data->stack_a, data->size_ab[0]))
	{
		if (!is_sorted_asc(data->stack_a, data->size_ab[0]))
			sort_to_b(data, data->size_ab[0]);
	}
	else
		ft_printf("Error: there are duplicates\n");
	free(data->stack_a);
	free(data->stack_b);
	free(data);
}
//	output_result(data);

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (!check_input(&argv))
			return (0);
		push_swap(argv);
	}
	return (0);
}
// system("leaks push_swap");
