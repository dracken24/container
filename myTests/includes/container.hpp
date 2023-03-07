/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:57:08 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/06 20:25:43 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_HPP
# define CONTAINER_HPP

// For the sake of the project, I'm including all the files here.

// Functions //
#include "../../includes/functions/isIntegral.hpp"
#include "../../includes/templates/mapIterator.hpp"
#include "../../includes/templates/iterator.hpp"
#include "../../includes/functions/utils.hpp"
#include "../../includes/functions/pair.hpp"

// Containers //
#include "../../includes/templates/vector.hpp"
// #include "../../includes/templates/stack.hpp"
#include "../../includes/templates/map.hpp"

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
#include <random>
#include <sys/time.h>

// Class tests //

typedef struct Vector2
{
	int x;
	int y;
}	Vector2;

class A
{
	public:
	// Constructors & Destructors //
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

	// Operators //
		A &operator=(const A &rhs)
		{
			_nbr = rhs._nbr;
			_vec = rhs._vec;
			_str = rhs._str;
			return *this;
		}

		bool	operator>(A const &src) const
		{
			if (this->_nbr > src._nbr)
				return (true);

			return (false);
		}

		bool	operator<(A const &src) const
		{
			if (this->_nbr < src._nbr)
				return (true);

			return (false);
		}

		bool	operator>=(A const &src) const
		{
			if (this->_nbr >= src._nbr)
				return (true);

			return (false);
		}

		bool	operator<=(A const &src) const
		{
			if (this->_nbr <= src._nbr)
				return (true);

			return (false);
		}

		bool	operator==(A const &src) const
		{
			if (this->_nbr == src._nbr)
				return (true);

			return (false);
		}

		bool	operator!=(A const &src) const
		{
			if (this->_nbr != src._nbr)
				return (true);

			return (false);
		}
		
	// Setters //
		void setNbr(int nbr)
		{
			_nbr = nbr;
		}
		
		void setVec(Vector2 vec)
		{
			_vec = vec;
		}
	// Getters //
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

	bool	operator>(StructA const &src) const
	{
		if (this->_nbr > src._nbr)
			return (true);

		return (false);
	}

	bool	operator<(StructA const &src) const
	{
		if (this->_nbr < src._nbr)
			return (true);

		return (false);
	}

	bool	operator>=(StructA const &src) const
	{
		if (this->_nbr >= src._nbr)
			return (true);

		return (false);
	}

	bool	operator<=(StructA const &src) const
	{
		if (this->_nbr <= src._nbr)
			return (true);

		return (false);
	}

	bool	operator==(StructA const &src) const
	{
		if (this->_nbr == src._nbr)
			return (true);

		return (false);
	}

	bool	operator!=(StructA const &src) const
	{
		if (this->_nbr != src._nbr)
			return (true);

		return (false);
	}
};

template<typename T>
std::ostream	&operator<<(std::ostream &out, const ft::is_integral<T> &src)
{
	out << src.value;
	
	return out;
}

template<typename T, typename U>
std::ostream	&operator<<(std::ostream &out, const ft::is_same<T, U> &src)
{
	out << src.value;

	return out;
}

template<typename T>
std::ostream	&operator<<(std::ostream &out, const ft::is_same<T, T> &src)
{
	out << src.value;
	
	return out;
}

//*** Functions ***//

// Choose Tests type //
void	chooseVectorTests(int flag);

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
void	mapTestString(void);
void	mapTestStruct(void);
void	mapTestClass(void);
void	mapTestInt(void);

// TimeOut //
void	vectorTimeOutTestInt(void);
void    chooseStackTestsInt(void);
void	chooseMapTestsInt(void);

// OneByOne //
void	is_integralTests(void);
void	enable_ifTests(void);
void	iteratorsTests(void);
void	is_sameTests(void);
void	lexicoTests(void);
void	pairTests(void);

#endif
