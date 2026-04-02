/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:37:28 by chnaranj          #+#    #+#             */
/*   Updated: 2026/04/01 16:37:29 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try
    {
        empty[0] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Empty array access: " << e.what() << '\n';
    }

    
    Array<int> original(3);
    original[0] = 100;
    original[1] = 200;
    original[2] = 300;
    Array<int> copy(original);
    copy[0] = 999;
    std::cout << "Original[0]: " << original[0] << ", Copy[0]: " << copy[0] << std::endl;

    // Test with different types
    std::cout << "\n--- Multi-type tests ---" << std::endl;

    Array<float> floats(3);
    floats[0] = 1.1f;
    floats[1] = 2.2f;
    floats[2] = 3.3f;
    std::cout << "Float: " << floats[0] << " " << floats[1] << " " << floats[2] << std::endl;

    Array<std::string> strs(2);
    strs[0] = "hello";
    strs[1] = "world";
    std::cout << "String: " << strs[0] << " " << strs[1] << std::endl;

    Array<char> chars(3);
    chars[0] = 'A';
    chars[1] = 'B';
    chars[2] = 'C';
    std::cout << "Char: " << chars[0] << " " << chars[1] << " " << chars[2] << std::endl;
    delete [] mirror;
    return 0;
}
