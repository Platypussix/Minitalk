/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:59:20 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/25 19:00:56 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	ret = 0;
	if (size == 0)
		return (ret + ft_strlen(src));
	while (dest[ret] && ret < size)
		ret++;
	i = ret;
	while (i < size - 1 && src[i - ret])
	{
		dest[i] = src[i - ret];
		i++;
	}
	if (ret < size)
		dest[i] = 0;
	return (ret + ft_strlen(src));
}
