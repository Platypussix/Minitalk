/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:25:31 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/22 16:53:24 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	c;

	if ((!s1 || !s2) && len == 0)
		return (NULL);
	if (*s2 == 0 || s1 == s2)
		return ((char *)s1);
	c = ft_strlen(s2);
	while (*s1 && c <= len--)
	{
		if (!(ft_strncmp((char *)s1, (char *)s2, c)))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
