/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:41:45 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 17:06:50 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat A("Borris", 150);
		std::cout << A << std::endl;
		A.incrementGrade();
		std::cout << A << std::endl;
		A.decrementGrade();
		std::cout << A << std::endl;
		A.decrementGrade();
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
