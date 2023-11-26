/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:05:08 by slippert          #+#    #+#             */
/*   Updated: 2023/11/25 10:47:13 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../libft/srcs/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stacks
{
	int		*stack_a;
	int		*stack_b;
	int		*temp_sorted;
	int		median;
	int		size_ab[2];
}	t_stacks;

// is checks
int		is_sorted_asc(int	*arr, int size);
int		is_sorted_desc(int *arr, int size);
int		is_doubled(int	*arr, int size);

// helper
int		check_input(char ***argv);
int		ft_arglen(char **input);

// push
void	push_a(t_stacks *data);
void	push_b(t_stacks *data);
int		push_selector(t_stacks *data, int len, int push);

// rotate
void	re_rotate(int *arr, int size, char c);
void	rotate(int *arr, int size, char c);

// swap
void	swap(int *arr, int size, char c);

// sorting
int		sort_to_a(t_stacks *data, int len);
int		sort_to_b(t_stacks *data, int len);
int		get_median(t_stacks *data, int *arr, int *median, int size);
void	sort_three(int	*arr, int size, char c);
void	sort_three_ab(t_stacks *data, int len);
void	sort_three_b(t_stacks *data, int len);
void	sort_five(t_stacks *data, int len);

#endif