/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:31:31 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/01 21:38:57 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm::AForm("Default name", \
				PresidentialPardonForm::SIGN_GRADE, \
				PresidentialPardonForm::EXEC_GRADE, \
				"Default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, const std::string& target):
	AForm::AForm(name, \
				PresidentialPardonForm::SIGN_GRADE, \
				PresidentialPardonForm::EXEC_GRADE, \
				target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref):
	AForm::AForm(ref.getName(), \
				PresidentialPardonForm::SIGN_GRADE, \
				PresidentialPardonForm::EXEC_GRADE, \
				ref.getTarget())
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
	if (this->getSigned() == false)
		throw AForm::AFormUnauthorizedException();
	if (this->getExecGrade() < executer.getGrade())
		throw AForm::AFormExcuteGradeException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
