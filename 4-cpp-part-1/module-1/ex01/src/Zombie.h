/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:31:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 16:02:10 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie
{

public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(const std::string& name);


private:
	std::string m_name;

};

Zombie* zombieHorde(int N, std::string name);
