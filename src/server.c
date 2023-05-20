/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:08:08 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/20 15:13:39 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	s_translater(int sig, siginfo_t *info, void *context)
{
	static int	counter = 0;
	static char	byte = 0;
	static int	len = 0;
	static char	message[LEN_MAX];

	(void)context;
	if (sig == SIGUSR2)
		byte |= 128 >> counter;
	counter++;
	if (counter == 8)
	{
		message[len] = byte;
		len++;
		byte = 0;
		counter = 0;
	}
	if (message[len - 1] == '\0')
	{
		write(1, message, len);
		len = 0;
	}
	usleep(50);
	kill(info -> si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s1;
	struct sigaction	s2;
	long int			pid;

	pid = getpid();
	ft_printf("PID actuel: %d\n", pid);
	s1.sa_flags = SA_SIGINFO;
	s2.sa_flags = SA_SIGINFO;
	s1.sa_sigaction = s_translater;
	s2.sa_sigaction = s_translater;
	while (1)
	{
		sigaction(SIGUSR1, &s1, NULL);
		sigaction(SIGUSR2, &s2, NULL);
		pause();
		usleep(150);
	}
	return (0);
}
