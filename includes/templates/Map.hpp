/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:54 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/22 10:46:17 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../container.hpp"
# include "mapIterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		// Define types //
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef BNode<key_type, mapped_type>*					node;
			// typedef ft::pair<const Key, T>							value_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;
			typedef MapIterator<key_type, mapped_type>				iterator;
			typedef MapIterator<key_type, mapped_type>				const_iterator;
			typedef MapReverseIterator<key_type, mapped_type>		reverse_iterator;
			typedef MapConstReverseIterator<key_type, mapped_type>	const_reverse_iterator;
			typedef typename allocator_type::size_type				size_type; 
			// typedef std::size_t										size_type;

		private:
			// No-Member functions //
				void _debug_tree(node n)
				{
					if (n->left != NULL)
						_debug_tree(n->left);
					std::cout << n->pair << " " << n->value << std::endl;
					if (n->right != NULL)
						_debug_tree(n->right);
				}
				
				node _newNode(key_type type, mapped_type value, node parent, bool end = false)
				{
					node n = new BNode<key_type, mapped_type>;
					n->pair = ft::make_pair(type, value);
					n->parent = parent;
					n->left = NULL;
					n->right = NULL;
					n->end = end;
					
					return (n);
				}

				void _freeTree(node n)
				{
					if (n->right)
					_freeTree(n->right);
					if (n->left)
					_freeTree(n->left);
					delete n;
				}

				node _insertNode(node n, key_type key, mapped_type value, bool end = false)
				{
					if (n->end)
					{
						if (!n->left)
						{
							n->left = _newNode(key, value, n, end);
							return (n->left);
						}
						return (_insertNode(n->left, key, value));
					}
					if (key < n->pair.first && !end)
					{
						if (!n->left)
						{
							n->left = _newNode(key, value, n, end);
							return (n->left);
						}
						else
							return (_insertNode(n->left, key, value));
					}
					else
					{
						if (!n->right)
						{
							n->right = _newNode(key, value, n, end);
							return (n->right);
						}
						else
							return(_insertNode(n->right, key, value));
					}
				}

				node _find(node n, key_type type) const
				{
					if (n->end)
					{
						if (!n->left)
							return (NULL);
						return (_find(n->left, type));
					}
					if (n->pair.first == type)
						return (n);
					if (type < n->pair.first)
					{
						if (!n->left)
							return (NULL);
						return (_find(n->left, type));
					}
					else
					{
						if (!n->right)
							return (NULL);
						return (_find(n->right, type));
					}
				}
				
				void _deleteNode(node n)
				{
					if (n->left == NULL && n->right == NULL)
					{
						if (n->parent->left == n)
							n->parent->left = NULL;
						else
							n->parent->right = NULL;
						_allocator.destroy(n);
						_allocator.deallocate(n, 1);
					}
					else if (n->left == NULL)
					{
						if (n->parent->left == n)
							n->parent->left = n->right;
						else
							n->parent->right = n->right;
						n->right->parent = n->parent;
						_allocator.destroy(n);
						_allocator.deallocate(n, 1);
					}
					else if (n->right == NULL)
					{
						if (n->parent->left == n)
							n->parent->left = n->left;
						else
							n->parent->right = n->left;
						n->left->parent = n->parent;
						_allocator.destroy(n);
						_allocator.deallocate(n, 1);
					}
					else
					{
						node tmp = n->right;
						while (tmp->left != NULL)
							tmp = tmp->left;
						n->pair = tmp->pair;
						n->value = tmp->value;
						_deleteNode(tmp);
					}
				}

				// bool	_validate(void) const
				// {
				// 	if (_root == NULL)
				// 		return (false);
				// 	if (_root->left == NULL || _root->right == NULL)
				// 		return (false);
				// 	if (_root->left->left == NULL || _root->left->right == NULL)
				// 		return (false);
				// 	if (_root->right->left == NULL || _root->right->right == NULL)
				// 		return (false);
				// 	if (_root->left->left != _root || _root->left->right != _root->right)
				// 		return (false);
				// 	if (_root->right->left != _root->left || _root->right->right != _root)
				// 		return (false);
				// 	return (true);
				// }

				void _init_tree(void)
				{
					_root = _newNode(key_type(), mapped_type(), NULL, true);
					_root->left = _newNode(key_type(), mapped_type(), _root, true);
					_root->right = _newNode(key_type(), mapped_type(), _root, true);
					_root->left->left = _root;
					_root->left->right = _root->right;
					_root->right->left = _root->left;
					_root->right->right = _root;
				}

				node _end(void) const
				{
					return _root->right;
				}
				
		public:
			class value_compare
			{
				friend class map;
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					
					bool operator() (const value_type &x, const value_type &y) const
					{
						return comp(x.first, y.first);
					};
					
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c)	{ return ;};
			};
			
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_allocator(alloc),
			_compare(comp),
			_root(NULL),
			_size(0)
			{
				return ;
			}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :
			_allocator(alloc),
			_compare(comp),
			_root(NULL),
			_size(0)
			{
				insert(first, last);
				
				return ;
			};
								
 			map (const map &src)
			{
				if (src._root != NULL)
				{
					_init_tree();
					insert(src.begin(), src.end());
				}
			}

			~map (void)
			{
				if (_root != NULL)
					_freeTree(_root);
			}

			map& operator= (const map& x)
			{
				if (this != &x)
				{
					if (_root != NULL)
						_freeTree(_root);
					_init_tree();
					insert(x.begin(), x.end());
				}
				
				return *this;
			}

			iterator begin()
			{
				return iterator(_root->left);
			}
			
 			const_iterator begin() const
			{
				return const_iterator(_root->left);
			}

			iterator end()
			{
				return iterator(_root);
			}
			
			const_iterator end() const
			{
				return const_iterator(_root);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(_root->right);
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(_root->right);
			}

			reverse_iterator rend()
			{
				return reverse_iterator(_root);
			}
			
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(_root);
			}

			bool empty() const
			{
				return (_size == 0);
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _allocator.max_size();
			}

			mapped_type& operator[] (const key_type &k)
			{
				node n = _find(_root, k);
				if (n == NULL)
				{
					n = _newNode(k, mapped_type(), NULL, false);
					_insertNode(n);
				}
				
				return n->_value.second;
			}

			pair<iterator, bool> insert(const value_type &value)
			{
				iterator tmp;
				if ((tmp = find(value.first)) != end())
					return (make_pair(tmp, false));
				++_size;
				return (make_pair(iterator(_insertNode(_root, value.first, value.second)), true));
			};

			// pair<iterator, bool> insert(const value_type &value)
			// {
			// 	node n = _find(_root, value.first);
			// 	if (n == NULL)
			// 	{
			// 		n = _newNode(value.first, value.second, NULL, false);
			// 		_insertNode(_root, value.first, value.second);
			// 		return pair<iterator, bool>(iterator(n), true);
			// 	}
				
			// 	return pair<iterator, bool>(iterator(n), false);
			// }

			iterator insert (iterator position, const value_type &val)
			{
				node n = _find(_root, val.first);
				if (n == NULL)
				{
					n = _newNode(val.first, val.second, NULL, false);
					_insertNode(n, val.first, val.second);
				}
				
				return iterator(n);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				for (InputIterator it = first; it != last; it++)
					insert(*it);
			}

			void erase (iterator position)
			{
				_deleteNode(position._node);
			}

			size_type erase (const key_type &k)
			{
				node n = _find(_root, k);
				if (n != NULL)
				{
					_deleteNode(n);
					return 1;
				}
				
				return 0;
			}

			void erase (iterator first, iterator last)
			{
				for (iterator it = first; it != last; it++)
					_deleteNode(it._node);
			}

			void swap (map &x)
			{
				node tmp = _root;
				_root = x._root;
				x._root = tmp;
				
				size_type tmp_size = _size;
				_size = x._size;
				x._size = tmp_size;
			}

			void clear()
			{
				if (_root != NULL)
					_freeTree(_root);
					
				_init_tree();
			}

			key_compare key_comp() const
			{
				return _compare;
			}

			value_compare value_comp() const
			{
				return value_compare(_compare);
			}

			iterator find (const key_type &k)
			{
				node n = _find(_root, k);
				if (n != NULL)
					return iterator(n);
				
				return end();
			}
			
			const_iterator find (const key_type &k) const
			{
				node n = _find(_root, k);
				if (n != NULL)
					return const_iterator(n);
				
				return end();
			}

			size_type count (const key_type &k) const
			{
				node n = _find(_root, k);
				if (n != NULL)
					return 1;
				
				return 0;
			}

			iterator lower_bound (const key_type &k)
			{
				node n = _find(_root, k);
				if (n != NULL)
					return iterator(n);
				
				return end();
			}
			
			const_iterator lower_bound (const key_type &k) const
			{
				node n = _find(_root, k);
				if (n != NULL)
					return const_iterator(n);
				
				return end();
			}

			iterator upper_bound (const key_type &k)
			{
				node n = _find(_root, k);
				if (n != NULL)
					return iterator(n);
				
				return end();
			}
			
			const_iterator upper_bound (const key_type &k) const
			{
				node n = _find(_root, k);
				if (n != NULL)
					return const_iterator(n);
				
				return end();
			}

			pair<const_iterator,const_iterator> equal_range (const key_type &k) const
			{
				node n = _find(_root, k);
				if (n != NULL)
					return pair<const_iterator, const_iterator>(const_iterator(n), const_iterator(n));
				
				return pair<const_iterator, const_iterator>(end(), end());
			}
			
			pair<iterator,iterator> equal_range (const key_type &k)
			{
				node n = _find(_root, k);
				if (n != NULL)
					return pair<iterator, iterator>(iterator(n), iterator(n));
				
				return pair<iterator, iterator>(end(), end());
			}

		private:
			allocator_type	_allocator;
			key_compare		_compare;
			node			_root;
			size_type		_size;

				
	};

	// Non-member function overloads
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		
		typename map<Key, T, Compare, Alloc>::const_iterator it1 = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
		
		while (it1 != lhs.end())
		{
			if (*it1 != *it2)
				return false;
			
			it1++;
			it2++;
		}
		
		return true;
	}
	
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator< (const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
			return true;
		
		typename map<Key, T, Compare, Alloc>::const_iterator it1 = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
		
		while (it1 != lhs.end())
		{
			if (*it1 < *it2)
				return true;
			
			it1++;
			it2++;
		}
		
		return false;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator> (const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
};

#endif
