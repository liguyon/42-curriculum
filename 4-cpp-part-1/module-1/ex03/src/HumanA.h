/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:43:12 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 17:21:28 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.h"
#include <string>

class HumanA
{

public:
	HumanA(const std::string& name, Weapon& weapon);
	void attack() const;


private:
	std::string m_name;
	Weapon& m_weapon;

};
