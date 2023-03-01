/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:31:31 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/01 20:50:28 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm::AForm("Default name", \
				RobotomyRequestForm::SIGN_GRADE, \
				RobotomyRequestForm::EXEC_GRADE, \
				"Default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name, const std::string& target):
	AForm::AForm(name, \
				RobotomyRequestForm::SIGN_GRADE, \
				RobotomyRequestForm::EXEC_GRADE, \
				target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref):
	AForm::AForm(ref.getName(), \
				RobotomyRequestForm::SIGN_GRADE, \
				RobotomyRequestForm::EXEC_GRADE, \
				ref.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	new	(this)(RobotomyRequestForm)(ref);

	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executer) const
{
	struct timeval	now;

	if (this->getSigned() == false)
		throw AForm::AFormUnauthorizedException();
	if (this->getExecGrade() < executer.getGrade())
		throw AForm::AFormExcuteGradeException();
	gettimeofday(&now, 0);
	if (now.tv_usec % 2)
		std::cout << this->getTarget() << " has been successfully robotomized." << std::endl;
	else
		std::cout << "failed to robotomize " << this->getTarget() << std::endl;
}
