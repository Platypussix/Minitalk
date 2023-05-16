/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:00:19 by amedioun          #+#    #+#             */
/*   Updated: 2022/12/10 19:41:08 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char g)
{
	return (write(1, &g, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	else
	{
		while (str[i])
			ft_putchar(str[i++]);
		return (i);
	}
}

int	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	long int	nb;
	int			ret;

	nb = nbr;
	i = 0;
	ret = 0;
	while (base[i])
		i++;
	if (nb < 0)
	{
		ret += ft_putchar('-');
		nb = (-nb);
	}
	if (nb >= i)
	{
		ret += ft_putnbr_base(nb / i, base);
		ret += ft_putnbr_base(nb % i, base);
	}
	else
		ret += ft_putchar(base[nb]);
	return (ret);
}

int	ft_putunbr_base(unsigned int nbr, char *base)
{
	int			i;
	long int	nb;
	int			ret;

	nb = nbr;
	i = 0;
	ret = 0;
	while (base[i])
		i++;
	if (nb < 0)
	{
		ret += ft_putchar('-');
		nb = (-nb);
	}
	if (nb >= i)
	{
		ret += ft_putnbr_base(nb / i, base);
		ret += ft_putnbr_base(nb % i, base);
	}
	else
		ret += ft_putchar(base[nb]);
	return (ret);
}
