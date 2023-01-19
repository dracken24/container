/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:54 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/19 13:09:56 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../container.hpp"
# include "../tree/rbTree.hpp"

namespace ft {
	
	// template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	// class map
	// {

	// public:
	// 	typedef T																mapped_type;
	// 	typedef Key																key_type;
	// 	typedef Alloc															allocator_type;
	// 	typedef Compare															key_compare;
	// 	typedef typename allocator_type::template rebind<value_type>::other		type_allocator;
	// 	typedef ft::pair<const key_type, mapped_type>							value_type;
		
	// 	typedef ft::allocator_traits<type_allocator>							type_traits;
	// 	typedef typename type_traits::const_pointer								const_pointer;
	// 	typedef typename type_traits::pointer									pointer;
		
	// 	typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
	// 	typedef typename allocator_type::size_type								size_type;
	// 	typedef const value_type&												const_reference;
	// 	typedef value_type&														reference;

	// class value_compare : public std::binary_function<value_type, value_type, bool>

	// protected:
	// 	key_compare comp;

	// public:
	// 	value_compare(key_compare c) :
	// 	~value_compare()

	// 	bool operator()(const value_type& x, const value_type& y)const
		
	// 	bool operator()(const value_type& x, const key_type& y)const
		
	// 	bool operator()(const key_type& x, const value_type& y)const
	// };

	// typedef typename ft::rbtree<value_type, key_type, value_compare, allocator_type>::const_iterator	const_iterator;
	// typedef typename ft::rbtree<value_type, key_type, value_compare, allocator_type>::iterator			iterator;
	// typedef ft::reverse_iterator<const_iterator>														const_reverse_iterator;
	// typedef ft::reverse_iterator<iterator>        														reverse_iterator;

	// private:
	// 	key_compare     _key_comp;
	// 	value_compare   _value_comp;
	// 	ft::rbtree<value_type, key_type, value_compare, allocator_type>   _tree;

	// public:
	// 	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :

	// 	template <class InputIterator>
	// 	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :

	// 	map(const map& x) : 

	// 	~map()

	// 	map& operator=(const map& x)
		

	// 	// Iterators
	// 	iterator begin()
		
	// 	const_iterator begin()const

	// 	iterator end()
		
	// 	const_iterator end()const

	// 	reverse_iterator rbegin()
		
	// 	const_reverse_iterator rbegin()const

	// 	reverse_iterator rend()
		
	// 	const_reverse_iterator rend()const

	// 	// Capacity
	// 	bool empty()const

	// 	size_type size()const

	// 	size_type max_size()const

	// 	// Element access
	// 	mapped_type& operator[] (const key_type& k)

	// 	mapped_type& at(const key_type& k)

	// 	const mapped_type& at(const key_type& k)const

	// 	// Modifiers
	// 	ft::pair<iterator, bool> insert(const value_type& val)

	// 	iterator insert(iterator position, const value_type& val)

	// 	template <class InputIterator>
	// 	void insert(InputIterator first, InputIterator last)

	// 	void erase(iterator position)

	// 	size_type erase(const key_type& k)

	// 	void erase(iterator first, iterator last)

	// 	void swap(map& x)

	// 	void clear()

	// 	// Observers
	// 	key_compare key_comp()const

	// 	value_compare value_comp()const

	// 	// Operations
	// 	iterator find(const key_type& k)
		
	// 	const_iterator find(const key_type& k)const

	// 	size_type count(const key_type& k)const

	// 	iterator lower_bound(const key_type& k)
		
	// 	const_iterator lower_bound(const key_type& k)const

	// 	iterator upper_bound(const key_type& k)
		
	// 	const_iterator upper_bound(const key_type& k)const

	// 	ft::pair<const_iterator, const_iterator> equal_range(const key_type& k)const
		
	// 	ft::pair<iterator, iterator> equal_range(const key_type& k)

	// 	// Allocator
	// 	allocator_type get_allocator()const
	// };

	// Non-member function overloads
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator< (const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator> (const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	
	// template <class Key, class T, class Compare, class Alloc>
	// bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs);

	// template <class Key, class T, class Compare, class Alloc>
	// void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs)
};
#endif
