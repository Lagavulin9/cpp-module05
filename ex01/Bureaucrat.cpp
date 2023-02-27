/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:00:48 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 20:00:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():
	_name("Default name"),
	_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name):
	_name(name),
	_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade):
	_name(name),
	_grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref):
	_name(ref.getName()),
	_grade(ref.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref)
{
	new	(this)(Bureaucrat)(ref);

	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::incrementGrade(int amount)
{
	this->_grade -= amount;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decrementGrade(int amount)
{
	this->_grade += amount;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(Form& form) const
{
	form.beSigned(*this);
	std::cout << this->_name << " signed " << form.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: Grade Too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: Grade Too Low";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return (os);
}
