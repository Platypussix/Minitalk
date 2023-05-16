/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:18:58 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/22 16:58:32 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;

	if (!s)
		return (NULL);
	dest = (unsigned char *)s;
	while (n > 0)
	{
		if (*dest == (unsigned char)c)
			return ((unsigned char *)dest);
		dest++;
		n--;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_memchr("le blackh0le me guette", '0', 15));
}
*/