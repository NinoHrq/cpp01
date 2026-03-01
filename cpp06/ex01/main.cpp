/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:42:58 by marvin            #+#    #+#             */
/*   Updated: 2026/03/01 17:42:59 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

#include <iostream>

int main(void)
{
    Data data;
    data.id = 345;
    data.name = "Bob";
    data.active = true;

    Data* p = &data;

    uintptr_t raw = Serializer::serialize(p);
	Data *q = Serializer::deserialize(raw);

    if (q == p)
    {
        std::cout << "Original pointer: " << p << std::endl;
        std::cout << "Serialized value: " << raw << std::endl;
        std::cout << "Deserialized pointer: " << q << std::endl;
    }
    else
    {
        std::cout << "Error: pointers differ" << std::endl;
    }
	return (0);
}