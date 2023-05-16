/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:55:03 by amedioun          #+#    #+#             */
/*   Updated: 2022/12/02 16:46:20 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_compteur(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 1;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				count++;
		}
		else
			i++;
	}
	return (count + 1);
}

static char	**ft_freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_split_ext(char **str, char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (k < ft_compteur(s, c) - 1)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		str[k] = ft_substr(s, i, j - i);
		if (str[k] == NULL)
			return (ft_freestr(str));
		k++;
		i = j;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	if ((*s == 0 && c == 0) || (!s && c == 0))
	{
		str = ft_calloc(1, sizeof(char *));
		return (str);
	}
	str = ft_calloc(ft_compteur(s, c), sizeof(char *));
	if (!str)
		return (NULL);
	ft_split_ext(str, s, c);
	if (!str)
		return (NULL);
	return (str);
}
