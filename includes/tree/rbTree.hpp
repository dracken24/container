/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:06:21 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/19 16:17:01 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

#include "../functions/pair.hpp"

namespace ft 
{
	const class nullptr_t
	{

		public:
			template <class T>
			operator T*() const
			{
				return 0;
			}

			template <class T, class U>
			operator T U::*() const
			{
				return 0;
			}

		private:
			void operator&() const;
	} NIL = {};

	// Node
	template <typename T>
	struct TreeNode 
	{
		typedef T     value_type;

		TreeNode*   _parent;
		TreeNode*   _left;
		TreeNode*   _right;
		value_type  _value;
		bool        _is_black;

		TreeNode() :
		_parent(NIL),
		_left(NIL),
		_right(NIL),
		_is_black(false)
		{
			return ;
		}

		TreeNode(const value_type &value) :
		_parent(NIL),
		_left(NIL),
		_right(NIL),
		_value(value),
		_is_black(false)
		{
			return ;
		}

		TreeNode(const TreeNode &ref) :
		_parent(ref._parent),
		_left(ref._left),
		_right(ref._right),
		_value(ref._value),
		_is_black(ref._is_black)
		{
			return ;
		}
		
		~TreeNode()
		{
			return ;
		}

		TreeNode& operator=(const TreeNode &ref)
		{
			if (this != &ref)
			{
				_parent = ref._parent;
				_left = ref._left;
				_right = ref._right;
				_value = ref._value;
				_is_black = ref._is_black;
			}
			return (*this);
		}
	};

	template <typename NodePtr>
	bool is_left_child(const NodePtr &ptr)
	{
		return (ptr->_parent->_left == ptr);
	}
	
	template <typename NodePtr>
	bool is_right_child(const NodePtr &ptr)
	{
		return (ptr->_parent->_right == ptr);
	}

	template <typename NodePtr>
	bool is_black_color(const NodePtr &ptr)
	{
		return (ptr->_is_black);
	}
	
	template <typename NodePtr>
	bool is_red_color(const NodePtr &ptr)
	{
		return (!ptr->_is_black);
	}

	template <typename NodePtr>
	NodePtr get_min_node(NodePtr ptr, NodePtr nil)
	{
		while (ptr->_left != nil)
			ptr = ptr->_left;
			
		return (ptr);
	}
	
	template <typename NodePtr>
	NodePtr get_max_node(NodePtr ptr, NodePtr nil)
	{
		while (ptr->_right != nil)
			ptr = ptr->_right;
			
		return (ptr);
	}

	template <typename NodePtr>
	NodePtr get_next_node(NodePtr ptr, NodePtr nil)
	{
		if (ptr->_right != nil)
			return (get_min_node(ptr->_right, nil));

		NodePtr parent = ptr->_parent;
		for (; parent != nil && ptr == parent->_right;
			ptr = parent, parent = parent->_parent)
			;
		
		return (parent);
	}

	template <typename U, typename V, class Comp>
	bool is_equal(const U &u, const V &v, Comp comp)
	{
		return (!comp(u, v) && !comp(v, u));
	}

	// RBTree
	template <typename U, typename V>
	class tree_iterator
	{
		public:
			typedef U															value_type;
			typedef V*															iterator_type;
			typedef value_type*													pointer;
			typedef value_type&													reference;
			
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::value_type			node_type;
			typedef typename iterator_traits<iterator_type>::reference			node_reference;
			typedef typename iterator_traits<iterator_type>::pointer			node_pointer;


		public:
			tree_iterator() :
			_current(NIL)
			{
				return ;
			}
			
			tree_iterator(node_pointer cur, node_pointer nil) :
			_current(cur),
			_nil(nil)
			{
				return ;
			}

			tree_iterator(const tree_iterator &ref) :
			_current(ref._cur),
			_nil(ref._nil)
			{
				return ;
			}

			~tree_iterator()
			{
				return ;
			}

			tree_iterator& operator=(const tree_iterator &ref)
			{
				if (this != &ref)
				{
					_current = ref._cur;
					_nil = ref._nil;
				}
				return (*this);
			}

			node_pointer base()       const
			{
				return (_current);
			}
			
			pointer      operator->() const
			{
				return (&_current->_value);
			}
			
			reference    operator*()  const
			{
				return (_current->_value);
			}

			tree_iterator& operator++()
			{
				_current = get_next_node(_current, _nil);
				
				return (*this);
			}
			
