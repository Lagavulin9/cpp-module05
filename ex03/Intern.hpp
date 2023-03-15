/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinholee <jinholee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:02:33 by jinholee          #+#    #+#             */
/*   Updated: 2023/03/15 17:41:54 by jinholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_HPP__
# define __INTERN_HPP__

class Intern
{
private:

public:
	Intern();
	Intern(const Intern&);
	~Intern();

	Intern&	operator=(const Intern&)
};

#endif
