/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 06:15:48 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 14:51:44 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define GNL_BUFFER_SIZE 4096
# define GNL_MAX_FD 1024

char	*get_next_line(int fd);

#endif