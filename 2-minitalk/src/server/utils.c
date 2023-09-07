/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:57:46 by liguyon           #+#    #+#             */
/*   Updated: 2023/05/13 21:57:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern t_msg	g_msg;

int	print_error_message(int error_code)
{
	if (error_code == ERRCODE_SIGACTION_FAIL)
		ft_print_error(ERRMSG_SIGACTION_FAIL);
	else if (error_code == ERRCODE_SEND_SIG)
		ft_print_error(ERRMSG_SEND_SIG);
	else if (error_code == ERRCODE_MALLOC_FAIL)
		ft_print_error(ERRMSG_MALLOC_FAIL);
	return (error_code);
}

void	send_reply(int pid, int signal)
{
	if (g_msg.send_signal == 1 || g_msg.message_received)
	{
		if (kill(pid, signal) == -1)
		{
			if (g_msg.str)
			{
				free(g_msg.str);
				g_msg.str = NULL;
			}
			exit(print_error_message(ERRCODE_SEND_SIG));
		}
	}
	g_msg.send_signal = 0;
}

void	recv_msg_len(int signum)
{
	if (signum == SIGUSR1)
		g_msg.received_bits |= (1 << g_msg.current_bit);
	g_msg.current_bit++;
	send_reply(g_msg.client_pid, SIGUSR1);
	if (g_msg.current_bit == sizeof(size_t) * CHAR_BIT)
	{
		g_msg.len = g_msg.received_bits;
		g_msg.received_bits = 0;
		g_msg.current_bit = 0;
		g_msg.len_received = 1;
	}
}

void	recv_msg_str(int signum)
{
	char	c;

	if (!g_msg.str)
	{
		g_msg.str = ft_calloc(1 + g_msg.len, sizeof(char));
		if (!g_msg.str)
			exit(print_error_message(ERRCODE_MALLOC_FAIL));
	}
	if (signum == SIGUSR1)
		g_msg.received_bits |= (1 << g_msg.current_bit);
	g_msg.current_bit++;
	send_reply(g_msg.client_pid, SIGUSR1);
	if (g_msg.current_bit == sizeof(char) * CHAR_BIT)
	{
		c = (char)g_msg.received_bits;
		g_msg.received_bits = 0;
		g_msg.current_bit = 0;
		g_msg.str[g_msg.current_char] = c;
		g_msg.current_char++;
		if (g_msg.current_char == (int)g_msg.len)
		{
			g_msg.str[g_msg.current_char] = '\0';
			g_msg.message_received = 1;
		}
	}
}
