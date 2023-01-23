/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:58:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/23 12:31:16 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "../functions/pair.hpp"

namespace ft
{
	template <class T>
	struct Node
	{
		T		data;
		Node	*left;
		Node	*right;
	};
	
	template <class Key, class T>
	struct BNode
	{
		ft::pair<Key, T> pair;
		
		BNode	*left;
		BNode	*right;
		BNode	*parent;
		
		bool	end;
	};
	
	template <class K, class T>
	class MapIterator
	{
		public:
			typedef ft::pair<K, T>		value_type;
			typedef ft::pair<K, T>&		reference;
			typedef BNode<K, T>*		pointer;

		public:
			MapIterator(void)
			: _ptr(0) {};
			
			MapIterator(const pointer ptr)
			: _ptr(ptr) {};
			
			MapIterator(const MapIterator &other)
			: _ptr(other._ptr) {};

			~MapIterator(void) {};
			
			MapIterator &operator=(const MapIterator &other)
			{
				if (this != &other)
					_ptr = other._ptr;
				
				return (*this);
			}
			
			pointer node(void)
			{
				return (_ptr);
			}
			
			value_type &operator*(void)
			{
				return (_ptr->pair);
			}
			
			value_type *operator->(void)
			{
				return (&(_ptr->pair));
			}
			
			bool operator==(const MapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			}
			
			bool operator!=(const MapIterator<K, T> &other)
			{
				return (_ptr != other._ptr);
			}
			
			bool operator>(const MapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			}
			
			bool operator<(const MapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			}
			
			bool operator>=(const MapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			}
			
			bool operator<=(const MapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			}
			
			MapIterator &operator++(void)
			{
				_ptr = _ptr->right;
				
				return (*this);
			}
			
			MapIterator &operator--(void)
			{
				_ptr = _ptr->left;
				
				return (*this);
			}
			
			MapIterator operator++(int)
			{
				MapIterator tmp(*this);
				_ptr = _ptr->right;
				
				return (tmp);
			}
			
			MapIterator operator--(int)
			{
				MapIterator tmp(*this);
				_ptr = _ptr->left;
				
				return (tmp);
			}
		
		protected:
			pointer _ptr;
	};

	template <class K, class T>
	class MapConstIterator
	{
		public:
			typedef ft::pair<K, T>		value_type;
			typedef ft::pair<K, T>&		reference;
			typedef ft::pair<K, T>*		pointer;
			typedef BNode<K, T>*		node_pointer;

		public:
			MapConstIterator(void)
			: _ptr(0) {};
			
			MapConstIterator(const pointer ptr)
			: _ptr(ptr) {};
			
			MapConstIterator(const MapConstIterator &other)
			: _ptr(other._ptr) {};

			~MapConstIterator(void) {};
			
			MapConstIterator &operator=(const MapConstIterator &other)
			{
				if (this != &other)
					_ptr = other._ptr;
				
				return (*this);
			}
			
			pointer node(void)
			{
				return (_ptr);
			}
			
			value_type &operator*(void)
			{
				return (_ptr->pair);
			}
			
			value_type *operator->(void)
			{
				return (&(_ptr->pair));
			}
			
			bool operator==(const MapConstIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			}
			
			bool operator!=(const MapConstIterator<K, T> &other)
			{
				return (_ptr != other._ptr);
			}
			
			bool operator>(const MapConstIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			}
			
			bool operator<(const MapConstIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			}
			
			bool operator>=(const MapConstIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			}
			
			bool operator<=(const MapConstIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			}
			
			MapConstIterator &operator++(void)
			{
				_ptr = _ptr->right;
				
				return (*this);
			}
			
			MapConstIterator &operator--(void)
			{
				_ptr = _ptr->left;
				
				return (*this);
			}
			
			MapConstIterator operator++(int)
			{
				MapConstIterator tmp(*this);
				_ptr = _ptr->right;
				
				return (tmp);
			}

			MapConstIterator operator--(int)
			{
				MapConstIterator tmp(*this);
				_ptr = _ptr->left;
				
				return (tmp);
			}

