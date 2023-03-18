/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:48:34 by marvin            #+#    #+#             */
/*   Updated: 2023/03/16 22:11:04 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{

	try
	{
		Bureaucrat	A("Ryo", 1);
		Intern 		B;

		AForm*	tree = B.makeForm("schrubbery creation", "bocchi");
		AForm*	robot = B.makeForm("robotomy request", "kita");
		AForm*	pardon = B.makeForm("presidential pardon", "nijika");

		A.signForm(*tree);
		A.signForm(*robot);
		A.signForm(*pardon);

		A.executeForm(*tree);
		A.executeForm(*robot);
		A.executeForm(*pardon);

		AForm*	wrongForm = B.makeForm("wrong form", "kikuri");
		A.signForm(*wrongForm);
		A.executeForm(*wrongForm);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
