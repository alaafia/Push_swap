/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:12:11 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/16 16:12:31 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = (0);
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		++s;
	}
	if (last)
		return (last);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