			tree_iterator operator++(int)
			{
				tree_iterator tmp(*this);
				++(*this);
				
				return (tmp);
			}

			tree_iterator& operator--()
			{
				if (_current == _nil)
				{
					_current = get_max_node(_current, _nil);
					return (*this);
				}
				
				if (_current->_left != _nil)
				{
					_current = get_max_node(_current->_left, _nil);
					return (*this);
				}
				
				node_pointer parent = _current->_parent;
				for (; parent != _nil && _current == parent->_left;
					_current = parent, parent = parent->_parent)
					;
				
				_current = parent;
				
				return (*this);
			}
			
			tree_iterator operator--(int)
			{
				tree_iterator tmp(*this);
				--(*this);
				
				return (tmp);
			}

			template <typename T>
			bool operator==(const tree_iterator<T, node_type> &x) const
			{
				return (_current == x._current);
			}
			
			template <typename T>
			bool operator!=(const tree_iterator<T, node_type> &x) const
			{
				return (_current != x._current);
			}

			operator tree_iterator<const value_type, node_type>(void) const
			{
				return (tree_iterator<const value_type, node_type>(_current, _nil));
			}

			friend bool operator==(const tree_iterator &lhs, const tree_iterator &rhs)
			{
				return (lhs._current == rhs._current);
			}
			
			friend bool operator!=(const tree_iterator &lhs, const tree_iterator &rhs)
			{
				return (lhs._current != rhs._current);
			}
	
		private:
			node_pointer  _current;
			node_pointer  _nil;
  	};

	template <typename Alloc>
    struct allocator_traits 
	{
        typedef typename Alloc::value_type value_type;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;

        static Alloc allocate(Alloc &a, std::size_t n)
		{
            return a.allocate(n);
        }

		static void deallocate(Alloc &a, pointer p, std::size_t n)
		{
			a.deallocate(p, n);
		}
		
		template <typename T>
		static void construct(Alloc &a, T *p, const T &val)
		{
			a.construct(p, val);
		}

		template <typename T>
		static void destroy(Alloc &a, T *p)
		{
			a.destroy(p);
		}
	};

	// RBTree
	template <typename T, class Key, class Comp, class Allocator>
	class rbtree
	{

		public:
			typedef T															value_type;
			typedef Key															key_type;
			typedef Comp														compare_type;
			
			typedef TreeNode<value_type>										node_type;
			typedef TreeNode<value_type>*										node_pointer; // node_type*
			typedef tree_iterator<value_type, node_type>						iterator;
			typedef tree_iterator<const value_type, node_type>					const_iterator;
			typedef Allocator													allocator_type;
			
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator;
			typedef ft::allocator_traits<node_allocator>						node_traits;
			typedef typename allocator_type::size_type							size_type;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

		public:
			rbtree(const compare_type &comp, const allocator_type &alloc) :
			_comp(comp),
			_allocator(alloc),
			_size(size_type())
			{
				_nil = _allocator.allocate(1);
				_allocator.construct(_nil, value_type());
				_nil->_is_black = true;
				_nil->_parent = _nil;
				_nil->_left = _nil;
				_nil->_right= _nil;
				_end = create_node(value_type());
				_end->_is_black = true;
				_begin = _end;
			}
			
			rbtree(const rbtree& ref) : 
			_comp(ref._comp),
			_allocator(ref._alloc),
			_size(size_type())
			{
				_nil = _allocator.allocate(1);
				_allocator.construct(_nil, value_type());
				_nil->_is_black = true;
				_nil->_parent = _nil;
				_nil->_left = _nil;
				_nil->_right= _nil;
				_end = create_node(value_type());
				_end->_is_black = true;
				_begin = _end;
				insert(ref.begin(), ref.end());
			}

			~rbtree()
			{
				clear();
				_allocator.destroy(_nil);
				_allocator.deallocate(_nil, 1);
			}

			rbtree& operator=(const rbtree& ref)
			{
				if (this != &ref)
				{
					clear();
					insert(ref.begin(), ref.end());
				}
				return (*this);
			}
			

			// Iterators //
			iterator begin()
			{
				return iterator(_begin, _nil);
			}
			
			const_iterator begin() const
			{
				return const_iterator(_begin, _nil);
			}

			iterator end()
			{
				return iterator(_end, _nil);
			}
			
			const_iterator end() const
			{
				return const_iterator(_end, _nil);
			}

			// Capacity //
			bool empty() const
			{
				return (_size == 0);
			}

			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return (_allocator.max_size(_allocator));
			}

