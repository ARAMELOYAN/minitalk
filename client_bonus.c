/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:11:17 by aeloyan           #+#    #+#             */
/*   Updated: 2022/10/08 20:13:34 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		res = res * 10 + ((int)*str) - 48;
		str++;
	}
	return (res);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "SIGNAL RECEIVED\n", 16);
}

void	end_of_text(int pid)
{
	int	j;

	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(80);
	}
}

int	main(int argc, char **argv)
{
	int	pid_p;
	int	i;
	int	j;

	if (argc < 3 || argc > 3)
		exit (1);
	pid_p = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, handler);
	while (argv[2][i])
	{
		j = sizeof(argv[2][i]) * 8 - 1;
		while (j >= 0)
		{
			if (argv[2][i] & 1 << j)
				kill(pid_p, SIGUSR2);
			else
				kill(pid_p, SIGUSR1);
			usleep(100);
			j--;
		}
		i++;
	}
	end_of_text(pid_p);
	return (0);
}
