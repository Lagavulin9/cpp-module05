/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:48:34 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 22:07:38 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{

	try
	{
		Bureaucrat A("Gorbachev", 1);
		std::cout << A << std::endl;

		ShrubberyCreationForm B("123");
		RobotomyRequestForm C("Bocchi");
		PresidentialPardonForm D("Bogon");
		
		A.signForm(B);
		A.signForm(C);
		A.signForm(D);

		A.executeForm(B);
		A.executeForm(C);
		A.executeForm(D);

		Bureaucrat E("some office worker", 50);
		ShrubberyCreationForm F("qwe");
		
		E.executeForm(F);
		E.executeForm(C);

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
