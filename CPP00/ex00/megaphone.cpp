/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:04:32 by lukan             #+#    #+#             */
/*   Updated: 2025/04/08 15:20:19 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char** argv)
{
	int		i;
	int		j = 1;
	char	c;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while(argv[j])
	{
		i = 0;
		while(argv[j][i])
		{
			c = std::toupper(argv[j][i]);
			std::cout << c;
			i++;
		}
		std::cout << ' ';
		j++;
	}
	std::cout << "\n";
	return(0);
}