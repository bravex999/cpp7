/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:37:49 by chnaranj          #+#    #+#             */
/*   Updated: 2026/04/01 16:37:51 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
private:
	T * _elements;
	unsigned int _n;

public:
	Array() : _elements(NULL), _n(0)
	{
	}

	Array(unsigned int n) : _n(n)
	{
		_elements = new T[n]();
	}

	Array(const Array & other) : _elements(NULL), _n(0)
	{
		*this = other;
	}

	Array & operator=(const Array & other)
	{
		if (this != &other)
		{
			if (_elements)
			{
				delete[] _elements;
			}
			_n = other._n;
			if (_n > 0)
			{
				_elements = new T[_n];
				for (unsigned int i = 0; i < _n; i++)
				{
					_elements[i] = other._elements[i];
				}
			}
			else
			{
				_elements = NULL;
			}
		}
		return *this;
	}

	~Array()
	{
		if (_elements)
		{
			delete[] _elements;
		}
	}

	T & operator[](unsigned int index)
	{
		if (index >= _n)
		{
			throw std::exception();
		}
		return _elements[index];
	}

	const T & operator[](unsigned int index) const
	{
		if (index >= _n)
		{
			throw std::exception();
		}
		return _elements[index];
	}

	unsigned int size() const
	{
		return _n;
	}
};

#endif
