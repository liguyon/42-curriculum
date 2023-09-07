/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:10:58 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/17 17:11:04 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp1;
	t_list	*temp2;

	if (*lst)
	{
		temp1 = *lst;
		while (temp1->next != NULL)
		{
			temp2 = temp1->next;
			ft_lstdelone(temp1, del);
			temp1 = temp2;
		}
		ft_lstdelone(temp1, del);
	}
	*lst = NULL;
}
