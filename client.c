/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:12:22 by aeloyan           #+#    #+#             */
/*   Updated: 2022/10/18 12:39:27 by aeloyan          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid_p;
	int	i;
	int	j;

	if (argc < 3 || argc > 3)
		exit (1);
	pid_p = ft_atoi(argv[1]);
	i = 0;
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
	return (0);
}
