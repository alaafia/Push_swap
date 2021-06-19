/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:37:10 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/19 15:01:19 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	a;
	t_all	b;
	int		i;

	i = -1;
	argv = get_arg(argc, argv);
	while (argv[++i])
		;
	argc = i;
	if (argc > 1)
	{
		if (!read_arg(argc, argv, &a))
			ft_exit(&argv, 0);
		ft_sort(&a, &b, argc - 1);
	}
	free_stack(&a);
	free_array(argv);
	free(argv);
	return (0);
}
