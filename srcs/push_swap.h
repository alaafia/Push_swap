/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:58:30 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/16 14:02:48 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
//# include "../libft/includes/libft.h"
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

int		execute_instruction(t_all *a, t_all *b, char *ins, int show);
void	sort_b(t_all *a, t_all *b, int start, int end);
void	sort_a(t_all *a, t_all *b, int start, int end);
int		read_arg(int ac, char **av, t_all *a);
void	heap_sort(int *arr, int n);
int		is_sorted(t_stack *a, t_stack *b);
int		get_next_line(int fd, char **line);
void	ft_sort(t_all *a, t_all *b, int len);
char	**get_arg(int argc, char **argv);
void	sort_a(t_all *a, t_all *b, int start, int end);
void	free_stack(t_all *a);
void	ft_stackadd(t_all *all, t_stack *news);
t_stack	*ft_stacknew(int data);
void	sort_b(t_all *a, t_all *b, int start, int end);
void	ft_exit(char ***argv, int s);
void	free_array(char **tab);
#endif