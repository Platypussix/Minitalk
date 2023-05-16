/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:56:58 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/30 19:00:16 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sublen(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
		i++;
	if (start > i)
		return (0);
	if (!s[start] || !len)
		return (0);
	j = 0;
	while (start < i && len > 0)
	{
		j++;
		start++;
		len--;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_sublen(s, start, len);
	dest = malloc(l + 1);
	if (!dest)
		return (NULL);
	if (l)
	{
		while (i < len && s[i + start])
		{
			dest[i] = ((char *)s)[i + start];
			i++;
		}
	}
	dest[i] = 0;
	return (dest);
}
/*
int main ()
{
	char str[] = "coucou";
	unsigned int start = 3;
	size_t len = 2;
	char *s = ft_substr(str, start, len);
	printf("%s\n", s);
}
*/