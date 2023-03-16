/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:15:40 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/01 20:46:39 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
protected:
	static const int	SIGN_GRADE = 145;
	static const int	EXEC_GRADE = 137;
private:
	
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string&);
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);

	void	execute(const Bureaucrat&) const;
};

#endif
