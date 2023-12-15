/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:21:47 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/15 09:53:08 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"
#include <string>

class HumanB
{

public:

	HumanB(const std::string& name);
	void attack() const;
	void setWeapon(Weapon& weapon);


private:
	std::string m_name;
	Weapon* m_weapon;

};
