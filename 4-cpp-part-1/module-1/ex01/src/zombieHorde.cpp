/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:40:58 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 16:07:45 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde =
		new (std::nothrow) Zombie[static_cast<std::size_t>(N)]()
	;
	if (horde)
	{
		for (int i = 0 ; i < N ; ++i)
			horde[i].setName(name);
	}

	return horde;
}
