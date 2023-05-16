/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:20:18 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/22 14:27:23 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	int		i;

	i = 0;
	d = ft_strdup(s);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = (*f)(i, s[i]);
		i++;
	}
	return (d);
}
