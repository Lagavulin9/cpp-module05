/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:00:48 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 17:05:49 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
	_name("Default name"),
	_grade(Bureaucrat::DEFAULT_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string& name):
	_name(name),
	_grade(Bureaucrat::DEFAULT_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade):
	_name(name),
	_grade(grade)
{
	if (this->_grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > Bureaucrat::MIN_GRADE)
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
	if (this->_grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::incrementGrade(int amount)
{
	this->_grade -= amount;
	if (this->_grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade += 1;
	if (this->_grade > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decrementGrade(int amount)
{
	this->_grade += amount;
	if (this->_grade > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return (os);
}
