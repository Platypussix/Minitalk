/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:08:08 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/16 12:20:01 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	translater(int sig)
{
	static unsigned char	byte;
	static int				bitcount;

	byte = 0;
	bitcount = 0;
	byte <<= 1;
	if (sig == SIGUSR1)
		byte |= 0x01;
	else
		byte |= 0x00;
	bitcount++;
	if (bitcount == 8)
	{
		write(1, &byte, 1);
		byte = 0;
		bitcount = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void) av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, translater);
	signal(SIGUSR2, translater);
	while (1)
	{
		pause();
	}
	return (0);
}
