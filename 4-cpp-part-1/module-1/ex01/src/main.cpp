/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:44 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 16:13:31 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	int nZombies = 10;
	std::string name = "JeanPoule";

	Zombie* horde = zombieHorde(nZombies, name);
	if (horde)
	{
		for (int i = 0 ; i < nZombies ; ++i)
			horde[i].announce();
	}

	delete[] horde;

	return 0;
}