			// Modifiers //
			ft::pair<iterator, bool> insert(const value_type &value)
			{
				node_pointer tmp = _begin;
				node_pointer parent = _nil;
				bool is_left = false;
				while (tmp != _end)
				{
					parent = tmp;
					if (_comp(value, tmp->_value))
					{
						tmp = tmp->_left;
						is_left = true;
					}
					else if (_comp(tmp->_value, value))
					{
						tmp = tmp->_right;
						is_left = false;
					}
					else
						return (ft::make_pair(iterator(tmp, _nil), false));
				}
				
				node_pointer new_node = create_node(value);
				if (parent == _nil)
				{
					_begin = new_node;
					_end->_parent = new_node;
				}
				else if (is_left)
					parent->_left = new_node;
				else
					parent->_right = new_node;
				new_node->_parent = parent;
				++_size;
				insert_fixup(new_node);
				return (ft::make_pair(iterator(new_node, _nil), true));
			}
			
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			

			iterator erase(iterator position)
			{
				node_pointer tmp = position.get_node();
				iterator ret = ++position;
				erase(tmp);
				
				return (ret);
			}
			
			size_type erase(const key_type &value)
			{
				node_pointer tmp = _begin;
				while (tmp != _end)
				{
					if (_comp(value, tmp->_value))
						tmp = tmp->_left;
					else if (_comp(tmp->_value, value))
						tmp = tmp->_right;
					else
					{
						erase(tmp);
						return (1);
					}
				}
				return (0);
			}
			
			void erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			void swap(rbtree &ref)
			{
				ft::swap(_begin, ref._begin);
				ft::swap(_end, ref._end);
				ft::swap(_size, ref._size);
				ft::swap(_nil, ref._nil);
				ft::swap(_comp, ref._comp);
				ft::swap(_allocator, ref._allocator);
			}

			void clear(void)
			{
				erase(begin(), end());
			}

			// Observers
			iterator find(const key_type &key)
			{
				node_pointer tmp = _begin;
				while (tmp != _end)
				{
					if (_comp(key, tmp->_value))
						tmp = tmp->_left;
					else if (_comp(tmp->_value, key))
						tmp = tmp->_right;
					else
						return (iterator(tmp, _nil));
				}
				
				return (end());
			}
			
			const_iterator find(const key_type &key) const
			{
				node_pointer tmp = _begin;
				while (tmp != _end)
				{
					if (_comp(key, tmp->_value))
						tmp = tmp->_left;
					else if (_comp(tmp->_value, key))
						tmp = tmp->_right;
					else
						return (const_iterator(tmp, _nil));
				}
				
				return (end());
			}

			iterator lower_bound(const key_type &key)
			{
				iterator it = begin();
				while (it != end())
				{
					if (!_comp(it->first, key))
						return (it);
					++it;
				}
				
				return (it);
			}
			
