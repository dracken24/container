/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:36:18 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/11 17:18:09 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTMAP_HPP
# define RBTMAP_HPP

# include "rbtIterator.hpp"
# include "../templates/iterator.hpp"

namespace ft
{
	template <typename value_type, typename Compare, typename Allocator>
	class rb_tree
	{
	//******************************************************************************************************//
	//											Member Types									    		//
	//******************************************************************************************************//
	public:
		typedef rbt_node<value_type>												tree_node;
		typedef tree_node															*tree_node_ptr;
		typedef Allocator															pair_allocator;
		typedef typename pair_allocator::difference_type							pair_difference_type;
		typedef typename Allocator::template rebind<rbt_node<value_type> >::other	node_allocator;
		typedef typename node_allocator::difference_type							node_difference_type;
		
		typedef rbt_iterator<value_type, Compare>									iterator;
		typedef const rbt_iterator<value_type, Compare>								const_iterator;
		typedef typename ft::reverse_iterator<iterator>								reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		typedef typename node_allocator::size_type									size_type;
		typedef Compare																value_compare;

		
	//******************************************************************************************************//
	//										Constructor - Destructor							    		//
	//******************************************************************************************************//
	public:

		rb_tree(const Compare &comp = Compare(), const pair_allocator &alloc = pair_allocator()) :
		_end_node(construct_node()),
		_root_node(NULL),
		_node_alloc(node_allocator()),
		_pair_alloc(alloc),
		_comp(comp),
		_size(0)
		{

		}

		template <typename InputIt>
		rb_tree(InputIt first, InputIt last, const Compare &comp = Compare(), const pair_allocator &alloc = pair_allocator()) :
		_end_node(construct_node()),
		_root_node(NULL),
		_node_alloc(node_allocator()),
		_pair_alloc(alloc),
		_comp(comp),
		_size(0)
		{
			insert(first, last);
		}

		rb_tree(const rb_tree &other) :
		_end_node(construct_node()),
		_root_node(NULL),
		_node_alloc(other._node_alloc),
		_pair_alloc(other._pair_alloc),
		_comp(other._comp),
		_size(0)
		{
			insert(other.begin(), other.end());
		}

		~rb_tree()
		{
			delete_tree(_end_node);
			_node_alloc.deallocate(_end_node, 1);
		}

		rb_tree &operator=(const rb_tree &other)
		{
			rb_tree tmp(other);
			swap(tmp);

			return *this;
		}

	//******************************************************************************************************//
	//											Getters - Setters								    		//
	//******************************************************************************************************//
	
		pair<iterator, bool> insert(const value_type &value)
		{

			tree_node_ptr node_constructed;
			bool can_construct;

			if (_root_node == NULL)
			{
				_root_node = construct_node(value, _end_node);
				_root_node->is_black = true;
				_end_node->left = _root_node;
				node_constructed = _root_node;
				can_construct = true;

				return pair<iterator, bool>(iterator(node_constructed), can_construct);
			}

			pair<tree_node_ptr, bool> parent_node = find_parent_pos(value, _root_node);

			if (parent_node.second == false)
			{
				node_constructed = parent_node.first;
				can_construct = false;

				return pair<iterator, bool>(iterator(node_constructed), can_construct);
			}

			if (_comp(value.first, parent_node.first->data.first) == true)
			{
				parent_node.first->left = construct_node(value, parent_node.first);
				node_constructed = parent_node.first->left;
				can_construct = true;
			}
			else
			{
				parent_node.first->right = construct_node(value, parent_node.first);
				node_constructed = parent_node.first->right;
				can_construct = true;
			}

			if (node_constructed->parent->is_black == true)
			{
				return pair<iterator, bool>(iterator(node_constructed), can_construct);
			}

			rbt_insertion(node_constructed);

			return pair<iterator, bool>(iterator(node_constructed), can_construct);
		}

		iterator insert(iterator hint, const value_type &value)
		{
			tree_node_ptr hint_node = hint.base();

			if (hint == end())
				return insert(value).first;
			if (_root_node == NULL)
			{
				_root_node = construct_node(value, _end_node);
				return iterator(_root_node);
			}
			if (_comp(hint->first, value.first) && _comp(value.first, get_next_node(hint_node)->data.first))
			{
				if (!hint_node->right)
				{
					hint_node->right = construct_node(value, hint_node);

					return iterator(hint_node->right);
				}
				else
				{
					hint_node->right->left = construct_node(value, hint_node->right);

					return iterator(hint_node->right->left);
				}
			}
			else
				return insert(value).first;
		}

		template <typename InputIt> void insert(InputIt first, InputIt last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		}

		iterator erase(iterator pos)
		{
			if (pos == end())
				return pos;

			tree_node_ptr node = pos.base();

			if (!node->left && !node->right)
			{
				check_black(node);

				tree_node_ptr next_node = get_next_node(node);

				delete_node(node);

				return iterator(next_node);
			}
			else
			{
				tree_node_ptr next_node = get_next_node(node);
				tree_node_ptr prev_node = get_prev_node(node);

				if (next_node == _end_node || next_node->data.first == node->data.first)
				{
					_pair_alloc.destroy(&node->data);
					_pair_alloc.construct(&node->data, prev_node->data);
					erase(--pos);

					return end();
				}
				else
				{
					_pair_alloc.destroy(&node->data);
					_pair_alloc.construct(&node->data, next_node->data);
					erase(++pos);

					return iterator(node);
				}
			}
		}

		template <typename Key>
		void erase(iterator first, iterator last)
		{

			Key last_key;

			if (last != end())
				last_key = last->first;

			while (first != last)
			{
				first = erase(first);
				if (last != end())
					last = find(last_key);
			}
		}

		template <typename Key> size_type erase(const Key &key)
		{
			iterator it = find(key);
			if (it == end())
				return 0;

			erase(it);

			return 1;
		}

		void swap(rb_tree &other)
		{
			std::swap(_end_node, other._end_node);
			std::swap(_root_node, other._root_node);
			std::swap(_node_alloc, other._node_alloc);
			std::swap(_pair_alloc, other._pair_alloc);
			std::swap(_comp, other._comp);
			std::swap(_size, other._size);
		}

		template <typename Key>
		size_type count(const Key &key) const
		{
			if (find(key) != end())
				return 1;

			return 0;
		}

	//******************************************************************************************************//
	//												Iterators									    		//
	//******************************************************************************************************//

		iterator begin()
		{
			return iterator(get_first_node(_root_node));
		}

		const_iterator begin() const
		{
			return const_iterator(get_first_node(_root_node));
		}

		iterator end()
		{ 
			return iterator(_end_node);
		}

		const_iterator end() const
		{
			return const_iterator(_end_node);
		}

		template <typename Key>
		iterator find(const Key &key)
		{

			tree_node_ptr node = _root_node;

			while (node != NULL)
			{
				if (_comp(key, node->data.first))
					node = node->left;
				else if (_comp(node->data.first, key))
					node = node->right;
				else
					return iterator(node);
			}

			return end();
		}

		template <typename Key>
		const_iterator find(const Key &key) const
		{
			tree_node_ptr node = _root_node;

			while (node != NULL)
			{
				if (_comp(key, node->data.first))
					node = node->left;
				else if (_comp(node->data.first, key))
					node = node->right;
				else
					return const_iterator(node);
			}

			return end();
		}

	//******************************************************************************************************//
	//											Element access									    		//
	//******************************************************************************************************//
	
		template <typename Key, typename T>
		T &operator[](const Key &key)
		{
			try
			{
				return at<Key, T>(key);
			}
			catch (std::out_of_range e)
			{
				return insert(ft::make_pair(key, T())).first->second;
			}
		}
	
		template <typename Key, typename Value>
		Value &at(const Key &key)
		{
			iterator it = find(key);

			if (it == end())
				throw std::out_of_range("Error: at: cannot find element");

			return it->second;
		}

		template <typename Key, typename Value>
		const Value &at(const Key &key) const
		{
			const_iterator it = find(key);

			if (it == end())
				throw std::out_of_range("Error: at: cannot find element");
				
			return it->second;
		}

	//******************************************************************************************************//
	//											Capacity and Look								    		//
	//******************************************************************************************************//

		template <typename Key>
		pair<iterator, iterator> equal_range(const Key& key)
		{
			return pair<iterator, iterator>(lower_bound(key), upper_bound(key));
		}

