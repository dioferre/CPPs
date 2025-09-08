/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:13:09 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/08 10:24:54 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include "stdint.h"

int	main(void)
{
	Data *d = new Data();

	d->status = true;
	d->num = 42;
	d->text.resize(12);
	d->text = "Hello world!";

	uintptr_t serializedData = Serializer::serialize(d);
	Data *d2 = Serializer::deserialize(serializedData);

	std::cout << "Original Data:" << std::endl;
	std::cout << "text: " << d->text << std::endl;
	std::cout << "status: " << (d->status ? "true" : "false") << std::endl;
	std::cout << "number: " << d->num << std::endl;

	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "text: " << d2->text << std::endl;
	std::cout << "status: " << (d2->status ? "true" : "false") << std::endl;
	std::cout << "number: " << d2->num << std::endl;

	delete d;
	d2 = NULL;
	
	return (0);
}