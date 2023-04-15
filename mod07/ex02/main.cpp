/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:11:20 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 12:19:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int>   obj1(1);
	Array<char>  obj2(2);
	Array<float> obj3(3);

	obj1[0] = 1;

	obj2[0] = '4';
	obj2[1] = '2';

	obj3[0] = 1.1f;
	obj3[1] = 2.2f;
	obj3[2] = 3.3f;

	std::cout << "int" << std::endl;
	std::cout << obj1[0] << std::endl;

	std::cout << "char" << std::endl;
	std::cout << obj2[0] << std::endl;
	std::cout << obj2[1] << std::endl;

	std::cout << "float" << std::endl;
	std::cout << obj3[0] << std::endl;
	std::cout << obj3[1] << std::endl;
	std::cout << obj3[2] << std::endl;
}
