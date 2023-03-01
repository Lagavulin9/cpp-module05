/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:03:31 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 21:35:05 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AFORM_HPP__
# define __AFORM_HPP__

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm {
protected:
	static const int	MAX_GRADE = 1;
	static const int	MIN_GRADE = 150;
	static const int	DEFAULT_SIGN_GRADE = MIN_GRADE;
	static const int	DEFAULT_EXEC_GRADE = MIN_GRADE;
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
	const std::string	_target;
	
	AForm&	operator=(const AForm&);
public:
	AForm();
	AForm(const std::string&, const std::string&);
	AForm(const std::string&, int, int, const std::string&);
	AForm(const AForm&);
	~AForm();

	void				beSigned(const Bureaucrat&);
	const std::string&	getName(void) const;
	bool				getSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	const std::string&	getTarget(void) const;
	virtual void		execute(Bureaucrat const&) const = 0;

	class AFormGradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class AFormGradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class AFormUnauthorizedException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class AFormExcuteGradeException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif
