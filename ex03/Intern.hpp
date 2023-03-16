/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:02:33 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/16 22:14:00 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <string>

class Intern
{
private:
	static const std::string	_formNames[3] = {"1", "2", "3"};
public:
	Intern();
	Intern(const Intern&);
	~Intern();

	Intern&	operator=(const Intern&);
};

#endif
