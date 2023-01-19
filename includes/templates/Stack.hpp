/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:45:41 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/18 19:23:05 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <deque>
# include <vector>

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class stack
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;
			
		public:
			explicit stack(const container_type &ctnr = container_type()) :
			_container(ctnr)
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
			
			value_type& top()
			{
				return _container.back();
			}
			
			const value_type& top() const
			{
				return _container.back();
			}
			
			void push(const value_type &val)
			{
				_container.push_back(val);
			}
			
			void pop()
			{
				_container.pop_back();
			}
			
			template <class T1, class Container1>
			friend bool operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs)
			{
				return (lhs._container == rhs._container);
			}
			
			template <class T1, class Container1>
			friend bool operator!=(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs)
			{
				return (lhs._container != rhs._container);
			}
			
			template <class T1, class Container1>
			friend bool operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs)
			{
				return (lhs._container < rhs._container);
			}
			
			template <class T1, class Container1>
			friend bool operator<=(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs)
			{
				return (lhs._container <= rhs._container);
			}
			
			template <class T1, class Container1>
			friend bool operator>(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs)
			{
				return (lhs._container > rhs._container);
			}
			
			template <class T1, class Container1>
			friend bool operator>=(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs)
			{
				return (lhs._container >= rhs._container);
			}
			
		protected:
			container_type		_container;
	};
};

#endif
