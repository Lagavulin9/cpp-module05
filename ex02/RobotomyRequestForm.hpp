/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:15:40 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/01 20:46:39 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <sys/time.h>

class RobotomyRequestForm : public AForm
{
protected:
	static const int	SIGN_GRADE = 72;
	static const int	EXEC_GRADE = 45;
private:
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string&, const std::string&);
	RobotomyRequestForm(const RobotomyRequestForm&);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

	void	execute(const Bureaucrat&) const;
};

#endif
