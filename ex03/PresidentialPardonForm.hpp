/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:15:40 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/15 17:53:57 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
protected:
	static const int	SIGN_GRADE = 25;
	static const int	EXEC_GRADE = 5;
private:
	
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string&);
	PresidentialPardonForm(const PresidentialPardonForm&);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

	void	execute(const Bureaucrat&) const;
}; 

#endif
