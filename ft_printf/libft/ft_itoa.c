/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:14 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/25 18:44:53 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_size(long int n)
{
	int	c;
	int	signe;

	c = 1;
	signe = 0;
	if (n < 0)
	{
		signe += 1;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		c++;
	}
	return (c + signe);
}

char	*ft_itoa(int n)
{
	char		*dst;
	long int	nb;
	int			size;

	nb = n;
	size = ft_set_size(nb);
	dst = ft_calloc(size + 1, 1);
	if (!dst)
		return (NULL);
	if (n < 0)
		nb *= -1;
	while (size - 1 >= 0)
	{
		dst[size - 1] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
