/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 09:33:49 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.h>
#include <iostream>
#include <sstream>

static const std::string getUserInput(const std::string& field)
{
	std::cout << "Enter the contact's " << field << ":" << std::endl;
	std::string ret;
	std::getline(std::cin >> std::ws, ret);
	return ret;
}

Contact::Contact()
{
	static int id = 0;
	m_id = id++;
	m_name = getUserInput("first name");
	m_lastName = getUserInput("last name");
	m_nickname = getUserInput("nickname");
	m_phoneNumber = getUserInput("phone number");
	m_secret = getUserInput("darkest secret");
}

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
		std::cout << entry.substr(0, 9) << '.';
}

void Contact::displayInList(void) const
{
	std::cout << '|';
	
	// convert id to string
	std::stringstream stream;
	stream << m_id;
	std::string id_str;
	stream >> id_str;
	printFormattedEntry(id_str);

	std::cout << '|';
	printFormattedEntry(m_name);
	std::cout << '|';
	printFormattedEntry(m_lastName);
	std::cout << '|';
	printFormattedEntry(m_nickname);
	std::cout << "|\n";
}

void Contact::print(void) const
{
	std::cout << m_name << '\n' << m_lastName << '\n' << m_nickname << '\n'
		<< m_phoneNumber << '\n' << m_secret << std::endl;
}
