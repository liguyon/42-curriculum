/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:41:04 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 17:36:52 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include <iostream>

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string &type)
{
	this->type = type;
}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &newType)
{
	type = newType;
}
