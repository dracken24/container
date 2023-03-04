/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:08:02 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/04 10:33:26 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//

		public:
			pair(void) : _first(), _second() {};
			pair(const T1 &src1, const T2 &src2) : _first(src1), _second(src2) {};
			pair(const pair<T1, T2> &copy) : _first(copy._first), _second(copy._second) {};
			
			template <typename U, typename V>
			pair(const pair<U, V> &copy) : _first(copy._first), _second(copy._second) {};

			~pair() {};

			pair    &operator=(const pair &src)
			{
				if (this != &src)
				{
					_first = src._first;
					_second = src._second;
				}

				return (*this);
			}
		
		public:
			T1  _first;
			T2  _second;
	};
	
	template<class T1, class T2>
	bool    operator==(const pair<T1, T2> &src1, const pair<T1, T2> &src2)
	{
		return (src1._first == src2._first && src1._second == src2._second);
	}

	template<class T1, class T2>
	bool    operator!=(const pair<T1, T2> &src1, const pair<T1, T2> &src2)
	{
		return !(src1._first == src2._first && src1._second == src2._second);
	}

	template<class T1, class T2>
	bool    operator<(const pair<T1, T2> &src1, const pair<T1, T2> &src2)
	{
		return (src1._first < src2._first);
	}

	template<class T1, class T2>
	bool    operator<=(const pair<T1, T2> &src1, const pair<T1, T2> &src2)
	{
		return (src1._first <= src2._first && src1._second <= src2._second);
	}

	template<class T1, class T2>
	bool    operator>(const pair<T1, T2> &src1, const pair<T1, T2> &src2)
	{
		return (src1._first > src2._first || src1._second > src2._second);
	}

	template<class T1, class T2>
	bool    operator>=(const pair<T1, T2> &src1, const pair<T1, T2> &src2)
	{
		return (src1._first >= src2._first);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 src1, T2 src2)
	{
		return (pair<T1, T2>(src1, src2));
	}
};

#endif
