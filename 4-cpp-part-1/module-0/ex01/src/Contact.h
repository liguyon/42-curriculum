/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/12 11:55:30 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact
{
public:
	void print(void) const;

private:

	std::string m_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone_nbr;
	std::string m_secret;

};