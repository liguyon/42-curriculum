/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:45:05 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/29 15:50:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_INTERNAL_H
# define ARENA_INTERNAL_H
# include <stdlib.h>

typedef struct s_arena		t_arena;
struct s_arena
{
	void	*buf;
	size_t	buf_size;
	size_t	prev_offset;
	size_t	curr_offset;
};

#endif