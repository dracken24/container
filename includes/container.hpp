/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:57:08 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/07 18:42:53 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// For the sake of the project, I'm including all the files here.

// Functions //
#include "functions/isIntegral.hpp"
#include "functions/pair.hpp"

// Containers //
#include "templates/iterator.hpp"
#include "templates/vector.hpp"
#include "templates/stack.hpp"
#include "templates/map.hpp"

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
#include <cstddef>
#include <iterator>
#include <memory>
#include <map>
#include <cstdio>

// Class tests //

typedef struct Vector2
{
	int x;
	int y;
}	Vector2;

class A
{
	public:
		A(void) : _nbr(0), _str("")
		{
			this->_vec = (Vector2){0, 0};
		}

		A(std::string str, int nbr, Vector2 vec) : _nbr(nbr), _str(str)
		{
			this->_vec = vec;
		}
		
		A(const A &src) : _nbr(src._nbr), _vec(src._vec), _str(src._str)
		{
			*this = src;
		}

		~A(void) {}

		A &operator=(const A &rhs)
		{
			_nbr = rhs._nbr;
			_vec = rhs._vec;
			_str = rhs._str;
			return *this;
		}
		
		void setNbr(int nbr)
		{
			_nbr = nbr;
		}
		
		void setVec(Vector2 vec)
		{
			_vec = vec;
		}

		std::string getStr(void) const
		{
			return _str;
		}

		int getNbr(void) const
		{
			return _nbr;
		}

		int getVecX(void) const
		{
			return _vec.x;
		}

		int getVecY(void) const
		{
			return _vec.y;
		}

	public:
		int 		_nbr;
		Vector2		_vec;
		std::string _str;
};


struct StructA
{
	std::string	_str;
	int			_nbr;
	Vector2		_vec;

	StructA(void) : _str(""), _nbr(0), _vec((Vector2){0, 0}) {}

	StructA(std::string str, int nbr, Vector2 vec) : _str(str), _nbr(nbr)
	{
		this->_vec = vec;
	}
	
	StructA(const StructA &src) : _str(src._str), _nbr(src._nbr), _vec(src._vec) {}

	~StructA(void) {}
	
	StructA &operator=(const StructA &rhs)
	{
		_str = rhs._str;
		_nbr = rhs._nbr;
		return *this;
	}
};

//*** Functions ***//

// Choose Tests type //
void	chooseVectorTests(void);

// rendomAccessIterator Tests //
void    randomAccessIteratorTestDouble(void);
void	randomAccessIteratorTestClass(void);
void    randomAccessIteratorTestInt(void);

// Vector Tests //
void	vectorTestStruct(void);
void	vectorTestString(void);
void	vectorTestDouble(void);
void	vectorTestClass(void);
void	vectorTestint(void);

// Stack Tests //
void    stackStructTest(void);
void    stackClassTest(void);
void    stackFloatTest(void);
void    stackIntTest(void);

// Map Tests //
void	mapTestString();
void	mapTestClass();
void	mapTestInt();
