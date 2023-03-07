/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:20:27 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/06 21:57:16 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <iostream>

namespace ft
{
	template<typename T , typename Compare>
	class map_iterator
	{
		public:
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef std::ptrdiff_t						difference_type;
			typedef map_iterator<T, Compare>			iterator;
			typedef const map_iterator<T, Compare>		const_iterator;

		private:
			typedef iterator*							_node_ptr;

		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//
		
		public:
			map_iterator(void) :
			_selected_value(NULL), _comp(Compare())
			{ };

			map_iterator(const _node_ptr node) :
			_selected_value(node), _comp(Compare())
			{ };

			~map_iterator()
			{ };

		//******************************************************************************************************//
		//						    				Overload Operator		    					    		//
		//******************************************************************************************************//

		reference	operator*(void) const
		{
			return _selected_value->pair;
		}

		pointer		operator->(void) const
		{
			return &_selected_value->pair;
		}
		
		iterator	&operator=(const iterator &src)
		{
			_selected_value = src._current;
			
			return *this;
		}

		iterator	&operator++(void)
		{
			if (_selected_value->right != nullptr)
			{
				_selected_value = _selected_value->right;
			}

			return (*this);
		}

		iterator	operator++(int)
		{

			if (_selected_value->right != nullptr)
			{
				iterator tmp = *this;
				_selected_value = _selected_value->right;
				
				return (tmp);
			}
			
			return (*this);
		}

		iterator	&operator--(void)
		{
			if (_selected_value->left != nullptr)
			{
				_selected_value = _selected_value->left;
			}

			return (*this);
		}

		iterator	operator--(int)
		{

			if (_selected_value->left != nullptr)
			{
				iterator tmp = *this;
				_selected_value = _selected_value->left;
				
				return (tmp);
			}
			
			return (*this);
		}

		//******************************************************************************************************//
		//											Members values									    		//
		//******************************************************************************************************//
		
		protected:
			_node_ptr 	_selected_value;

		private:
			Compare			_comp;
	};
};

#endif
