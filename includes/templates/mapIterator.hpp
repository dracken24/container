/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:58:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/07 19:12:58 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "../functions/pair.hpp"

namespace ft
{
	template <bool isConst, typename isFalse, typename isTrue>
	struct chooseConst {};

	template <typename isFalse, typename isTrue>
	struct chooseConst<false, isFalse, isTrue>
	{
		typedef isFalse type;
	};

	template <typename isFalse, typename isTrue>
	struct chooseConst<true, isFalse, isTrue>
	{
		typedef isTrue type;
	};
	
	template <class Key, class T, class Compare, typename Node, bool B>
	class map_iterator
	{
		public:
		
			typedef T												mapped_type;
			typedef Key												key_type;
			typedef Compare											key_compare;
			
			typedef size_t											size_type;
			typedef long int										difference_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			
			typedef typename chooseConst<B, value_type&, const value_type &>::type		reference;
			typedef typename chooseConst<B, value_type*, const value_type *>::type		pointer;
			typedef Node*																nodePtr;


		public:

			map_iterator(nodePtr node = 0, nodePtr lastElem = 0, 
						const key_compare &comp = key_compare()) :
			_node(node),
			_lastElem(lastElem),
			_comp(comp)
			{}
		
			map_iterator(const map_iterator<Key, T, Compare, Node, false> &copy)
			{
				_node = copy.getNode();
				_lastElem = copy.getLastElem();
				_comp = copy.getCompare();
			}
			
			~map_iterator()
			{}

			map_iterator &operator=(const map_iterator &assign)
			{
				if (this != &assign)
				{
					_node = assign._node;
					_lastElem = assign._lastElem;
					_comp = assign._comp;
				}
				
				return (*this);
			}

			nodePtr getNode() const
			{
				return _node;
			}
			
			nodePtr getLastElem() const
			{
				return _lastElem;
			}

			key_compare getCompare() const
			{
				return _comp;
			}

			reference operator*() const
			{
				return (_node->content);
			}

			pointer operator->() const
			{
				return (&_node->content);
			}

