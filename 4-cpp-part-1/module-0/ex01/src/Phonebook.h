/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:59 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 15:22:44 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.h"

#define ANSI_BOLD "\e[1m"
#define ANSI_RESET "\e[0m"

class Phonebook
{
public:
	Phonebook();
	void add();
	void search();
	void exit();
	bool getIsRunning() const;

private:
	bool	m_isRunning;
	Contact	m_contacts[8];
	int		m_contactsCount;
	bool	m_contactsFilled;
	int 	askContactIndex() const;
};
