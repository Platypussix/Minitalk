/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:21:54 by amedioun          #+#    #+#             */
/*   Updated: 2022/11/25 16:39:16 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (size > 0 && SIZE_MAX / size < nmemb)
		return (NULL);
	str = malloc(size * nmemb);
	if (!(str))
		return (NULL);
	ft_bzero(str, (size * nmemb));
	return (str);
}
