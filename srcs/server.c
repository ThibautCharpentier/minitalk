/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:06:25 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/23 14:06:25 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sig_received(int signal, siginfo_t *sig_info, void *ucontext)
{
	static unsigned char	c = 0;
	static int				bit = 0;
	static pid_t			pid_client = 0;

	(void) ucontext;
	if (!pid_client)
		pid_client = sig_info->si_pid;
	c = c | (signal == SIGUSR1);
	if (++bit == 8)
	{
		bit = 0;
		if (!c)
		{
			kill(pid_client, SIGUSR2);
			ft_putchar_fd('\n', 1);
			pid_client = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(pid_client, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	s_sig;

	ft_printf("PID du serveur : %d\n", getpid());
	s_sig.sa_flags = SA_SIGINFO;
	s_sig.sa_sigaction = &ft_sig_received;
	sigaction(SIGUSR1, &s_sig, 0);
	sigaction(SIGUSR2, &s_sig, 0);
	while (1)
		pause();
	return (0);
}