		template <typename Key>
		pair<const_iterator, const_iterator> equal_range(const Key &key) const
		{
			return pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
		}


		template <typename Key>
		iterator lower_bound(const Key& key)
		{
			tree_node_ptr curr_node = _root_node;
			tree_node_ptr lower_node = _end_node;

			while (curr_node != NULL && curr_node != _end_node)
			{
				if (curr_node->data.first == key)
					return iterator(curr_node);

				if (_comp(key, curr_node->data.first))
				{
					lower_node = curr_node;
					curr_node = curr_node->left;
				}
				else
					curr_node = curr_node->right;
			}

			return iterator(lower_node);
		}

		template <typename Key>
		const_iterator lower_bound(const Key& key) const
		{
			tree_node_ptr curr_node = _root_node;
			tree_node_ptr lower_node = _end_node;

			while (curr_node != NULL && curr_node != _end_node)
			{
				if (curr_node->data.first == key)
					return const_iterator(curr_node);

				if (_comp(key, curr_node->data.first))
				{
					lower_node = curr_node;
					curr_node = curr_node->left;
				}
				else
					curr_node = curr_node->right;
			}

			return const_iterator(lower_node);
		}

		template <typename Key>
		iterator upper_bound(const Key& key)
		{
			tree_node_ptr curr_node = _root_node;
			tree_node_ptr upper_node = _end_node;

			while (curr_node != NULL && curr_node != _end_node)
			{
				if (_comp(key, curr_node->data.first))
				{
					upper_node = curr_node;
					curr_node = curr_node->left;
				}
				else
					curr_node = curr_node->right;
			}

			return iterator(upper_node);
		}

		template <typename Key>
		const_iterator upper_bound(const Key& key) const
		{
			tree_node_ptr curr_node = _root_node;
			tree_node_ptr upper_node = _end_node;

			while (curr_node != NULL && curr_node != _end_node)
			{
				if (_comp(key, curr_node->data.first))
				{
					upper_node = curr_node;
					curr_node = curr_node->left;
				}
				else
					curr_node = curr_node->right;
			}

			return const_iterator(upper_node);
		}

		bool empty() const
		{
			if (_end_node->left == NULL && _end_node->right == NULL)
				return true;

			return false;
		}

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return std::min(_node_alloc.max_size() , static_cast<size_type>(std::numeric_limits<node_difference_type>::max()));
		}

		void clear()
		{
			delete_tree(_end_node);
		}

	//******************************************************************************************************//
	//											No Member Functions								    		//
	//******************************************************************************************************//
	// Play with Nodes in the tree //

	private:
		// Delete all Nodes in the tree //
		void delete_tree(tree_node_ptr node)
		{
			if (node != NULL)
			{
				delete_tree(node->left);
				delete_tree(node->right);
				if (node != _end_node)
				{
					_pair_alloc.destroy(&node->data);
					_node_alloc.deallocate(node, 1);
				}
				else if (node == _end_node)
					_end_node->left = NULL;
				if (node == _root_node)
					_root_node = NULL;
			}
			_size = 0;
		}

		// Insert a Node in the tree //
		void rbt_insertion(tree_node_ptr node)
		{
			if (node == _root_node)									// If node is root, then color it black //
				node->is_black = true;

			while (node->parent->is_black == false)
			{
				tree_node_ptr parent = get_parent(node);
				
				// Check if parent is left child //
				if (node->parent == node->parent->parent->left)
				{
					// If parent color is red, then uncle color is black //
					if (parent && parent->is_black == false)
					{
						node->parent->is_black = true;				// Color node parent black //
						parent->is_black = true;					// Color parent black //
						node->parent->parent->is_black = false;		// Color grandparent red //
						rbt_insertion(node->parent->parent);		// Insert grandparent //

						return;
					}
					// If parent color is red, then uncle color is black //
					else
					{
						// If node is right child //
						if (node == node->parent->right)
						{
							node = node->parent;					// Node is now parent //
							rotate_left(node);						// Rotate left //
						}

						node->parent->is_black = true;				// Color parent black //
						node->parent->parent->is_black = false;		// Color grandparent red //
						rotate_right(node->parent->parent);			// Rotate right //
						_root_node->is_black = true;				// Color root black //
					}
				}
				// Check if parent is right child //
				else
				{
					// If parent color is red, then parent color is black //
					if (parent && parent->is_black == false)
					{
						node->parent->is_black = true;				// Parent color is black //
						parent->is_black = true;					// parent color is black //
						node->parent->parent->is_black = false;		// Grandparent color is red //
						rbt_insertion(node->parent->parent);		// Insert grandparent //

						return;
					}
					// If parent color is red, then parent color is black //
					else
					{
						// If node is left child //
						if (node == node->parent->left)
						{
							node = node->parent;					// Node is parent //
							rotate_right(node);						// Rotate right //
						}

						node->parent->is_black = true;				// Parent color is black //
						node->parent->parent->is_black = false;		// Grandparent color is red //
						rotate_left(node->parent->parent);			// Rotate left //
						_root_node->is_black = true;				// Root color is black //
					}
				}
			}
		}
		
