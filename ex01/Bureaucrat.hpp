/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:30:28 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 16:30:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat {
private:
	const std::string&	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string&);
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat&);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat&);

	const std::string&	getName(void) const;
	void				incrementGrade(void);
	void				incrementGrade(int);
	void				decrementGrade(void);
	void				decrementGrade(int);
	int					getGrade(void) const;
	void				signForm(Form&) const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& ref);

#endif
