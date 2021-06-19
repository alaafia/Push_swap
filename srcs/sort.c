/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:33:57 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/19 16:09:58 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tree(t_all *a)
{
	if (a->stack->next != a->last)
	{
		if (a->stack->data < a->stack->next->data
			&& a->last->data < a->stack->next->data)
			execute_instruction(a, NULL, "rra", 1);
		else if (a->stack->data > a->last->data
			&& a->stack->data > a->last->prev->data)
			execute_instruction(a, NULL, "ra", 1);
	}
	if (a->stack->data > a->stack->next->data)
		execute_instruction(a, NULL, "sa", 1);
}

static void	sort_five(t_all *a, t_all *b)
{
	int	i;

	i = 0;
	while (++i <= 2)
	{
		while (a->stack->data >= 3)
			execute_instruction(a, b, "ra", 1);
		execute_instruction(a, b, "pb", 1);
	}
	sort_tree(a);
	if (b->stack->data < b->stack->next->data)
		execute_instruction(a, b, "sb", 1);
	execute_instruction(a, b, "pa", 1);
	execute_instruction(a, b, "pa", 1);
}

void	ft_sort(t_all *a, t_all *b, int len)
{
	if (!is_sorted(a->stack, b->stack))
	{
		if (len <= 3)
			sort_tree(a);
		else if (len <= 5)
			sort_five(a, b);
		else
			sort_a(a, b, 1, len);
	}
}