			const_iterator lower_bound(const key_type &key) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (!_comp(it->first, key))
						return (it);
					++it;
				}
				
				return (it);
			}

			iterator upper_bound(const key_type &key)
			{
				iterator it = begin();
				while (it != end())
				{
					if (_comp(key, it->first))
						return (it);
					++it;
				}
				
				return (it);
			}
			
			const_iterator upper_bound(const key_type &key) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (_comp(key, it->first))
						return (it);
					++it;
				}
				
				return (it);
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
			{
				return (ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
			}
			
			ft::pair<iterator, iterator> equal_range(const key_type &key)
			{
				return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
			}

			// Allocator
			allocator_type get_allocator() const
			{
				return (_allocator);
			}

		private:

			// return the node that is the parent of the node that should contain the value
			node_pointer get_root() const
			{
				return (_begin->_parent);
			}

			void set_root(const node_pointer ptr)
			{
				_begin->_parent = ptr;
			}

			node_pointer create_node(const value_type &value)
			{
				node_pointer ptr = _allocator.allocate(1);
				_allocator.construct(ptr, node(value));
				
				return (ptr);
			}

			void delete_node(node_pointer ptr)
			{
				_allocator.destroy(ptr);
				_allocator.deallocate(ptr, 1);

				return ;
			}

			void delete_node_recursive(node_pointer ptr)
			{
				if (ptr == _end)
					return ;
					
				delete_node_recursive(ptr->_left);
				delete_node_recursive(ptr->_right);
				delete_node(ptr);

				return ;
			}

			node_pointer search_parent(const value_type& value, node_pointer position = ft::NIL)
			{
				if (position == ft::NIL)
					position = get_root();
				if (position == _end)
					return (position);
					
				switch (_comp(value, position->_value))
				{
					case true:
						if (position->_left == _end)
							return (position);
						return (search_parent(value, position->_left));
					case false:
						if (position->_right == _end)
							return (position);
						return (search_parent(value, position->_right));
				}
				
				return (position);
			}

			node_pointer insert_internal(const value_type& value, node_pointer parent)
			{
				node_pointer ptr = create_node(value);
				ptr->_parent = parent;
				ptr->_left = _end;
				ptr->_right = _end;
				ptr->_color = false; // false = red

				if (parent == _end)
					set_root(ptr);
				switch (_comp(value, parent->_value))
				{
					case true:
						parent->_left = ptr;
						break ;
					case false:
						parent->_right = ptr;
						break ;
				}
				
				insert_fixup(ptr);
				insert_update(ptr);
				
				return (ptr);
			}

			// insert fixup function allows to keep the tree balanced after insertion of a new node
			void insert_fixup(node_pointer ptr)
			{
				if (ptr == get_root())
				{
					ptr->_color = true; // true = black
					return ;
				}
				if (ptr->_parent->_color == true)
					return ;
				if (ptr->_parent->_parent->_left->_color == false && ptr->_parent->_parent->_right->_color == false)
				{
					ptr->_parent->_color = true;
					ptr->_parent->_parent->_left->_color = true;
					ptr->_parent->_parent->_right->_color = true;
					insert_fixup(ptr->_parent->_parent);
					return ;
				}
				
				if (ptr->_parent->_parent->_left->_color == false)
					insert_fixup_left(ptr);
				else
					insert_fixup_right(ptr);

				return ;
			}

			// insert fixup function for left child
			void insert_fixup_left(node_pointer &ptr)
			{
				if (ptr == ptr->_parent->_right)
				{
					ptr = ptr->_parent;
					rotate_left(ptr);
				}
				ptr->_parent->_color = true;
				ptr->_parent->_parent->_color = false;
				rotate_right(ptr->_parent->_parent);

				return ;
			}

			// insert fixup function for right child
			void insert_fixup_right(node_pointer &ptr)
			{
				if (ptr == ptr->_parent->_left)
				{
					ptr = ptr->_parent;
					rotate_right(ptr);
				}
				ptr->_parent->_color = true;
				ptr->_parent->_parent->_color = false;
				rotate_left(ptr->_parent->_parent);

				return ;
			}

			// update the begin and size of the tree after insertion
			void insert_update(const node_pointer ptr)
			{
				
				if (ptr == _end)
					return ;
				if (ptr->_left != _end)
					insert_update(ptr->_left);
				if (ptr->_right != _end)
					insert_update(ptr->_right);
				if (ptr->_left == _end && ptr->_right == _end)
				{
					if (ptr->_parent->_left == ptr)
						ptr->_parent->_left = _end;
					else
						ptr->_parent->_right = _end;
					delete_node(ptr);
				}
				++_size;
				
				return ;
			}

			// update the begin and size of the tree after deletion
			void remove_internal(node_pointer ptr)
			{
				if (ptr == _end)
					return ;
				if (ptr->_left != _end)
					remove_internal(ptr->_left);
				if (ptr->_right != _end)
					remove_internal(ptr->_right);
				if (ptr->_left == _end && ptr->_right == _end)
				{
					if (ptr->_parent->_left == ptr)
						ptr->_parent->_left = _end;
					else
						ptr->_parent->_right = _end;
					delete_node(ptr);
				}
				--_size;
				
				return ;
			}

			void remove_fixup(node_pointer ptr)
			{
				switch (ptr->_color)
				{
					case true:
						return ;
					case false:
						if (ptr->_parent->_left->_color == false)
							remove_fixup_left(ptr);
						else
							remove_fixup_right(ptr);
						return ;
				}
					
				return ;
			}

			void remove_fixup_left(node_pointer &ptr)
			{
				if (ptr->_parent->_right->_color == false)
				{
					ptr->_parent->_right->_color = true;
					ptr->_parent->_color = false;
					rotate_left(ptr->_parent);
				}
				if (ptr->_parent->_right->_left->_color == true && ptr->_parent->_right->_right->_color == true)
				{
					ptr->_parent->_right->_color = false;
					remove_fixup(ptr->_parent);
					return ;
				}
				if (ptr->_parent->_right->_right->_color == true)
				{
					ptr->_parent->_right->_left->_color = true;
					ptr->_parent->_right->_color = false;
					rotate_right(ptr->_parent->_right);
				}
				ptr->_parent->_right->_color = ptr->_parent->_color;
				ptr->_parent->_color = true;
				ptr->_parent->_right->_right->_color = true;
				rotate_left(ptr->_parent);
				ptr = get_root();
				
				return ;
			}

			void remove_fixup_right(node_pointer &ptr)
			{
				if (ptr->_parent->_left->_color == false)
				{
					ptr->_parent->_left->_color = true;
					ptr->_parent->_color = false;
					rotate_right(ptr->_parent);
				}
				if (ptr->_parent->_left->_right->_color == true && ptr->_parent->_left->_left->_color == true)
				{
					ptr->_parent->_left->_color = false;
					remove_fixup(ptr->_parent);
					return ;
				}
				if (ptr->_parent->_left->_left->_color == true)
				{
					ptr->_parent->_left->_right->_color = true;
					ptr->_parent->_left->_color = false;
					rotate_left(ptr->_parent->_left);
				}
				
				ptr->_parent->_left->_color = ptr->_parent->_color;
				ptr->_parent->_color = true;
				ptr->_parent->_left->_left->_color = true;
				rotate_right(ptr->_parent);
				ptr = get_root();
				
				return ;
			}

			void transplant(node_pointer former, node_pointer latter)
			{
				switch (former->_parent->_color)
				{
					case true:
						if (former->_parent->_left == former)
							former->_parent->_left = latter;
						else
							former->_parent->_right = latter;
						break;
					case false:
						former->_parent->_left = latter;
						break;
				}
				
				return ;
			}

			// rotate nodes to left to maintain balance
			void rotate_left(node_pointer ptr)
			{
				node_pointer right = ptr->_right;
				transplant(ptr, right);
				ptr->_right = right->_left;
				
				if (right->_left != _end)
					right->_left->_parent = ptr;
					
				right->_left = ptr;
				ptr->_parent = right;
				
				return ;
			}

			// rotate nodes to right to maintain balance
			void rotate_right(node_pointer ptr)
			{
				node_pointer left = ptr->_left;
				transplant(ptr, left);
				ptr->_left = left->_right;
				
				if (left->_right != _end)
					left->_right->_parent = ptr;
					
				left->_right = ptr;
				ptr->_parent = left;
				
				return ;
			}

			// find first node of the tree
			node_pointer find_internal(const key_type &value)const
			{
				node_pointer ptr = get_root();
				
				while (ptr != _end)
				{
					switch (_comp(value, ptr->_value.first))
					{
						case true:
							ptr = ptr->_left;
							break;
						case false:
							switch (_comp(ptr->_value.first, value))
							{
								case true:
									ptr = ptr->_right;
									break;
								case false:
									return (ptr);
							}
					}
				}
				
				return (ptr);
			}
		
			// find the first node whose key is not less than the given key
			node_pointer lower_bound_internal(const key_type &key)const
			{
				node_pointer ptr = get_root();
				node_pointer result = _end;
				
				while (ptr != _end)
				{
					switch (_comp(ptr->_value.first, key))
					{
						case true:
							ptr = ptr->_right;
							break;
						case false:
							result = ptr;
							ptr = ptr->_left;
							break;
					}
				}
				
				return (result);
			}

			// find the first node whose key is greater than the given key
			node_pointer upper_bound_internal(const key_type &key)const
			{
				node_pointer ptr = get_root();
				node_pointer result = _end;
				
				while (ptr != _end)
				{
					switch (_comp(key, ptr->_value.first))
					{
						case true:
							result = ptr;
							ptr = ptr->_left;
							break;
						case false:
							ptr = ptr->_right;
							break;
					}
				}
				
				return (result);
			}

			ft::pair<iterator, iterator> equal_range_internal(const key_type &value)
			{
				node_pointer lower = lower_bound_internal(value);
				node_pointer upper = upper_bound_internal(value);
				
				return (ft::make_pair(iterator(lower), iterator(upper)));
			}
			
			ft::pair<const_iterator, const_iterator> equal_range_internal(const key_type &value)const
			{
				node_pointer lower = lower_bound_internal(value);
				node_pointer upper = upper_bound_internal(value);
				
				return (ft::make_pair(const_iterator(lower), const_iterator(upper)));
			}
	
		private:
			node_pointer    _nil;
			node_pointer    _begin;
			node_pointer    _end;
			compare_type    _comp;
			node_allocator  _allocator;
			size_type       _size;
	};
};

#endif
