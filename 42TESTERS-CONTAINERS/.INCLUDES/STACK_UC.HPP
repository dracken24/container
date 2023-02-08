/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:45:41 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/23 14:59:49 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// # include <deque>
// # include <vector>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
			
		public:

			explicit stack(const container_type &ctnr = container_type()) :
			_container(ctnr)
			{
				return ;
			}
		
			~stack()
			{
				return ;
			}
			
			bool empty() const
			{
				return _container.empty();
			}
			
			size_type size() const
			{
				return _container.size();
			}
			
			value_type &top()
			{
				return _container.back();
			}
			
			const value_type &top() const
			{
				return _container.back();
			}
			
			void	push(const value_type &val)
			{
				_container.push_back(val);
			}
			
			void	pop()
			{
				_container.pop_back();
			}
			
			template <class Tn, class ContN>
			friend bool operator==(const stack<Tn, ContN> &lhs, const stack<Tn, ContN> &rhs);
			
			template <class Tn, class ContN>
			friend bool operator!=(const stack<Tn, ContN> &lhs, const stack<Tn, ContN> &rhs);
			
			template <class Tn, class ContN>
			friend bool operator<(const stack<Tn, ContN> &lhs, const stack<Tn, ContN> &rhs);

			template <class Tn, class ContN>
			friend bool operator<=(const stack<Tn, ContN> &lhs, const stack<Tn, ContN> &rhs);

			template <class Tn, class ContN>
			friend bool operator>(const stack<Tn, ContN> &lhs, const stack<Tn, ContN> &rhs);

			template <class Tn, class ContN>
			friend bool operator>=(const stack<Tn, ContN> &lhs, const stack<Tn, ContN> &rhs);
			
			
			
		protected:
			container_type		_container;
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs._container == rhs._container;
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs._container != rhs._container;
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs._container < rhs._container;
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs._container <= rhs._container;
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs._container > rhs._container;
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs._container >= rhs._container;
	}
};
