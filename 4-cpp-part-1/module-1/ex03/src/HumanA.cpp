/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:45:29 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 17:21:12 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: m_name(name), m_weapon(weapon)
{
	m_name = name;
	m_weapon = weapon;
}

void HumanA::attack() const
{
	std::cout <<
		m_name << " attacks with their " << m_weapon.getType() << '\n';
}
