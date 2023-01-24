/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/20 12:17:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::set_id(int new_id)
{
	this->id = new_id;
}

int PhoneBook::get_id(void)
{
	return (this->id);
}
