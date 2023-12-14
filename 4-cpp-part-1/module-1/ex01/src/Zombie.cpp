/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:38:12 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 16:08:04 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "Zombie created\n";
}

Zombie::~Zombie()
{
	std::cout << m_name << ": destroyed\n";
}

void Zombie::announce(void)
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const std::string& name)
{
	m_name = name;
}
