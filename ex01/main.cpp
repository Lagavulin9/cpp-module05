/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:48:34 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 17:43:42 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	try
	{
		Bureaucrat A("Gorbachev", 1);
		std::cout << A << std::endl;
		Bureaucrat B("Shcherbina", 2);
		std::cout << B << std::endl;
		Form C("chernobyl", 1, 1);
		std::cout << C << std::endl;
		A.signForm(C);
		std::cout << C << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
