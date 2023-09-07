/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:20:44 by liguyon           #+#    #+#             */
/*   Updated: 2023/05/13 21:20:47 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_msg	g_msg;

void	sigusr_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	g_msg.client_pid = siginfo->si_pid;
	g_msg.send_signal = 1;
	if (!g_msg.len_received)
		recv_msg_len(signum);
	else
		recv_msg_str(signum);
}

void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		if (g_msg.str != NULL)
		{
			free(g_msg.str);
			g_msg.str = NULL;
		}
		ft_printf("\nServer closed.\n");
		exit(0);
	}
}

int	set_signal_handler(void)
{
	struct sigaction	sa_sigusr;
	struct sigaction	sa_sigint;

	sa_sigusr.sa_sigaction = sigusr_handler;
	sigemptyset(&sa_sigusr.sa_mask);
	sa_sigusr.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_sigusr, NULL) == -1
		|| sigaction(SIGUSR2, &sa_sigusr, NULL) == -1)
		exit(print_error_message(ERRCODE_SIGACTION_FAIL));
	sa_sigint.sa_handler = sigint_handler;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = 0;
	if (sigaction(SIGINT, &sa_sigint, NULL) == -1)
		exit(print_error_message(ERRCODE_SIGACTION_FAIL));
	return (0);
}

void	init_gmsg(void)
{
	g_msg.client_pid = 0;
	g_msg.current_bit = 0;
	g_msg.current_char = 0;
	g_msg.len = 0;
	g_msg.len_received = 0;
	g_msg.message_received = 0;
	g_msg.received_bits = 0;
	g_msg.send_signal = 0;
	g_msg.str = NULL;
	ft_printf(MSG_LISTEN, getpid());
}

int	main(void)
{
	set_signal_handler();
	while (1)
	{
		init_gmsg();
		pause();
		while (!g_msg.message_received)
			pause();
		if (g_msg.message_received == 1)
		{
			usleep(100);
			send_reply(g_msg.client_pid, SIGUSR2);
			ft_printf(MSG_RECEIVED,
				(int)g_msg.len, g_msg.client_pid, g_msg.str);
			free(g_msg.str);
		}
	}
	return (0);
}
