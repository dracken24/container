/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:41:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/10 23:22:51 by dracken24        ###   ########.fr       */
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

	template <typename T, typename Compare>
	class rbt_const_iterator;

	template<typename T, typename Compare>
	class rbt_iterator
	{
	public:
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t						difference_type;
		typedef rbt_const_iterator<T, Compare>		rbt_const_iterator;

	private:
		typedef rbt_node<value_type>	tree_node;
		typedef tree_node*				tree_node_ptr;


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

		bool operator==(const rbt_const_iterator &other)
		{
			return _current == other.base();
		}

		bool operator!=(const rbt_iterator &other)
		{
			return !(*this == other);
		}

		bool operator!=(const rbt_const_iterator &other)
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

  	template<typename T, typename Compare>
	class rbt_const_iterator
	{
	public:
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::ptrdiff_t						difference_type;
		typedef rbt_iterator<T, Compare>			rbt_iterator;
		typedef std::bidirectional_iterator_tag		iterator_category;

	private:
		typedef rbt_node<value_type>				tree_node;
		typedef tree_node*							tree_node_ptr;
		
	//******************************************************************************************************//
	//										Constructor - Destructor							    		//
	//******************************************************************************************************//

	public:

		rbt_const_iterator(void) :
		_current(NULL),
		_comp(Compare())
		{

		}

		rbt_const_iterator(const tree_node_ptr node) :
		_current(node),
		_comp(Compare())
		{

		}

		rbt_const_iterator(rbt_iterator it) :
		_current(it.base())
		{

		}

	//******************************************************************************************************//
	//						    				Overload Operator		    					    		//
	//******************************************************************************************************//

		reference operator*(void) const
		{
			return _current->data;
		}

		pointer operator->(void) const
		{
			return &_current->data;
		}

		rbt_const_iterator &operator=(const rbt_const_iterator &other)
		{
			_current = other._current;

			return *this;
		}

		rbt_const_iterator &operator++(void)
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

		rbt_const_iterator operator++(int)
		{
			rbt_const_iterator tmp_it = *this;
			++(*this);

			return tmp_it;
		}

		rbt_const_iterator& operator--()
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

		rbt_const_iterator operator--(int)
		{
			rbt_const_iterator tmp_it = *this;
			--(*this);

			return tmp_it;
		}

	//******************************************************************************************************//
	//						    				Compare Operator		    					    		//
	//******************************************************************************************************//

		bool operator==(const rbt_const_iterator &other)
		{
			return _current == other.base();
		}

		bool operator==(const rbt_iterator &other)
		{
			return _current == other.base();
		}

		bool operator!=(const rbt_const_iterator &other)
		{
			return !(*this == other);
		}

		bool operator!=(const rbt_iterator &other)
		{
			return !(*this == other);
		}

		const tree_node_ptr base() const { return _current; }

		protected:
			tree_node_ptr _current;

		private:
			Compare _comp;
	};
}

#endif
