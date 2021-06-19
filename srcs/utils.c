/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:34:48 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/19 16:10:07 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
}

void	ft_exit(char ***argv, int s)
{
	free_array(*argv);
	free(*argv);
	if (s == 0)
		write(1, "Error\n", 6);
	else if (s == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}

/* swap two values*/
static void	swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition (int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = low;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[high]);
	return (i);
}

void	quick_sort(int *arr, int low, int high)
{
	int	i;

	if (low < high)
	{
		i = partition (arr, low, high);
		quick_sort(arr, i + 1, high);
		quick_sort(arr, low, i - 1);
	}
}
