/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:37:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/05/13 21:37:55 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern t_msg	g_msg;

int	print_error_message(int error_code)
{
	if (error_code == ERRCODE_ARGC)
		ft_print_error(ERRMSG_ARGC);
	else if (error_code == ERRCODE_INVALID_PID)
		ft_print_error(ERRMSG_INVALID_PID);
	else if (error_code == ERRCODE_EMPTY_STR)
		ft_print_error(ERRMSG_EMPTY_STR);
	else if (error_code == ERRCODE_SIGACTION_FAIL)
		ft_print_error(ERRMSG_SIGACTION_FAIL);
	else if (error_code == ERRCODE_SEND_SIG)
		ft_print_error(ERRMSG_SEND_SIG);
	else if (error_code == ERRCODE_TIMEOUT)
		ft_print_error(ERRMSG_TIMEOUT);
	else if (error_code == ERRCODE_SEND_MSG)
		ft_print_error(ERRMSG_SEND_MSG);
	return (error_code);
}

int	send_bit(int pid, u_int64_t bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(print_error_message(ERRCODE_SEND_SIG));
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(print_error_message(ERRCODE_SEND_SIG));
	}
	return (0);
}

int	send_data(int pid, u_int64_t data, size_t bits_size)
{
	size_t	i;

	i = -1;
	while (++i < bits_size)
	{
		g_msg.send_signal = 0;
		send_bit(pid, data & (1 << i));
		usleep(2000);
		if (g_msg.send_signal != 1)
			exit(print_error_message(ERRCODE_TIMEOUT));
	}
	return (0);
}

void	send_str(int pid, const unsigned char *str)
{
	size_t	i;

	i = -1;
	while (++i < g_msg.len)
		send_data(pid, str[i], CHAR_BIT * sizeof(unsigned char));
}
