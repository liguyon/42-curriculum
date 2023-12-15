/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:38:26 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 17:25:26 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{

public:

	Weapon();
	Weapon(const std::string& type);
	const std::string& getType() const;
	void setType(const std::string& newType);


private:

	std::string type;

};
