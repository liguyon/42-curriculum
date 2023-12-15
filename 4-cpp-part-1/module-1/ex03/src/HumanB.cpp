/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:26:11 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/15 09:53:19 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string& name)
{
	m_name = name;
	m_weapon = NULL;
}

void HumanB::attack() const
{
	std::cout <<
	m_name << " attacks with their " << m_weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
	m_weapon = &weapon;
}
