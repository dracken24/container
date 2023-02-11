/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:54 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/11 00:14:48 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_HPP
# define MAP_HPP

#include <functional>
#include <cmath>
#include <limits>
#include <iostream>

# include "../functions/utils.hpp"
# include "../rbt/rbTree.hpp"

namespace ft
{
  	template <typename Key,
	typename T,
	typename Compare = std::less<Key>,
	typename Allocator = std::allocator<ft::pair<const Key, T> > >
	
	class map
	{
	public:
		typedef  Key													key_type;                                                      
		typedef  T														mapped_type;                                                   
		typedef  pair<const Key, T>										value_type;
		typedef  std::size_t											size_type;                                                     
		typedef  std::ptrdiff_t											difference_type;                                               
		typedef  Compare												key_compare;                                                   
		typedef  Allocator												allocator_type;                                                
		typedef  value_type&											reference;                                                     
		typedef  const value_type&										const_reference;         
		typedef  typename Allocator::pointer							pointer;                 
		typedef  typename Allocator::const_pointer						const_pointer;           
		typedef  rbt_iterator<value_type, Compare>						iterator;
		typedef  rbt_const_iterator<value_type, Compare>				const_iterator;
		typedef  typename ft::reverse_iterator<iterator>				reverse_iterator;        
		typedef  typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;  
		typedef  rb_tree<value_type, Compare, Allocator>				rb_tree;

	//******************************************************************************************************//
	//											Member class									    		//
	//******************************************************************************************************//

	public:
		class value_compare : std::binary_function<value_type, value_type, bool>
		{

			friend class map;

		public:
			typedef bool        result_type;
			typedef value_type  first_argument_type;
			typedef value_type  second_argument_type;

			value_compare(Compare c) :
			_compare(c)
			{

			}

		public:
			bool operator()(const value_type &lhs, const value_type &rhs) const
			{
				return _compare(lhs.first, rhs.first);
			}

		protected:
			Compare _compare;
		};

	//******************************************************************************************************//
	//										Constructor - Destructor							    		//
	//******************************************************************************************************//

	public:

		explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) :
		_allocator(alloc)
		, _compare(comp)
		{
			_tree = rb_tree(comp, alloc);
		}

		template<typename InputIt>
		map(InputIt first, InputIt last, const Compare& comp = Compare(),
			const Allocator& alloc = Allocator()) :
		_allocator(alloc)
		, _compare(comp)
		{
			_tree = rb_tree(first, last, comp, alloc);
		}

		map(const map& other) :
		_tree(other._tree)
		{

		}

		~map()
		{

		}

		// Map assignment operator overload
		map &operator=(const map &other)
		{
			_tree = other._tree;
			
			return *this;
		}

	//******************************************************************************************************//
	//											Getters - Setters								    		//
	//******************************************************************************************************//

		allocator_type get_allocator(void) const
		{
			return _allocator;
		}

		void clear(void)
		{
			_tree.clear();
		}

		pair<iterator, bool> insert(const value_type &value)
		{
			return _tree.insert(value);
		}

		iterator insert(iterator hint, const value_type &value)
		{
			return _tree.insert(hint, value);
		}

		template <typename InputIt>
		void insert(InputIt first, InputIt last)
		{
			_tree.insert(first, last);
		}

		void erase(iterator pos)
		{
			_tree.erase(pos);
		}

		void erase(iterator first, iterator last)
		{
			_tree.template erase<Key>(first, last);
		}

		size_type erase(const Key &key)
		{
			return _tree.erase(key);
		}

		void swap(map &other)
		{
			_tree.swap(other._tree);
		}

	//******************************************************************************************************//
	//											Element access									    		//
	//******************************************************************************************************//

		T &at(const Key &key)
		{
			return _tree.template at<Key, T>(key);
		}

		const T &at(const Key &key) const
		{
			return _tree.template at<Key, T>(key);
		}

		T &operator[](const Key &key)
		{
			return _tree.template operator[]<Key, T>(key);
		}

	//******************************************************************************************************//
	//												Iterators									    		//
	//******************************************************************************************************//
	
		iterator begin(void)
		{
			return _tree.begin();
		}

		const_iterator begin(void) const
		{
			return _tree.begin();
		}

		iterator end(void)
		{
			return _tree.end();
		}

		const_iterator end(void) const
		{
			return _tree.end();
		}

		reverse_iterator rbegin(void)
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin(void) const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend(void)
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend(void) const
		{
			return const_reverse_iterator(begin());
		}

	//******************************************************************************************************//
	//												Capacity									    		//
	//******************************************************************************************************//

		bool empty(void) const
		{
			return _tree.empty();
		}

		size_type size(void) const
		{
			return _tree.size();
		}

		size_type max_size(void) const
		{
			return _tree.max_size();
		}

	//******************************************************************************************************//
	//												Lookup										    		//
	//******************************************************************************************************//

		size_type count(const Key &key) const
		{
			return _tree.count(key);
		}

		iterator find(const Key &key)
		{
			return _tree.find(key);
		}

		const_iterator find(const Key &key) const
		{
			return _tree.find(key);
		}

		pair<iterator, iterator> equal_range(const Key &key)
		{
			return _tree.equal_range(key);
		}

		pair<const_iterator, const_iterator> equal_range(const Key &key) const
		{
			return _tree.equal_range(key);
		}

		iterator lower_bound(const Key &key)
		{
			return _tree.lower_bound(key);
		}

		const_iterator lower_bound(const Key &key) const
		{
			return _tree.lower_bound(key);
		}

		iterator upper_bound(const Key &key)
		{
			return _tree.upper_bound(key);
		}

		const_iterator upper_bound(const Key &key) const
		{
			return _tree.upper_bound(key);
		}

	//******************************************************************************************************//
	//												Observers									    		//
	//******************************************************************************************************//

		key_compare key_comp(void) const
		{
			return Compare();
		}

		value_compare value_comp(void) const
		{
			return value_compare(Compare());
		}

	private:
		rb_tree			_tree;
		allocator_type	_allocator;
		Compare			_compare;
	};

	//******************************************************************************************************//
	//											No member functions								    		//
	//******************************************************************************************************//

  	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator==(const map<Key,T,Compare,Alloc> &lhs ,const map<Key,T,Compare,Alloc> &rhs)
	{
		typename map<Key, T, Compare, Alloc>::const_iterator lhs_it = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator rhs_it = rhs.begin();

		if (lhs.size() != rhs.size())
			return 0;

		while (lhs_it != lhs.end())
		{
			if (*lhs_it != *rhs_it)
				return 0;
				
			++lhs_it;
			++rhs_it;
		}
		
		return 1;
	}

  	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

  	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

  	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator<=(const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

  	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
	{
		return (!(lhs < rhs) && !(lhs == rhs));
	}

  	template<typename Key, typename T, typename Compare, typename Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc> &lhs, const map<Key,T,Compare,Alloc> &rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}

  	template<typename Key, typename T, typename Compare, typename Alloc>
	void swap(map<Key,T,Compare,Alloc> &lhs, map<Key,T,Compare,Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
