/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:08:08 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/18 18:48:03 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	s_translater(int sig, siginfo_t *info, void *context)
{
	static int	counter = 0;
	static char	ch = 0;
	static int	len = 0;
	static char	message[LEN_MAX];

	(void)context;
	if (sig == SIGUSR2)
		ch |= 128 >> counter;
	counter++;
	if (counter == 8)
	{
		message[len] = ch;
		len++;
		ch = 0;
		counter = 0;
	}
	if (message[len - 1] == '\0')
	{
		write(1, message, len);
		len = 0;
	}
	usleep(SLEEP_TIME);
	kill(info -> si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	s1;
	struct sigaction	s2;
	pid_t				my_pid;

	my_pid = getpid();
	ft_printf("PID actuel: %d\n", (int)my_pid);
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
