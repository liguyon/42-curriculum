/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:20:24 by liguyon           #+#    #+#             */
/*   Updated: 2023/05/13 21:20:26 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_msg	g_msg;

int	parse_msg(int ac, char **av)
{
	long	pid;

	if (ac != 3)
		exit(print_error_message(ERRCODE_ARGC));
	g_msg.len = ft_strlen(av[2]);
	if (!g_msg.len)
		exit(print_error_message(ERRCODE_EMPTY_STR));
	g_msg.str = (const unsigned char *)av[2];
	pid = ft_atol(av[1]);
	if (pid < 1 || pid > INT_MAX)
		exit(print_error_message(ERRCODE_INVALID_PID));
	g_msg.pid = (int)pid;
	return (0);
}

void	sigusr_handler(int signum)
{
	if (signum == SIGUSR1)
		g_msg.send_signal = 1;
	else if (signum == SIGUSR2)
		g_msg.msg_received = 1;
}

int	set_signal_handler(void)
{
	struct sigaction	sa_sigusr;

	sa_sigusr.sa_handler = sigusr_handler;
	sigemptyset(&sa_sigusr.sa_mask);
	sa_sigusr.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa_sigusr, NULL) == -1
		|| sigaction(SIGUSR2, &sa_sigusr, NULL) == -1)
		exit(print_error_message(ERRCODE_SIGACTION_FAIL));
	return (0);
}

int	main(int ac, char **av)
{
	parse_msg(ac, av);
	set_signal_handler();
	g_msg.msg_received = 0;
	ft_printf(MSG_SENDING, (int)g_msg.len, g_msg.pid);
	send_data(g_msg.pid, g_msg.len, CHAR_BIT * sizeof(size_t));
	send_str(g_msg.pid, g_msg.str);
	usleep(2000);
	if (!g_msg.msg_received)
		return (print_error_message(ERRCODE_SEND_MSG));
	else
		ft_printf(MSG_SENT);
	return (0);
}
