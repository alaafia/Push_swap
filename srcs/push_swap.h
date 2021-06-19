/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:33:11 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/19 15:33:15 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_all
{
	t_stack			*stack;
	t_stack			*last;
}					t_all;

char	**get_arg(int argc, char **argv);

int		execute_instruction(t_all *a, t_all *b, char *ins, int show);
int		read_arg(int ac, char **av, t_all *a);
void	quick_sort(int arr[], int low, int high);
int		is_sorted(t_stack *a, t_stack *b);
void	ft_sort(t_all *a, t_all *b, int len);
void	sort_a(t_all *a, t_all *b, int start, int end);
void	free_array(char **tab);
void	free_stack(t_all *a);
void	ft_stackadd(t_all *all, t_stack *new);
t_stack	*ft_stacknew(int data);
void	ft_exit(char ***argv, int s);
int		get_next_line(int fd, char **line);

#endif
