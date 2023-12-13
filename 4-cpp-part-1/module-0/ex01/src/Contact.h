/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 05:01:33 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact
{
public:
	void print(void) const;

private:

	const std::string m_name;
	const std::string m_lastName;
	const std::string m_nickname;
	const std::string m_phoneNumber;
	const std::string m_secret;

};