		int rotate_left(tree_node_ptr node_x)
		{
			if (node_x->right == NULL)
				return 0;

			tree_node_ptr node_y = node_x->right;

			if (node_x->parent->left == node_x)
				node_x->parent->left = node_y;

			else if (node_x->parent->right == node_x)
			{
				node_x->parent->right = node_y;
			}
			
			node_y->parent = node_x->parent;

			node_x->right = node_y->left;
			if (node_x->right)
				node_x->right->parent = node_x;

			node_y->left = node_x;
			node_x->parent = node_y;

			_root_node = _end_node->left;

			return 1;
		}

		int rotate_right(tree_node_ptr node_x)
		{
			if (node_x->left == NULL)
				return 0;
			tree_node_ptr node_y = node_x->left;

			if (node_x->parent->left == node_x)
				node_x->parent->left = node_y;
			else if (node_x->parent->right == node_x)
				node_x->parent->right = node_y;
			node_y->parent = node_x->parent;

			node_x->left = node_y->right;
			if (node_x->left)
				node_x->left->parent = node_x;

			node_y->right = node_x;
			node_x->parent = node_y;

			_root_node = _end_node->left;

			return 1;
		}

		// Change color of node //
		void change_color(tree_node_ptr node)
		{
			if (node)
			{
				if (node->is_black == true)
					node->is_black = false;
				else
					node->is_black = true;
			}
		}

		// Check if node is root or end node //
		tree_node_ptr get_sibbling(const tree_node_ptr node) const
		{
			if (node == _end_node || node == _root_node)
				return NULL;
			else if (node == node->parent->left)
				return node->parent->right;
			else
				return node->parent->left;
		}

		tree_node_ptr get_parent(const tree_node_ptr node) const
		{
			tree_node_ptr parent = node->parent;

			if (parent == _root_node)
				return NULL;
			if (parent == parent->parent->right)
				return parent->parent->left;
			else
				return parent->parent->right;
		}


		void delete_node(tree_node_ptr node)
		{
			if (node == node->parent->left)
			{
				node->parent->left = NULL;
			}
			else
			{
				node->parent->right = NULL;
			}
			if (node == _root_node)
				_root_node = NULL;

			_pair_alloc.destroy(&node->data);
			_node_alloc.deallocate(node, 1);
			_size--;
		}

