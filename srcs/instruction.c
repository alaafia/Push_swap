/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:32:26 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/19 16:09:28 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*************************SWAP***************************************/
/* swap : swapping values only **/

static int	swap(t_all *a)
{
	int	tmp;

	if (a && a->stack && a->stack->next)
	{
		tmp = a->stack->next->data;
		a->stack->next->data = a->stack->data;
		a->stack->data = tmp;
	}
	return (1);
}

/*************************PUSH***************************************/
	/*pushing first element in stack 'b' into stack 'a'*/
static int	push(t_all *a, t_all *b)
{
	t_stack	*tmp;

	if (a && b && b->stack)
	{
		tmp = b->stack;
		b->stack = tmp->next;
		tmp->next = a->stack;
		if (a->stack)
			a->stack->prev = tmp;
		a->stack = tmp;
		if (a->last == NULL)
			a->last = a->stack;
		if (b->stack == NULL)
			b->last = NULL;
		else
			b->stack->prev = NULL;
	}
	return (1);
}

/*************************Rotat***************************************/
/*rotat the first element to be the  last 
one and descreasing the others by one step*/

static int	rotate(t_all *a)
{
	t_stack	*tmp;

	if (a && a->stack && a->stack->next)
	{
		tmp = a->stack;
		a->stack = tmp->next;
		tmp->next = NULL;
		a->stack->prev = NULL;
		a->last->next = tmp;
		tmp->prev = a->last;
		a->last = tmp;
	}
	return (1);
}

/*************************Reverse Rotat***************************************/
	/* rotat the last element to be the  
	first one and increasing the others by one step*/

static int	reverse_rotate(t_all *a)
{
	t_stack	*tmp;

	if (a && a->stack && a->stack->next)
	{
		tmp = a->last;
		a->last = tmp->prev;
		tmp->prev = NULL;
		a->last->next = NULL;
		a->stack->prev = tmp;
		tmp->next = a->stack;
		a->stack = tmp;
	}
	return (1);
}
/* show is used as indice to defer between 
the checker '0' and the  push swap '1'
/ index i is used to know if we used some instructions or none 
'1' is everything is okay and '0' for errors */

int	execute_instruction(t_all *a, t_all *b, char *ins, int show)
{
	int	i;

	i = 0;
	if (!ft_strncmp(ins, "sa", 10) || !ft_strncmp(ins, "ss", 10))
		i = swap(a);
	if (!ft_strncmp(ins, "sb", 10) || !ft_strncmp(ins, "ss", 10))
		i = swap(b);
	if (!ft_strncmp(ins, "pa", 10))
		i = push(a, b);
	if (!ft_strncmp(ins, "pb", 10))
		i = push(b, a);
	if (!ft_strncmp(ins, "ra", 10) || !ft_strncmp(ins, "rr", 10))
		i = rotate(a);
	if (!ft_strncmp(ins, "rb", 10) || !ft_strncmp(ins, "rr", 10))
		i = rotate(b);
	if (!ft_strncmp(ins, "rra", 10) || !ft_strncmp(ins, "rrr", 10))
		i = reverse_rotate(a);
	if (!ft_strncmp(ins, "rrb", 10) || !ft_strncmp(ins, "rrr", 10))
		i = reverse_rotate(b);
	if (show && i)
	{
		ft_putstr_fd(ins, 1);
		write(1, "\n", 1);
	}	
	return (i);
}
