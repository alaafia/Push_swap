/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:33:57 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/16 15:34:02 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int n)
{
	size_t	i;

	i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	nb;

	len = numlen(n);
	nb = n;
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	str = malloc(len + 1);
	str[len] = '\0';
	str[--len] = nb % 10 + '0';
	while (nb)
	{
		nb /= 10;
		str[--len] = nb % 10 + '0';
	}
	if (n < 0)
		*(str) = '-';
	return (str);
}