		void check_black(tree_node_ptr node)
		{
			tree_node_ptr sibbling = get_sibbling(node);
			tree_node_ptr far_sib_child = NULL;
			tree_node_ptr near_sib_child = NULL;

			if (node->is_black == false)
				return;

			if (node == _root_node)
				return;

			// 
			if (sibbling && node == node->parent->left)
			{
				far_sib_child = sibbling->right;
				near_sib_child = sibbling->left;
			}
			else if (sibbling && node == node->parent->right)
			{
				far_sib_child = sibbling->left;
				near_sib_child = sibbling->right;
			}

			if (sibbling && sibbling->is_black)
			{
				if ((!sibbling->left || sibbling->left->is_black)
						&& (!sibbling->right || sibbling->right->is_black))
				{
					sibbling->is_black = false;
					if (!node->parent->is_black)
					{
						node->parent->is_black = true;
					}
					else if (node->parent->is_black)
					{
						check_black(node->parent);
					}
				}
				else if (near_sib_child && !near_sib_child->is_black
						&& (!far_sib_child || far_sib_child->is_black))
				{
					sibbling->is_black = false;
					near_sib_child->is_black = true;
					if (node == node->parent->left)
						rotate_right(sibbling);
					else if (node == node->parent->right)
						rotate_left(sibbling);
					check_black(node);
				}
				else if ((!near_sib_child || near_sib_child->is_black)
						&& (far_sib_child && !far_sib_child->is_black))
				{
					bool tmp_color = node->parent->is_black;

					node->parent->is_black = sibbling->is_black;
					sibbling->is_black = tmp_color;
					far_sib_child->is_black = true;
					if (node == node->parent->left)
						rotate_left(node->parent);
					else if (node == node->parent->right)
						rotate_right(node->parent);
				}
			}
			else if (sibbling && !sibbling->is_black)
			{
				if ((!sibbling->left || sibbling->left->is_black)
						&& (!sibbling->right || sibbling->right->is_black))
				{
					node->parent->is_black = false;
					sibbling->is_black = true;

					if (node == node->parent->left)
						rotate_left(node->parent);
					else if (node == node->parent->right)
						rotate_right(node->parent);

					check_black(node);
				}
			}
		}

		tree_node_ptr get_next_node(tree_node_ptr node)
		{
			if (node->right != NULL)
			{
				node = node->right;
				while (node->left != NULL)
				{
					node = node->left;
				}

				return node;
			}
			else
			{
				while (node->parent != NULL && node->parent->right == node)
				{
					node = node->parent;
				}
				node = node->parent;
				if (node == _end_node)
					return _end_node;

				return node;
			}
		}

		tree_node_ptr get_prev_node(tree_node_ptr node)
		{
			if (node->left != NULL)
			{
				node = node->left;
				while (node->right != NULL)
				{
					node = node->right;
				}

				return node;
			}
			else
			{
				while (node->parent != NULL && node->parent->left == node)
				{
					node = node->parent;
				}
				node = node->parent;

				return node;
			}
		}

		tree_node_ptr get_first_node(tree_node_ptr node) const
		{
			if (!node)
				return _end_node;
			if (node->left == NULL)
				return node;

			return get_first_node(node->left);
		}

		tree_node_ptr get_last_node(tree_node_ptr node) const
		{
			if (!node)
				return _end_node;
			if (node->right == NULL)
				return node;

			return get_last_node(node->right);
		}

		tree_node_ptr construct_node()
		{
			tree_node_ptr new_node = _node_alloc.allocate(1);

			new_node->parent = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->is_black = true;
			_size++;

			return new_node;
		}

		tree_node_ptr construct_node(const value_type &new_value)
		{
			tree_node_ptr new_node = _node_alloc.allocate(1);
			new_node->parent = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->is_black = false;
			_pair_alloc.construct(&new_node->data, new_value);
			_size++;

			return new_node;
		}

		tree_node_ptr construct_node(const value_type &new_value, const tree_node_ptr parent)
		{
			tree_node_ptr new_node = _node_alloc.allocate(1);

			new_node->parent = parent;
			new_node->left = NULL;
			new_node->right = NULL;
			new_node->is_black = false;
			_pair_alloc.construct(&new_node->data, new_value);
			_size++;

			return new_node;
		}

		pair<tree_node_ptr, bool> find_parent_pos(const value_type &value, tree_node_ptr node)
		{
			if (value.first == node->data.first)
				return pair<tree_node_ptr, bool>(node, false);

			if (_comp(value.first, node->data.first) == true)
			{
				if (node->left == NULL)
					return pair<tree_node_ptr, bool>(node, true);
				else
					return find_parent_pos(value, node->left);
			}
			else
			{
				if (node->right == NULL)
					return pair<tree_node_ptr, bool>(node, true);
				else
					return find_parent_pos(value, node->right);
			}
		}

	private:
		tree_node_ptr	_end_node;
		tree_node_ptr	_root_node;
		node_allocator	_node_alloc;
		pair_allocator	_pair_alloc;
		Compare			_comp;
		size_type		_size;
	};
};

#endif
