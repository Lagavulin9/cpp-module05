/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2023/03/01 22:02:33 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/16 22:14:00 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

class Intern
{
private:
	AForm	*makeShrubberyCreationForm(std::string target);
	AForm	*makeRobotomyRequestForm(std::string target);
	AForm	*makePresidentialPardonForm(std::string target);

	Intern(const Intern&);
	Intern&	operator=(const Intern&);
public:
	Intern();
	~Intern();

	AForm	*makeForm(std::string name, std::string target);

	class	InvalidFormNameException: public std::exception
	{
		const char* what() const throw();
	};
};

#endif
