/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:45:41 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/10 21:25:45 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
			typedef T			&reference;
			typedef const T		&const_reference;
			
		public:

			explicit stack(const container_type &ctnr = container_type()) :
			c(ctnr)
			{
				return ;
			}
		
			~stack()
			{
				return ;
			}
			
			bool empty() const
			{
				return c.empty();
			}
			
			size_type size() const
			{
				return c.size();
			}
			
			value_type &top()
			{
				return c.back();
			}
			
			const value_type &top() const
			{
				return c.back();
			}
			
			void	push(const value_type &val)
			{
				c.push_back(val);
			}
			
			void	pop()
			{
				c.pop_back();
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
			container_type		c;
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c != rhs.c;
	}

	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c < rhs.c;
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c <= rhs.c;
	}

	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c > rhs.c;
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c >= rhs.c;
	}
};

#endif
