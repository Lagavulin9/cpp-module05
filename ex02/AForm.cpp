/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:03:41 by marvin            #+#    #+#             */
/*   Updated: 2023/03/15 17:49:34 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm():
	_name("Default AForm"),
	_signed(false),
	_signGrade(AForm::DEFAULT_SIGN_GRADE),
	_execGrade(AForm::DEFAULT_EXEC_GRADE),
	_target("Default Target")
{
}

AForm::AForm(const std::string& name, const std::string& target):
	_name(name),
	_signed(false),
	_signGrade(AForm::DEFAULT_SIGN_GRADE),
	_execGrade(AForm::DEFAULT_EXEC_GRADE),
	_target(target)
{
}

AForm::AForm(const std::string& name, int signGrade, int execGrade, const std::string& target):
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade),
	_target(target)
{
	if (this->_signGrade < AForm::MAX_GRADE)
		throw AForm::AFormGradeTooHighException();
	if (this->_signGrade > AForm::MIN_GRADE)
		throw AForm::AFormGradeTooLowException();
}

AForm::AForm(const AForm& ref):
	_name(ref._name),
	_signed(ref._signed),
	_signGrade(ref._signGrade),
	_execGrade(ref._execGrade)
{	
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(const AForm& ref)
{
	(void)ref;

	return (*this);
}

void	AForm::beSigned(const Bureaucrat& bureaurocrat)
{
	if (bureaurocrat.getGrade() > this->_signGrade)
	{
		std::cout << bureaurocrat.getName() << " couldn't sign " \
				<< this->_name << " because ";
		throw AForm::AFormGradeTooLowException();
	}
	this->_signed = true;
}

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

const std::string&	AForm::getTarget(void) const
{
	return (this->_target);
}

const char*	AForm::AFormGradeTooHighException::what() const throw()
{
	return "Form: Grade Too High";
}

const char*	AForm::AFormGradeTooLowException::what() const throw()
{
	return "Form: Grade Too Low";
}

const char*	AForm::AFormUnauthorizedException::what() const throw()
{
	return "Form: Unsigned Form";
}

const char*	AForm::AFormExcuteGradeException::what() const throw()
{
	return "Form: Grade Too Low to Execute";
}

std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
	os << "Form name: " << ref.getName() \
		<< ", signed: " << std::boolalpha << ref.getSigned() \
		<< ", signGrade: " << ref.getSignGrade() \
		<< ", execGrade: " << ref.getExecGrade();
	return (os);
}