			map_iterator &operator++()
			{
				nodePtr previousNode = _node;
				
				if (_node == _lastElem)
				{
					_node = _lastElem->right;
					return (*this);
				}
				while (_node != _lastElem && !_comp(previousNode->content.first, _node->content.first))
				{ 
					if (_node->right && (_node->right == _lastElem || 
							_comp(previousNode->content.first, _node->right->content.first)))
					{
						Node	*tmp = 0;
						
						_node = _node->right;
						if (_node != _lastElem && (tmp = searchMinNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				return (*this);
			}

			map_iterator operator++(int)
			{
				map_iterator res(*this);

				if (_node == _lastElem)
				{
					_node = _lastElem->right;
					return (res);
				}
				
				while (_node != _lastElem && !_comp(res->first, _node->content.first))
				{
					if (_node->right && (_node->right == _lastElem || 
							_comp(res->first, _node->right->content.first)))
					{
						_node = _node->right;
						
						Node	*tmp = 0;
						if (_node != _lastElem && (tmp = searchMinNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				
				return (res);
			}

			map_iterator &operator--()
			{
				nodePtr previousNode = _node;

				if (_node == _lastElem)
				{
					_node = _lastElem->left;
					return (*this);
				}

				while (_node != _lastElem && !_comp(_node->content.first, previousNode->content.first))
				{
					if (_node->left && (_node->left == _lastElem || 
							_comp(_node->left->content.first, previousNode->content.first)))
					{
						_node = _node->left;
						
						Node	*tmp = 0;
						if (_node != _lastElem && (tmp = searchMaxNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}

				return (*this);
			}

			map_iterator operator--(int)
			{
				map_iterator res(*this);

				if (_node == _lastElem)
				{
					_node = _lastElem->left;
					return (res);
				}
				
				while (_node != _lastElem && !_comp(_node->content.first, res->first))
				{
					if (_node->left && (_node->left == _lastElem || 
							_comp(_node->left->content.first, res->first)))
					{
						Node	*tmp = 0;
						
						_node = _node->left;
						if (_node != _lastElem && (tmp = searchMaxNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				
				return (res);
			}

			bool operator==(const map_iterator &it) const
			{
				return (it._node == _node);
			}
			
			bool operator!=(const map_iterator &it) const
			{
				return (it._node != _node);
			}
			
		// Member functions
		private:

			Node *searchMaxNode(Node *root)
			{
				if (root && root != _lastElem && root->right && root->right != _lastElem)
				
					return searchMaxNode(root->right);
				return root;
			}

			Node *searchMinNode(Node *root)
			{
				if (root && root != _lastElem && root->left && root->left != _lastElem)
					return searchMinNode(root->left);
					
				return root;
			}
			
		private:

			nodePtr         _node;      // Pointer to a binary tree's node
			nodePtr         _lastElem;  // Pointer to the dummy node of binary tree
			key_compare     _comp;      // Comparison object used to sort the binary tree
	};

	template<class Key, class T, class Compare, typename Node, bool B>
	class rev_map_iterator
	{
		public:
		
			typedef Key                                             key_type;
			typedef Compare                                         key_compare;
			typedef T                                               mapped_type;
			
			typedef ft::pair<const key_type, mapped_type>           value_type;
			typedef long int                                        difference_type;
			typedef size_t                                          size_type;
			
			typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
			typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
			typedef Node*                                                               nodePtr;
			


		public:
		
			rev_map_iterator(nodePtr node = 0, nodePtr lastElem = 0,
							const key_compare& comp = key_compare()) :
			_node(node),
			_lastElem(lastElem),
			_comp(comp)
			{}
		
			rev_map_iterator(const rev_map_iterator<Key, T, Compare, Node, false> &copy)
			{
				_node = copy.getNonConstNode();
				_lastElem = copy.getNonConstLastElem();
				_comp = copy.getCompare();
			}
			
			explicit rev_map_iterator(map_iterator<Key, T, Compare, Node, false> copy)
			{
				--copy;
				_node = copy.getNonConstNode();
				_lastElem = copy.getNonConstLastElem();
				_comp = copy.getCompare();
			}

			~rev_map_iterator()
			{}

			rev_map_iterator& operator=(const rev_map_iterator& assign)
			{
				if (this != &assign)
				{
					_node = assign._node;
					_lastElem = assign._lastElem;
					_comp = assign._comp;
				}
				return (*this);
			}

			// Getters //
			
			nodePtr getNonConstNode() const
			{
				return _node;
			}

			nodePtr getNonConstLastElem() const
			{
				return _lastElem;
			}

			key_compare getCompare() const
			{
				return _comp;
			}

			reference operator*() const
			{
				return (_node->content);
			}
			
			pointer operator->() const
			{
				return (&_node->content);
			}

			rev_map_iterator& operator++()
			{
				nodePtr previousNode = _node;

				if (_node == _lastElem)
				{
					_node = _lastElem->left;
					return (*this);
				}

				while (_node != _lastElem && !_comp(_node->content.first, previousNode->content.first))
				{
					if (_node->left && (_node->left == _lastElem || 
							_comp(_node->left->content.first, previousNode->content.first)))
					{
						Node* tmp = 0;
						
						_node = _node->left;
						if (_node != _lastElem && (tmp = searchMaxNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}

				return (*this);
			}

			rev_map_iterator operator++(int)
			{
				rev_map_iterator res(*this);

				if (_node == _lastElem)
				{
					_node = _lastElem->left;
					return (res);
				}
				
				while (_node != _lastElem && !_comp(_node->content.first, res->first))
				{
					if (_node->left && (_node->left == _lastElem || 
							_comp(_node->left->content.first, res->first)))
					{
						Node	*tmp = 0;
						
						_node = _node->left;
						if (_node != _lastElem && (tmp = searchMaxNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				
				return (res);
			}

			rev_map_iterator &operator--()
			{
				nodePtr previousNode = _node;

				if (_node == _lastElem)
				{
					_node = _lastElem->right;
					return (*this);
				}

				while (_node != _lastElem && !_comp(previousNode->content.first, _node->content.first))
				{ 
					if (_node->right && (_node->right == _lastElem || 
							_comp(previousNode->content.first, _node->right->content.first)))
					{
						Node	*tmp = 0;
						
						_node = _node->right;
						if (_node != _lastElem && (tmp = searchMinNode(_node)))
							_node = tmp;
					}

					else
						_node = _node->parent;
				}
				return (*this);
			}

			rev_map_iterator operator--(int)
			{
				rev_map_iterator res(*this);

				if (_node == _lastElem)
				{
					_node = _lastElem->right;
					return (res);
				}
				
				while (_node != _lastElem && !_comp(res->first, _node->content.first))
				{
					if (_node->right && (_node->right == _lastElem || 
							_comp(res->first, _node->right->content.first)))
					{
						_node = _node->right;
						
						Node	*tmp = 0;
						if (_node != _lastElem && (tmp = searchMinNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				
				return (res);
			}

			bool operator==(const rev_map_iterator &it) const
			{
				return (it._node == _node);
			}
			
			bool operator!=(const rev_map_iterator &it) const
			{
				return (it._node != _node);
			}

		// Member functions
		private:

			Node *searchMaxNode(Node *root)
			{
				if (root && root != _lastElem && root->right && root->right != _lastElem)
					return searchMaxNode(root->right);
					
				return root;
			}

			Node *searchMinNode(Node *root)
			{

				if (root && root != _lastElem && root->left && root->left != _lastElem)
					return searchMinNode(root->left);
					
				return root;
			}
		
		private:

			nodePtr         _node;      // Pointer to a binary tree's node
			nodePtr         _lastElem;  // Pointer to the dummy node of binary tree
			key_compare     _comp;      // Comparison object used to sort the binary tree
	};
};
