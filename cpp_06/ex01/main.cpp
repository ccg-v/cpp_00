/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 00:03:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 01:32:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {

	Data		data_struct;
	Data*		ptrToData;
	uintptr_t	raw;	

	data_struct.str = "Hi";
	data_struct.num = 42;
	ptrToData = &data_struct;
	
	std::cout << "/* ---- Initial values ------------------- */\n" << std::endl;

	std::cout << "\tPointer to data is " << ptrToData << std::endl;
	std::cout << "\tValues stored in data and their addresses are:\n" 
			  << "\t - " << data_struct.num << " | " << &data_struct.num << "\n" 
			  << "\t - " << data_struct.str << " | " << &data_struct.str << "\n"
			  << std::endl;

	std::cout << "/* ---- After serializing... ------------- */\n" << std::endl;

	raw = Serializer::serialize(ptrToData);
	std::cout << "\tAddress is " << raw << "\n" << std::endl;

	std::cout << "/* ---- After deserializing... ----------- */\n" << std::endl;
		
	ptrToData = Serializer::deserialize(raw);
	std::cout << "\tPointer to data is " << ptrToData << std::endl;
	std::cout << "\tValues stored in data and their addresses are:\n" 
			  << "\t - " << data_struct.num << " | " << &data_struct.num << "\n" 
			  << "\t - " << data_struct.str << " | " << &data_struct.str << "\n"
			  << std::endl;
	
	return 0;
}