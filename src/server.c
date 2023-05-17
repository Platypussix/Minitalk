/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:08:08 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/17 16:30:07 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	translater(int sig)
{
	static unsigned char	byte;
	static int				bitcount;
	byte = 0;
	bitcount = 0;
	byte <<= 1;//Decale les bits de byte vers la gauche
	if (sig == SIGUSR1)
		byte |= 0x01;//Bit a 1 en hexa
	else
		byte |= 0x00;//Bit a 0 en hexa
	if (++bitcount == 8)
	{
printf("Byte received: %c\n", byte);
		write(1, &byte, 1);
		byte = 0;
		bitcount = 0;
	}
else
{
printf("Bit received: %d\n", (sig == SIGUSR1) ? 1 : 0);
}
}

int	main(int ac, char **av)
{
	int	pid;
	struct sigaction sa;

	(void) av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID actuel: %d\n", pid);
	sa.sa_handler = translater;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
printf("pause ");
		pause();
	}
	return (0);
}
