/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:31:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 15:30:37 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie
{


public:
	Zombie(std::string& name);
	~Zombie();
	void announce(void);


private:
	std::string m_name;

};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
