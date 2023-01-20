/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:57:08 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/19 21:01:27 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_HPP
# define CONTAINER_HPP

// For the sake of the project, I'm including all the files here.

// Functions //
#include "functions/lexicographicalCompare.hpp"
#include "functions/isIntegral.hpp"
#include "functions/enableIf.hpp"
#include "functions/equal.hpp"
#include "functions/pair.hpp"

// Containers //
#include "templates/Iterator.hpp"
#include "templates/Vector.hpp"
#include "templates/Stack.hpp"
#include "templates/Map.hpp"

// Tree //
# include "tree/rbTree.hpp"

// Other //

#include "color.hpp"

// std Library //

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <assert.h>
#include <vector>
#include <cstddef>
#include <iterator>
#include <memory>

// Class tests //

// template <typename T>
class A
{
	public:
		A(void) : _nbr(0) {}
		
		A(const A &src) : _nbr(src._nbr) 
		{
			*this = src;
		}

		~A(void) {}

		A &operator=(const A &rhs)
		{
			(void)rhs;
			return *this;
		}
		
		void setNbr(int nbr)
		{
			_nbr = nbr;
		}

		int getNbr(void) const
		{
			return _nbr;
		}
	// Operators Overload //
		A	&operator++(void)
		{
			_nbr++;
			return *this;
		}

		A	operator++(int)
		{
			A tmp(*this);
			operator++();
			return tmp;
		}
		
		A	&operator--(void)
		{
			_nbr--;
			return *this;
		}

		A	operator--(int)
		{
			A tmp(*this);
			operator--();
			return tmp;
		}

		A	&operator+=(const A &rhs)
		{
			_nbr += rhs._nbr;
			return *this;
		}

		A	&operator-=(const A &rhs)
		{
			_nbr -= rhs._nbr;
			return *this;
		}

		A	&operator*=(const A &rhs)
		{
			_nbr *= rhs._nbr;
			return *this;
		}

		A	&operator/=(const A &rhs)
		{
			_nbr /= rhs._nbr;
			return *this;
		}

	private:
		int _nbr;
};

template <typename T>
class B
{
	public:
		B(void) : _nbr(0) {}
		
		B(const B &src) : _nbr(src._nbr) 
		{
			*this = src;
		}
		
		~B(void) {}
		
		B &operator=(const B &rhs)
		{
			(void)rhs;
			return *this;
		}

		void setNbr(int nbr)
		{
			_nbr = nbr;
		}

		int getNbr(void) const
		{
			return _nbr;
		}
	
	private:
		int _nbr;
};

// template <typename T>
struct StructA
{
	// typedef T     value_type;
	
	std::string	_str;
	int			_nbr;
	// value_type	_val;

	StructA(void) : _str(""), _nbr(0) {}

	StructA(std::string str, int nbr) : _str(str), _nbr(nbr) {}
	
	StructA(const StructA &src) : _str(src._str), _nbr(src._nbr) {}

	~StructA(void) {}
	
	StructA &operator=(const StructA &rhs)
	{
		_str = rhs._str;
		_nbr = rhs._nbr;
		// _val = rhs._val;
		return *this;
	}
};

template <typename T>
struct StructB
{
	typedef T     value_type;
	
	std::string	_str;
	int			_nbr;
	value_type	_val;

	StructB(void) : _str(""), _nbr(0), _val(0) {}

	StructB(std::string str, int nbr) : _str(str), _nbr(nbr), _val(0) {}
	
	StructB(const StructB &src) : _str(src._str), _nbr(src._nbr), _val(src._val) {}

	~StructB(void) {}
	
	StructB &operator=(const StructB &rhs)
	{
		_str = rhs._str;
		_nbr = rhs._nbr;
		_val = rhs._val;
		return *this;
	}
};

//*** Functions ***//

void	randomAccessIteratorTestClass(void);
void    randomAccessIteratorTestInt(void);

void	chooseVectorTests(void);
void	reverseIteratorTest(void);

void	vectorTest(void);

#endif
