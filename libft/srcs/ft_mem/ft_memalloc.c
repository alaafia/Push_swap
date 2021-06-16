/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:40:49 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/16 15:41:39 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (--n >= 0)
		*p++ = 0;
}


void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	p = ft_memalloc(count * size);
	return (p);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	ft_bzero(mem, size);
	return (mem);
}