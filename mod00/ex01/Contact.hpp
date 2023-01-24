/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:01:22 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/24 15:39:21 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
  private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

  public:
	void        setFirstName(std::string first_name);
	std::string getFirstName(void);
	void        setLastName(std::string last_name);
	std::string getLastName(void);
	void        setNickname(std::string nickname);
	std::string getNickname(void);
	void        setPhoneNumber(std::string phone_number);
	std::string getPhoneNumber(void);
	void        setDarkestSecret(std::string darkest_secret);
	std::string getDarkestSecret(void);
	bool        isCompleted(void);
};

#endif
