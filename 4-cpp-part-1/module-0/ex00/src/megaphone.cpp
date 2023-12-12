/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:38:11 by liguyon           #+#    #+#             */
/*   Updated: 2023/12/12 11:07:27 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	print_capitalized(const std::string str)
{
	int len = str.length();
	for (int i = 0 ; i < len ; ++i)
		std::cout << static_cast<unsigned char>(std::toupper(str[i]));
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1 ; i < argc ; ++i)
		{
			std::string str = argv[i];
			print_capitalized(str);
		}
	}

	std::cout << '\n';

	return 0;
}