		protected:
			pointer _ptr;
	};

	template <class K, class T>
	class MapReverseIterator
	{
		public:
			typedef ft::pair<K, T>		value_type;
			typedef ft::pair<K, T>&		reference;
			typedef BNode<K, T>*		pointer;

		public:
			MapReverseIterator(void)
			: _ptr(0) {};
			
			MapReverseIterator(const pointer ptr)
			: _ptr(ptr) {};
			
			MapReverseIterator(const MapReverseIterator &other)
			: _ptr(other._ptr) {};

			~MapReverseIterator(void) {};
			
			MapReverseIterator &operator=(const MapReverseIterator &other)
			{
				if (this != &other)
					_ptr = other._ptr;
				
				return (*this);
			}
			
			pointer node(void)
			{
				return (_ptr);
			}
			
			value_type &operator*(void)
			{
				return (_ptr->pair);
			}
			
			value_type *operator->(void)
			{
				return (&(_ptr->pair));
			}
			
			bool operator==(const MapReverseIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			}
			
			bool operator!=(const MapReverseIterator<K, T> &other)
			{
				return (_ptr != other._ptr);
			}
			
			bool operator>(const MapReverseIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			}
			
			bool operator<(const MapReverseIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			}
			
			bool operator>=(const MapReverseIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			}
			
			bool operator<=(const MapReverseIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			}
			
			MapReverseIterator &operator++(void)
			{
				_ptr = _ptr->left;
				
				return (*this);
			}
			
			MapReverseIterator &operator--(void)
			{
				_ptr = _ptr->right;
				
				return (*this);
			}
			
			MapReverseIterator operator++(int)
			{
				MapReverseIterator tmp(*this);
				_ptr = _ptr->left;
				
				return (tmp);
			}

			MapReverseIterator operator--(int)
			{
				MapReverseIterator tmp(*this);
				_ptr = _ptr->right;
				
				return (tmp);
			}

		protected:
			pointer _ptr;
	};

	template <class K, class T>
	class MapConstReverseIterator
	{
		public:
			typedef ft::pair<K, T>		value_type;
			typedef ft::pair<K, T>&		reference;
			typedef ft::pair<K, T>*		pointer;
			typedef BNode<K, T>*		node_pointer;

		public:
			MapConstReverseIterator(void)
			: _ptr(0) {};
			
			MapConstReverseIterator(const pointer ptr)
			: _ptr(ptr) {};
			
			MapConstReverseIterator(const MapConstReverseIterator &other)
			: _ptr(other._ptr) {};

			~MapConstReverseIterator(void) {};
			
			MapConstReverseIterator &operator=(const MapConstReverseIterator &other)
			{
				if (this != &other)
					_ptr = other._ptr;
				
				return (*this);
			}
			
			pointer node(void)
			{
				return (_ptr);
			}
			
			value_type &operator*(void)
			{
				return (_ptr->pair);
			};
			
			value_type *operator->(void)
			{
				return (&(_ptr->pair));
			}
			
			bool operator==(const MapConstReverseIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			}
			
			bool operator!=(const MapConstReverseIterator<K, T> &other)
			{
				return (_ptr != other._ptr);
			}
			
			bool operator>(const MapConstReverseIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			}
			
			bool operator<(const MapConstReverseIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			}
			
			bool operator>=(const MapConstReverseIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			}
			
			bool operator<=(const MapConstReverseIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			}
			
			MapConstReverseIterator &operator++(void)
			{
				_ptr = _ptr->left;
				
				return (*this);
			}
			
			MapConstReverseIterator &operator--(void)
			{
				_ptr = _ptr->right;
				
				return (*this);
			}

			MapConstReverseIterator operator++(int)
			{
				MapConstReverseIterator tmp(*this);
				_ptr = _ptr->left;
				
				return (tmp);
			}

			MapConstReverseIterator operator--(int)
			{
				MapConstReverseIterator tmp(*this);
				_ptr = _ptr->right;
				
				return (tmp);
			}

		protected:
			pointer _ptr;
	};


	
};
