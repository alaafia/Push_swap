/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:18:31 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/19 14:55:16 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s)
		return (NULL);
	result = malloc((ft_strlen((char *)s) + 1));
	ft_bzero(result, ft_strlen((char *)s) + 1);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		++i;
	}
	result[i] = '\0';
	return (result);
}
