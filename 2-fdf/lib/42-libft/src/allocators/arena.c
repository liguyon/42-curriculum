/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:45:14 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/29 15:47:02 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena_internal.h"

void	*arena_init(size_t buffer_size)
{
	t_arena	*a;
	void	*buf;

	buf = malloc(buffer_size);
	if (!buf)
		return (NULL);
	a = malloc(sizeof(t_arena));
	if (!a)
		return (NULL);
	a->buf = buf;
	a->buf_size = buffer_size;
	a->curr_offset = 0;
	a->prev_offset = 0;
	return (a);
}

void	arena_reset(t_arena *a)
{
	a->curr_offset = 0;
	a->prev_offset = 0;
}

void	arena_destroy(t_arena *a)
{
	arena_reset(a);
	if (a->buf)
		free(a->buf);
	free(a);
}
