/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:48:34 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 01:48:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	try
	{
		Bureaucrat A("Gorbachev", 1);
		Form B("chernobyl", 1, 1);
		std::cout << B << std::endl;
		A.signForm(B);
		std::cout << B << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
