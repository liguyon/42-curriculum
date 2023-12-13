/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 14:38:57 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact
{
public:
	Contact();
	Contact(int id);
	void displayInList(void) const;
	void print(void) const;

private:
	int			m_id;
	std::string m_name;
	std::string m_lastName;
	std::string m_nickname;
	std::string m_phoneNumber;
	std::string m_secret;
};
