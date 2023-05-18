/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedioun <amedioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:51:20 by amedioun          #+#    #+#             */
/*   Updated: 2023/05/18 18:43:25 by amedioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

// static int	ft_atoi(char *str)
// {
// 	int					i;
// 	int					sign;
// 	unsigned long int	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result *= 10;
// 		result += str[i] - '0';
// 		i++;
// 	}
// 	return (result * sign);
// }

void	c_translater(unsigned char ch, pid_t pid)
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
		usleep(SLEEP_TIME);
	}
}

void	fonction( int tmp )
{
	(void)tmp;
}

int	main(int args, char **argv)
{
	int		c;
	int		pid;

	c = 0;
	if (args == 3)
	{
		pid = ft_atoi(argv[1]);
		if (ft_strlen(argv[2]) > LEN_MAX || kill(pid, 0) != 0)
		{
			ft_printf("Erreur args\n");
			return (0);
		}
		signal(SIGUSR1, fonction);
		while (argv[2][c])
		{
			c_translater(argv[2][c], pid);
			c++;
		}
		c_translater('\0', pid);
	}	
	return (0);
}
