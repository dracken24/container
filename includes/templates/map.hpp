/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:54 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/05 20:35:03 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_HPP
# define MAP_HPP

#include <functional>
#include <cmath>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>

# include "../functions/utils.hpp"
# include "../templates/iterator.hpp"

namespace ft
{
	template<typename Key, typename T>
	class _node
	{
		public:
			_node(Key k, T value)
			{
				pair = ft::make_pair(k, value);
			};
		
		private:
			_node				*left;
			_node				*right;

			ft::pair<Key, T>	pair;
	};

  	template <typename Key, typename T, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::_node<Key, T>>> // typename Allocator = std::allocator<ft::pair<const Key, T>>>
	class map
	{
		public:
			typedef Key														key_type;				// key_type	The first template parameter (Key)	
			typedef T														mapped_type;			// mapped_type	The second template parameter (T)	
			typedef ft::pair<const Key, T>									value_type;				// value_type	pair<const key_type,mapped_type>	
			typedef Compare													key_compare;			// key_compare	The third template parameter (Compare)	defaults to: less<key_type>
			typedef Allocator												allocator_type;			// allocator_type	The fourth template parameter (Alloc)	defaults to: allocator<value_type>

			typedef value_type												&reference;				// reference	allocator_type::reference	for the default allocator: value_type&
			typedef const value_type										&const_reference;		// const_reference	allocator_type::const_reference	for the default allocator: const value_type&
			typedef typename Allocator::pointer								pointer;				// pointer	allocator_type::pointer	for the default allocator: value_type*
			typedef typename Allocator::const_pointer						const_pointer;			// const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
			
			typedef std::bidirectional_iterator_tag							iterator;				// iterator	a bidirectional iterator to value_type	convertible to const_iterator
			typedef const std::bidirectional_iterator_tag					const_iterator;			// const_iterator	a bidirectional iterator to const value_type	
			typedef typename std::reverse_iterator<iterator>				reverse_iterator;		// reverse_iterator	reverse_iterator<iterator>	
			typedef typename std::reverse_iterator<const_iterator>			const_reverse_iterator;	// const_reverse_iterator	reverse_iterator<const_iterator>	
			
			typedef std::ptrdiff_t											difference_type;		// difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
			typedef std::size_t												size_type;				// size_type	an unsigned integral type that can represent any non-negative value of difference_type
			
			class value_compare
			{		
				public:
					bool	getCompare(void)
					{
						if (_comp1._second > _comp2._second)
							return (true);
						
						return (false);
					}

				private:
					ft::pair<Key, T>	_comp1;
					ft::pair<Key, T>	_comp2;

					value_compare(ft::pair<Key, T> comp1, ft::pair<Key, T> comp2) :
					_comp1(comp1), _comp2(comp2)
					{ };
			};
		

	//******************************************************************************************************//
	//										Constructor - Destructor							    		//
	//******************************************************************************************************//

		public:
			explicit map(const key_compare &compare = key_compare(), const allocator_type &alloc = allocator_type());
			
			template <class InTerator>
			map(InTerator first, InTerator last, const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type());
				
			map(const map &src);
			
			~map(void);

			map	&operator=(const map &src);

			mapped_type	&operator[](const key_type &palce);
		
		//******************************************************************************************************//
		//												Find										    		//
		//******************************************************************************************************//

			// at
			reference		&at(const key_type &k_type);
			
			const_reference	&at(const key_type &k_type) const;

			// Set the way to compare your keys, ex.: lenght of a string or number of the key...
			key_compare		key_comp(void) const;

			// Same as key_comp but with the value
			value_compare	value_comp(void) const;

			// Find an element in map with is key value
			iterator		find(const key_type &k_type);
			
			const_iterator	find(const key_type &k_type) const;

			// Return the number of element with the same key in the map
			size_type		count(const key_type &k_type) const;

			// Return the iterator to the first element in map upper or equal to k_type
			iterator		lower_bound(const key_type &k_type);
			
			const_iterator	lower_bound(const key_type &k_type) const;

			// Same as lower_bound but return the upper k_type, even if key is equal to an other
			iterator		upper_bound(const key_type &k_type);
			
			const_iterator	upper_bound(const key_type &k_type) const;

			// Return an iterator to an element if find it, else, return an iterator where
			// the key can be insert in the map
			pair<const_iterator,const_iterator>	equal_range(const key_type &k_type) const;

			pair<iterator,iterator>	equal_range(const key_type &k_type);
		
		//******************************************************************************************************//
		//												Modifiers									    		//
		//******************************************************************************************************//


			// insert(): This function is used to add a new element before a specified position inside the map.
			pair<iterator, bool>	insert(const value_type &value);

			iterator	insert(iterator position, const value_type& value);
			
			template <class InTerator>
			void		insert(InTerator first, InTerator last);

			// erase(): It is used to remove the element from the container at a specified position or a range.
			void		erase(iterator position);
			
			size_type	erase(const key_type &k_type);

			void		erase(iterator first, iterator last);

			// swap(): It is used to swap the contents between the maps, but it should be of the same type.
			void	swap(map &k_map);
			
			// clear(): This function is used to remove all elements from the maps.
			void	clear(void);
			
		//******************************************************************************************************//
		//												Iterators									    		//
		//******************************************************************************************************//

			// begin(): This function returns the iterator to the first element of the map container.
			iterator		begin(void);
			
 			const_iterator	begin(void) const;
			
			// end(): This function returns the iterator to the last element of the map container.
			iterator		end(void);
			
 			const_iterator	end(void) const;

			// rbegin(): This function is similar to the begin() function; the only difference is that
			// it cannot change or modify the content it is pointing to.
			reverse_iterator		rbegin(void);
			
 			const_reverse_iterator	rbegin(void) const;

			// rend(): This function also returns the iterator to the last element of the map,
			// just like the end() function, but the difference is it cannot modify the content it is pointing to.
			reverse_iterator		rend(void);
			
 			const_reverse_iterator	rend(void) const;
			
		//******************************************************************************************************//
		//												Capacity									    		//
		//******************************************************************************************************//

			// size(): This function is used to return the number of elements inside the map.
			size_type	size(void) const;
			
			// max_size(): It is used to return the maximum size allow in your pc for allocation.
			size_type	max_size(void) const;
			
			// empty(): It checks whether the map is empty or not, and it returns true if a map is empty else it returns false.
			bool	empty(void) const;
			
		private:
			pointer			_first;
			pointer			_end;
			
			Compare			_comp;
			size_type		_size;
			allocator_type	_alloc;
	};
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator==(const map<Key,T,Compare,Alloc> &src1 ,const map<Key,T,Compare,Alloc> &src2);

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator!=(const map<Key,T,Compare,Alloc> &src1 ,const map<Key,T,Compare,Alloc> &src2);

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>(const map<Key,T,Compare,Alloc> &src1 ,const map<Key,T,Compare,Alloc> &src2);

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>=(const map<Key,T,Compare,Alloc> &src1 ,const map<Key,T,Compare,Alloc> &src2);

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<(const map<Key,T,Compare,Alloc> &src1 ,const map<Key,T,Compare,Alloc> &src2);

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<=(const map<Key,T,Compare,Alloc> &src1 ,const map<Key,T,Compare,Alloc> &src2);

	template<typename Key, typename T, typename Compare, typename Alloc>
	void	swap(map<Key,T,Compare,Alloc> &src1, map<Key,T,Compare,Alloc> &src2);
};

#endif
