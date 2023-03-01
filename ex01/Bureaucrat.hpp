/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:30:28 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 17:32:51 by jinholee         ###   ########.fr       */
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
protected:
	static const int			MAX_GRADE = 1;
	static const int			MIN_GRADE = 150;
	static const int			DEFAULT_GRADE = MIN_GRADE;
private:
	const std::string	_name;
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
	void				signForm(Form&);

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
