/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:19:31 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/14 16:34:33 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	
	std::string* stringPTR = &brain;
	
	std::string& stringREF = brain;

	std::cout << "Memory address of the string:     " << &brain << '\n';
	std::cout << "Memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "Memory address held by stringREF: " << &stringREF << "\n\n";

	std::cout << "Value of the string:           " << brain << '\n';
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << "Value pointed to by stringREF: " << stringREF << '\n';

	return 0;
}