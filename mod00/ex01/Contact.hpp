/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:01:22 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/24 14:31:28 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
  private:
	char *_first_name;
	char *_last_name;
	char *_nickname;
	char *_phone_number;
	char *_darkest_secret;

  public:
	Contact();
	~Contact();
	void  setFirstName(char *first_name);
	char *getFirstName(void);
	void  setLastName(char *last_name);
	char *getLastName(void);
	void  setNickname(char *nickname);
	char *getNickname(void);
	void  setPhoneNumber(char *phone_number);
	char *getPhoneNumber(void);
	void  setDarkestSecret(char *darkest_secret);
	char *getDarkestSecret(void);
};

#endif
