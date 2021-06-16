/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <alaafia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:17:05 by alaafia           #+#    #+#             */
/*   Updated: 2021/06/16 16:18:10 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	while (s1[j])
		++j;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	i = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = malloc(i);
	while (*s1)
	{
		*ret = *s1;
		ret++;
		s1++;
	}
	while (*s2)
	{
		*ret = *s2;
		ret++;
		s2++;
	}
	*ret = '\0';
	return (ret - i + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		x;

	if (!s)
		return (0);
	ret = malloc(len + 1);
	x = len;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	while (start-- > 0)
		s++;
	while (len-- > 0)
		*ret++ = *s++;
	*ret = '\0';
	return (ret - x);
}

int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_set(s1[i], set))
		i++;
	while (is_set(s1[j], set) && j)
		j--;
	if (i > j)
		return (ft_strdup(""));
	p = ft_substr(s1, i, j - i + 1);
	return (p);
}
