/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2023/03/15 17:41:58 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/15 17:45:17 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& ref)
{
	(void) ref;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& ref)
{
	(void) ref;
	return (*this);
}

AForm*	Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string	formNames[3] = {"schrubbery creation", \
								"robotomy request", \
								"presidential pardon"};
	AForm*	(Intern::*func_ptr[3])(std::string) = {&Intern::makeShrubberyCreationForm, \
													&Intern::makeRobotomyRequestForm, \
													&Intern::makePresidentialPardonForm};

	for (int i=0; i<3; i++)
	{
		if (name.compare(formNames[i]) == 0)
			return ((this->*func_ptr[i])(target));
	}
	throw Intern::InvalidFormNameException();
}

const char* Intern::InvalidFormNameException::what() const throw()
{
	return "Invalid Form Name.\n";
}
