/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:21:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/05/13 21:21:17 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define _XOPEN_SOURCE 500

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <signal.h>
# include "ft_printf.h"

typedef struct s_msg
{
	const unsigned char	*str;
	size_t				len;
	int					pid;
	int					send_signal;
	int					msg_received;
}	t_msg;

# define ERRCODE_ARGC 1
# define ERRMSG_ARGC "Invalid number of arguments. \
		Specify the PID and the message to send.\n"
# define ERRCODE_INVALID_PID 2
# define ERRMSG_INVALID_PID "Invalid PID.\n"
# define ERRCODE_EMPTY_STR 3
# define ERRMSG_EMPTY_STR "Can't send an empty string.\n"
# define ERRCODE_SIGACTION_FAIL 4
# define ERRMSG_SIGACTION_FAIL "Failed to register a signal handler.\n"
# define ERRCODE_SEND_SIG 5
# define ERRMSG_SEND_SIG "Failed to send a signal to the specified PID.\n"
# define ERRCODE_TIMEOUT 6
# define ERRMSG_TIMEOUT "Data transmission timeout.\n"
# define ERRCODE_SEND_MSG 7
# define ERRMSG_SEND_MSG "Transmission error. \
			Server may have received incomplete message.\n"

# define MSG_SENDING "Sending message of length %d to [PID %d]...\n"
# define MSG_SENT "\nMessage sent.\n"

int		print_error_message(int error_code);
int		send_bit(int pid, u_int64_t bit);
int		send_data(int pid, u_int64_t data, size_t bits_size);
void	send_str(int pid, const unsigned char *str);

#endif
