/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 05:06:31 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.h>
#include <iostream>

static void printFormattedEntry(const std::string& entry)
{
	int len = entry.length();
	if (len <= 10)
	{
		std::cout << entry;
		for (int i = 0 ; i < 10 - len ; ++i)
			std::cout << ' ';
	}
	else
	{
		std::string entry_cut = entry.substr(0, 9);
		std::cout << entry_cut << '.';
	}
}

void Contact::print(void) const
{
	std::cout << '|';
	printFormattedEntry(this->m_name);
	std::cout << '|';
	printFormattedEntry(this->m_lastName);
	std::cout << '|';
	printFormattedEntry(this->m_nickname);
	std::cout << '|';
	printFormattedEntry(this->m_phoneNumber);
	std::cout << '|';
}
