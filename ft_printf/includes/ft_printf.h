/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:02:49 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/16 12:21:27 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_formater(va_list ap, char type);
int		ft_parser(const char *str, va_list ap);
int		ft_putchar(char g);
int		ft_putstr(char *str);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putunbr_base(unsigned int nb, char *base);
int		ft_printptr(unsigned long long ptr);
void	ft_printthex(unsigned long n);
int		ft_ptrlen(unsigned long n);

#endif