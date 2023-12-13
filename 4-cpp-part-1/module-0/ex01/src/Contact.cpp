/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 14:44:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include <iostream>
#include <sstream>

Contact::Contact()
{
}

static const std::string getUserInput(const std::string& field)
{
	std::cout << "Enter the contact's " << field << ":" << std::endl;
	std::string ret;
	std::getline(std::cin >> std::ws, ret);
	return ret;
}

Contact::Contact(int id)
{
	m_id = id;
	std::cout << "\nAdding a new contact...\n";
	m_name = getUserInput("first name");
	m_lastName = getUserInput("last name");
	m_nickname = getUserInput("nickname");
	m_phoneNumber = getUserInput("phone number");
	m_secret = getUserInput("darkest secret");
	std::cout << "Added a contact successfully.\n";
}

static void printFormattedEntry(const std::string& entry)
{
	std::cout << '|';
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
	// convert id to string
	std::stringstream stream;
	stream << m_id;
	std::string id_str;
	stream >> id_str;
	printFormattedEntry(id_str);

	printFormattedEntry(m_name);

	printFormattedEntry(m_lastName);

	printFormattedEntry(m_nickname);
	std::cout << '|' << std::endl;
}

void Contact::print(void) const
{
	std::cout << "first name     : " << m_name << '\n';
	std::cout << "last name      : " << m_lastName << '\n';
	std::cout << "nickname       : " << m_nickname << '\n';
	std::cout << "phone number   : " << m_phoneNumber << '\n';
	std::cout << "darkest secret : " << m_secret << std::endl;
}
