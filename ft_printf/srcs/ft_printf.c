/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:04:44 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/15 10:43:26 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_formater(va_list ap, char type)
{
	int	ret;

	ret = 0;
	if (type == 'c')
		ret += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		ret += ft_printptr(va_arg(ap, unsigned long));
	else if (type == 'd' || type == 'i')
		ret += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (type == 'u')
		ret += ft_putunbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (type == 'x')
		ret += ft_putunbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		ret += ft_putunbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (type == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_parser(const char *str, va_list ap)
{
	int		i;
	char	type;
	int		ret;

	i = 0;
	type = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
				type = str[i + 1];
				ret += ft_formater(ap, type);
				i++;
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;

	if (!str)
		return (-1);
	va_start(ap, str);
	ret = ft_parser(str, ap);
	va_end(ap);
	return (ret);
}
