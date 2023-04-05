/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:32:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 20:24:27 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
  public:
	Brain(void);
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	~Brain(void);

	void               setIdea(const int &id, const std::string &idea);
	const std::string &getIdea(const int &id) const;

  private:
	std::string ideas[100];
};

#endif /* BRAIN_HPP */
