/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamamot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:45:21 by hyamamot          #+#    #+#             */
/*   Updated: 2025/04/02 17:45:22 by hyamamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	sub_sort_fix(t_node **a, t_node **b, t_ops **ops)
{
	push_a(b, a, ops);
	rotate_a(a, ops);
}

// static void	sub_three_sort(t_node **b, t_ops **ops)
// {
// 	int	first;
// 	int	second;
// 	int	third;

// 	first = (*b)->index;
// 	second = (*b)->pnext->index;
// 	third = (*b)->pprev->index;
// 	if (first < second && second < third)
// 		return ;
// 	else if (first > second && first < third)
// 		swap_b(b, ops);
// 	else if ((first > second && first > third) && second > third)
// 	{
// 		swap_b(b, ops);
// 		reverse_rotate_b(b, ops);
// 	}
// 	else if ((first > second && first > third) && second < third)
// 		rotate_b(b, ops);
// 	else if ((first < second && first < third) && second > third)
// 	{
// 		swap_b(b, ops);
// 		rotate_b(b, ops);
// 	}
// 	else if (first < second && first > third)
// 		reverse_rotate_b(b, ops);
// }

static void	sub_three_sort(t_node **b, t_ops **ops)
{
	int	first;
	int	second;
	int	third;

	first = (*b)->index;
	second = (*b)->pnext->index;
	third = (*b)->pprev->index;
	if (first < second && second < third)
		return ;
	else if (first > second && first < third)
		swap_b(b, ops);
	else if ((first > second && first > third) && second > third)
	{
		swap_b(b, ops);
		reverse_rotate_b(b, ops);
	}
	else if ((first > second && first > third) && second < third)
		rotate_b(b, ops);
	else if ((first < second && first < third) && second > third)
	{
		swap_b(b, ops);
		rotate_b(b, ops);
	}
	else if (first < second && first > third)
		reverse_rotate_b(b, ops);
}

void	sort_fix(t_node **a, t_node **b, t_ops **ops)
{
	int	i;

	i = 0;
	if (list_len(b) == 3)
	{
		sub_three_sort(b, ops);
		while (i++ < 3)
			sub_sort_fix(a, b, ops);
	}
	else if (list_len(b) == 2)
	{
		if ((*b)->index > (*b)->pnext->index)
			swap_b(b, ops);
		while (i++ < 2)
			sub_sort_fix(a, b, ops);
	}
	else
		sub_sort_fix(a, b, ops);
}
