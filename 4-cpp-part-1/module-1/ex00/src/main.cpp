/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:42:10 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 15:30:42 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	randomChump("JeanPaul-SquatteurDeStack");
	Zombie* zom = newZombie("JeanNeymar-OccupantDeHeap");
	if (zom)
		zom->announce();
	delete zom;
	return 0;
}
