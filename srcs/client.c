/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:06:51 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/23 14:06:51 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sig_received(int signal)
{
	static int	nb_oct = 0;

	if (signal == SIGUSR1)
		nb_oct++;
	else
	{
		ft_printf("%d octet(s) recu(s), message envoye !\n", nb_oct);
		exit(0);
	}
}

static void	ft_send_str(char *str, pid_t pid)
{
	int				i_str;
	unsigned char	c;
	int				i_bit;

	i_str = -1;
	while (str[++i_str])
	{
		i_bit = 7;
		c = str[i_str];
		while (i_bit > -1)
		{
			if (c >> i_bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i_bit--;
			usleep(100);
		}
	}
	while (++i_bit < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (0);
	signal(SIGUSR1, &ft_sig_received);
	signal(SIGUSR2, &ft_sig_received);
	ft_send_str(argv[2], (pid_t) ft_atoi((argv[1])));
	while (1)
		pause();
	return (0);
}
