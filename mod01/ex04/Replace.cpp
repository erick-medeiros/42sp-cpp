/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:34:33 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/17 23:57:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

#include <iostream>

Replace::Replace(std::string &filename, std::string &search,
                 std::string &replace)
    : _filename(filename), _search(search), _replace(replace)
{
}

void Replace::run(void)
{
	std::ifstream input;
	std::ofstream output;
	std::string   match;
	char          c;
	size_t        i;

	if (_search.size() == 0)
		return;
	input.open(_filename.c_str());
	if (!input.is_open())
		throw std::string("Error opening: " + _filename);
	output.open(std::string(_filename + ".replace").c_str());
	if (!output.is_open())
	{
		input.close();
		throw std::string("Error opening output file");
	}
	match.clear();
	i = 0;
	while (input.get(c))
	{
		if (c != _search[i])
		{
			output << match;
			match.clear();
			i = 0;
		}
		if (c != _search[i])
			output << c;
		else
		{
			match += c;
			i++;
		}
		if (i == _search.size())
		{
			if (_search.compare(match) == 0)
				output << _replace;
			match.clear();
			i = 0;
		}
	}
	input.close();
	output.close();
}
