/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:54 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/13 14:46:09 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include "Phonebook.h"
#include <iostream>
#include <string>

int	main()
{
	Phonebook pb;
	
	while (pb.getIsRunning())
	{
		std::cout << "\nEnter a command:\n";
		std::string command;
		std::cin >> command;
		
		if (!command.compare("EXIT"))
			pb.exit();
		else if (!command.compare("ADD"))
			pb.add();
		else if (!command.compare("SEARCH"))
			pb.search();
		else
			std::cout << "The command is invalid. Please try again.\n\n";
	}
	return 0;
}
