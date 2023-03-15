/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:31:31 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/01 20:50:28 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm::AForm("ShrubberyCreationForm", \
				ShrubberyCreationForm::SIGN_GRADE, \
				ShrubberyCreationForm::EXEC_GRADE, \
				"Default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm::AForm("ShrubberyCreationForm", \
				ShrubberyCreationForm::SIGN_GRADE, \
				ShrubberyCreationForm::EXEC_GRADE, \
				target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref):
	AForm::AForm(ref._name, \
				ShrubberyCreationForm::SIGN_GRADE, \
				ShrubberyCreationForm::EXEC_GRADE, \
				ref._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	new	(this)(ShrubberyCreationForm)(ref);

	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{

	if (this->_signed == false)
		throw AForm::AFormUnauthorizedException();
	if (this->_execGrade < executer.getGrade())
		throw AForm::AFormExcuteGradeException();
	
	std::string	file_name = this->_target;
	file_name.append("_shrubbery");
	
	std::ofstream file(file_name);
	file << "       _-_ ;
    /~~   ~~\
 /~~         ~~\
{               }
 \\  _-     -_  /
   ~  \\ //  ~
_- -   | | _- _
  _ -  | |   -_
      // \\ ";
	file.close();
}
