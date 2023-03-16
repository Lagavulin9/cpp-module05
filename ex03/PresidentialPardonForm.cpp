/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:31:31 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/15 17:53:43 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm::AForm("PresidentialPardonForm", \
				PresidentialPardonForm::SIGN_GRADE, \
				PresidentialPardonForm::EXEC_GRADE, \
				"Default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm::AForm("PresidentialPardonForm", \
				PresidentialPardonForm::SIGN_GRADE, \
				PresidentialPardonForm::EXEC_GRADE, \
				target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref):
	AForm::AForm(ref._name, \
				PresidentialPardonForm::SIGN_GRADE, \
				PresidentialPardonForm::EXEC_GRADE, \
				ref._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	new	(this)(PresidentialPardonForm)(ref);

	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executer) const
{
	if (this->_signed == false)
		throw AForm::AFormUnauthorizedException();
	if (this->_execGrade < executer.getGrade())
		throw AForm::AFormExcuteGradeException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
