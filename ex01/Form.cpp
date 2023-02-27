/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:03:41 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 22:03:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form():
	_name("Default Form"),
	_signed(false),
	_signGrade(150),
	_execGrade(150)
{
}

Form::Form(const std::string& name):
	_name(name),
	_signed(false),
	_signGrade(150),
	_execGrade(150)
{
}

Form::Form(const std::string& name, int signGrade, int execGrade):
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::FormGradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::FormGradeTooLowException();
}

Form::Form(const Form& ref):
	_name(ref.getName()),
	_signed(ref.getSigned()),
	_signGrade(ref.getSignGrade()),
	_execGrade(ref.getExecGrade())
{	
}

Form::~Form()
{
}

Form&	Form::operator=(const Form& ref)
{
	new	(this)(Form)(ref);

	return (*this);
}

void	Form::beSigned(const Bureaucrat& bureaurocrat)
{
	if (bureaurocrat.getGrade() > this->_signGrade)
	{
		std::cout << bureaurocrat.getName() << " couldn't sign " \
				<< this->_name << " because ";
		throw Form::FormGradeTooLowException();
	}
	this->_signed = true;
}

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

const int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

const int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

const char*	Form::FormGradeTooHighException::what() const throw()
{
	return "Form: Grade Too High";
}

const char*	Form::FormGradeTooLowException::what() const throw()
{
	return "Form: Grade Too Low";
}

std::ostream& operator<<(std::ostream& os, const Form& ref)
{
	os << ref.getName() << std::boolalpha \
		<< ", signed: " << ref.getSigned() \
		<< ", signGrade: " << ref.getSignGrade() \
		<< ", execGrade: " << ref.getExecGrade();
	return (os);
}
