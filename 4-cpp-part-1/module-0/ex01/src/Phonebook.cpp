/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:57 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 18:21:17 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.h"
#include <iostream>
#include <limits>

int 	Phonebook::m_nbContacts = 0;
bool	Phonebook::m_contactsFilled = false;

Phonebook::Phonebook()
{
	std::cout << "Welcome to the awesome phonebook!\n\n";
	std::cout << "Usage:\n"
		ANSI_BOLD "ADD" ANSI_RESET "    save a new contact\n"
		ANSI_BOLD "SEARCH" ANSI_RESET " display a specific contact\n"
		ANSI_BOLD "EXIT" ANSI_RESET "   quit the program\n";
	m_isRunning = true;
}

void Phonebook::add()
{
	static int i = 0;

	m_contacts[i] = Contact(i);
	++i;
	if (!Phonebook::m_contactsFilled)
		++Phonebook::m_nbContacts;
	if (i > 7)
	{
		i = 0;
		Phonebook::m_contactsFilled = true;
	}
}

static void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Phonebook::m_askContactIndex() const
{
	while (true)
	{
		std::cout << "\nEnter the index of the entry to display:\n";
		int index;
		std::cin >> index;
		if (!std::cin || index < 0 || index >= Phonebook::m_nbContacts)
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid index. Please try again.\n";
		}
		else
		{
			ignoreLine();
			return index;
		}
	}
}

void Phonebook::search()
{
	if (Phonebook::m_nbContacts == 0)
		std::cout << "\nNo registered contact yet.\n";
	else
	{
		std::cout << "\nRegistered contacts:\n";
		for (int i = 0 ; i < Phonebook::m_nbContacts ; ++i)
			m_contacts[i].displayInList();
		int index = m_askContactIndex();
		m_contacts[index].print();
	}
}

void Phonebook::exit()
{
	std::cout << "\nGoodbye!\n";
	m_isRunning = false;
}

bool Phonebook::getIsRunning() const
{
	return m_isRunning;
}
