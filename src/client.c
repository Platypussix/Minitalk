/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:51:20 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/20 14:41:34 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	c_translater(unsigned char ch, int pid)
{
	int				c;
	unsigned int	base;

	c = 0;
	base = 128;
	while (c < 8)
	{
		if (ch < base)
		{
			kill(pid, SIGUSR1);
		}			
		else
		{
			kill(pid, SIGUSR2);
			ch -= base;
		}
		base /= 2;
		c++;
		pause();
		usleep(50);
	}
}

void	fonction( int tmp )
{
	(void)tmp;
}

int	main(int ac, char **av)
{
	int		c;
	int		pid;

	c = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (ft_strlen(av[2]) > LEN_MAX || kill(pid, 0) != 0)
		{
			ft_printf("Erreur args\n");
			return (0);
		}
		signal(SIGUSR1, fonction);
		while (av[2][c])
		{
			c_translater(av[2][c], pid);
			c++;
		}
		c_translater('\0', pid);
	}	
	return (0);
}
