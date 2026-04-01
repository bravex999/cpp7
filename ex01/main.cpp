/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:37:15 by chnaranj          #+#    #+#             */
/*   Updated: 2026/04/01 16:37:17 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

template <typename T>
void print_element(T & element)
{
	std::cout << element << " ";
}

template <typename T>
void print_const_element(const T & element)
{
	std::cout << element << " ";
}

template <typename T>
void increment(T & element)
{
	element++;
}

int main()
{
	int int_arr[] = {1, 2, 3, 4, 5};
	std::string str_arr[] = {"uno", "dos", "tres"};

	std::cout << "Int array: ";
	::iter(int_arr, 5, print_element<int>);
	std::cout << std::endl;

	std::cout << "String array: ";
	::iter(str_arr, 3, print_element<std::string>);
	std::cout << std::endl;

	const int const_arr[] = {10, 20, 30};
	std::cout << "Const int array: ";
	::iter(const_arr, 3, print_const_element<int>);
	std::cout << std::endl;

	std::cout << "Before increment: ";
	::iter(int_arr, 5, print_element<int>);
	std::cout << std::endl;
	::iter(int_arr, 5, increment<int>);
	std::cout << "After increment: ";
	::iter(int_arr, 5, print_element<int>);
	std::cout << std::endl;

	return 0;
}
