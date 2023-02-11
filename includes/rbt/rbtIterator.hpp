/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:41:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/11 16:58:42 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Link for Red Black Tree Visualisation //
// https://www.cs.usfca.edu/~galles/visualization/RedBlack.html //

#ifndef RBTITERATOR_HPP
# define RBTITERATOR_HPP

namespace ft
{

	//******************************************************************************************************//
	//											Node Struct 									    		//
	//******************************************************************************************************//
	
	template <typename value_type>
	class rbt_node
	{
	  public:
		rbt_node*	parent;
		rbt_node*	left;
		rbt_node*	right;

		value_type	data;
		bool		is_black;
	};

	//******************************************************************************************************//
	//												Class	 									    		//
	//******************************************************************************************************//

	template<typename T, typename Compare>
	class rbt_iterator
	{
	public:
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef const rbt_iterator<T, Compare>		rbt_const_iterator;

	private:
		typedef rbt_node<value_type>				tree_node;
		typedef tree_node*							tree_node_ptr;


	//******************************************************************************************************//
	//										Constructor - Destructor							    		//
	//******************************************************************************************************//

	public:
	  
		rbt_iterator() :
		_current(NULL),
		_comp(Compare())
		{

		}

		rbt_iterator(const tree_node_ptr node) :
		_current(node),
		_comp(Compare())
		{

		}

		~rbt_iterator()
		{

		}

	//******************************************************************************************************//
	//						    				Overload Operator		    					    		//
	//******************************************************************************************************//

		reference operator*() const
		{
			return _current->data;
		}

		pointer operator->() const
		{
			return &_current->data;
		}

		rbt_iterator &operator=(const rbt_iterator &other)
		{
			_current = other._current;
			
			return *this;
		}

		rbt_iterator &operator++()
		{
			if (_current->right != NULL)
			{
				_current = _current->right;
				while (_current->left != NULL)
				{
					_current = _current->left;
				}
				
				return *this;
			}
			else
			{
				while (_current->parent != NULL && _current->parent->right == _current)
				{
					_current = _current->parent;
				}
				_current = _current->parent;
				
				return *this;
			}
		}

		rbt_iterator operator++(int)
		{
			rbt_iterator tmp_it = *this;
			++(*this);
			
			return tmp_it;
		}

		rbt_iterator &operator--()
		{
			if (_current->left != NULL)
			{
				_current = _current->left;
				while (_current->right != NULL)
				{
					_current = _current->right;
				}
				
				return *this;
			}
			else
			{
				while (_current->parent != NULL && _current->parent->left == _current)
				{
					_current = _current->parent;
				}
				_current = _current->parent;
				
				return *this;
			}
		}

		rbt_iterator operator--(int)
		{
			rbt_iterator tmp_it = *this;
			--(*this);
			
			return tmp_it;
		}

	//******************************************************************************************************//
	//						    				Compare Operator		    					    		//
	//******************************************************************************************************//

		bool operator==(const rbt_iterator &other)
		{
			return _current == other.base();
		}

		bool operator==(const rbt_const_iterator &other) const
		{
			return (_current == other.base());
		}

		bool operator!=(const rbt_iterator &other)
		{
			return !(*this == other);
		}

		bool operator!=(const rbt_const_iterator &other) const
		{
			return !(*this == other);
		}

		tree_node_ptr base() const
		{
			return _current;
		}

		protected:
			tree_node_ptr 	_current;

		private:
			Compare			_comp;
	};
}

#endif
