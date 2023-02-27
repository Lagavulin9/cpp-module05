/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:03:31 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 22:03:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
private:
	const std::string&	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
public:
	Form();
	Form(const std::string&);
	Form(const std::string&, int, int);
	Form(const Form&);
	~Form();

	Form&	operator=(const Form&);

	void				beSigned(const Bureaucrat&);
	const std::string&	getName(void) const;
	bool				getSigned(void) const;
	const int			getSignGrade(void) const;
	const int			getExecGrade(void) const;

	class FormGradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class FormGradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& ref);

#endif
