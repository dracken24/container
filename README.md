# Implement the following containers and turn in the necessary <container>.hpp

• vector

		- You don’t have to do the vector<bool> specialization
• map

• stack

		- It will use your vector class as default underlying container.


# You also have to implement

• iterator_traits

• reverse_iterator

• enable_if

		- Yes, it is C++11 but you will be able to implement it in a C++98 manner.
		  This is asked so you can discover SFINAE.
• is_integral

• equal and/or lexicographical_compare

• std::pair

• std::make_pair

# VECTOR______________________________________
https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170
	
https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-vector
## (constructor)
- [x] explicit vector (const allocator_type& alloc = allocator_type());
- [x] explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
- [x] template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
- [x] vector (const vector& x);
## (destructor)
## operator=
- [x] vector& operator= (const vector& x);
## begin
- [x] iterator begin()
- [x] const_iterator begin() const;
## end
- [x] iterator end()
- [x] const_iterator end() const;
## rbegin
- [x] reverse_iterator rbegin()
- [x] const_reverse_iterator rbegin() const;
## rend
- [x] reverse_iterator rend()
- [x] const_reverse_iterator rend() const;
## size
- [x] size_type size() const;
## max_size
- [x] size_type max_size() const;
## resize
- [x] void resize (size_type n, value_type val = value_type());
## capacity
- [x] size_type capacity() const;
## empty
- [x] bool empty() const;
## reserve
- [x] void reserve (size_type n);
## operator[]
- [x] reference operator[] (size_type n)
- [x] const_reference operator[] (size_type n) const;
## at
- [x] reference at (size_type n)
- [x] const_reference at (size_type n) const;
## front
- [x] reference front()
- [x] const_reference front() const;
## back
- [x] reference back()
- [x] const_reference back() const;
## assign
- [x] template <class InputIterator> void assign (InputIterator first, InputIterator last);
- [x] void assign (size_type n, const value_type& val);
## push_back
- [x] void push_back (const value_type& val);
## pop_back
- [x] void pop_back();
## insert
- [x] iterator insert (iterator position, const value_type& val);
- [x] void insert (iterator position, size_type n, const value_type& val);
- [x] template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);
## erase
- [x] iterator erase (iterator position)
- [x] iterator erase (iterator first, iterator last);
## clear
- [x] void clear();
## swap
- [x] void swap(Vector &x);
## relational operators
- [x] template <class T, class Alloc> bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
## swap
- [x] template <class T, class Alloc> void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

# MAP_______________________________________
## (constructor)
- [x] explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
- [x] template <class InputIterator> map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
- [x] map (const map& x);
## (destructor)
- [x] ~map (void);
## operator=
- [x] map& operator= (const map& x);
## begin
- [x] iterator begin()
- [x] const_iterator begin() const;
## end
- [x] iterator end()
- [x] const_iterator end() const;
## rbegin
- [x] reverse_iterator rbegin()
- [x] const_reverse_iterator rbegin() const;
## rend
- [x] reverse_iterator rend()
- [x] const_reverse_iterator rend() const;
## empty
- [x] bool empty() const;
## size
- [x] size_type size() const;
## max_size
- [x] size_type max_size() const;
## operator[]
- [x] mapped_type& operator[] (const key_type& k);
## insert
- [x] pair<iterator,bool> insert (const value_type& val);
- [x] iterator insert (iterator position, const value_type& val);
- [x] template <class InputIterator> void insert (InputIterator first, InputIterator last);
## erase
- [x] void erase (iterator position);
- [x] size_type erase (const key_type& k);
- [x] void erase (iterator first, iterator last);
## swap
- [x] void swap (map& x);
## clear
- [x] void clear();
## key_comp
- [x] key_compare key_comp() const;
## value_comp
- [x] value_compare value_comp() const;
## find
- [x] iterator find (const key_type& k)
- [x] const_iterator find (const key_type& k) const;
## count
- [x] size_type count (const key_type& k) const;
## lower_bound
- [x] iterator lower_bound (const key_type& k)
- [x] const_iterator lower_bound (const key_type& k) const;
## upper_bound
- [x] iterator upper_bound (const key_type& k)
- [x] const_iterator upper_bound (const key_type& k) const;
## equal_range
- [x] pair<const_iterator,const_iterator> equal_range (const key_type& k) const
- [x] pair<iterator,iterator> equal_range (const key_type& k);

# STACK_______________________________________
## (constructor)
- [x] explicit stack (const container_type& ctnr = container_type());
## empty
- [x] bool empty() const;
## size
- [x] size_type size() const;
## top
- [x] value_type& top()
- [x] const value_type& top() const;
## push
- [x] void push (const value_type& val);
## pop
- [x] void pop();
## relational operators
- [x] template <class T, class Container> bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

# LIST_________________________________________
## (constructor)
- [x] explicit list (const allocator_type& alloc = allocator_type());
- [x] explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
- [x] template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
- [x] list (const list& x);
## (destructor)
## operator=
- [x] list& operator= (const list& x);
## begin
- [x] iterator begin()
- [x] const_iterator begin() const;
## end
- [x] iterator end()
- [x] const_iterator end() const;
## rbegin
- [x] reverse_iterator rbegin()
- [x] const_reverse_iterator rbegin() const;
## rend
- [x] reverse_iterator rend()
- [x] const_reverse_iterator rend() const;
## empty
- [x] bool empty() const;
## size
- [x] size_type size() const;
## max_size
- [x] size_type max_size() const;
## front
- [x] reference front()
- [x] const_reference front() const;
## back
- [x] reference back()
- [x] const_reference back() const;
## assign
- [x] template <class InputIterator> void assign (InputIterator first, InputIterator last);
- [x] void assign (size_type n, const value_type& val);
## push_front
- [x] void push_front (const value_type& val);
## pop_front
- [x] void pop_front();
## push_back
- [x] void push_back (const value_type& val);
## pop_back
- [x] void pop_back();
## insert
- [x] iterator insert (iterator position, const value_type& val);
- [x] void insert (iterator position, size_type n, const value_type& val);
- [x] template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);
## erase
- [x] iterator erase (iterator position)
- [x] iterator erase (iterator first, iterator last);
## swap
- [x] void swap (list& x);
## resize
- [x] void resize (size_type n, value_type val = value_type());
## clear
- [x] void clear();
## splice
- [x] void splice (iterator position, list& x);
- [x] void splice (iterator position, list& x, iterator i);
- [x] void splice (iterator position, list& x, iterator first, iterator last);
## remove
- [x] void remove (const value_type& val);
## remove_if
- [x] template <class Predicate> void remove_if (Predicate pred);
## unique
- [x] void unique();
- [x] template <class BinaryPredicate> void unique (BinaryPredicate binary_pred);
## merge
- [x] void merge (list& x);
- [x] template <class Compare> void merge (list& x, Compare comp);
## sort
- [x] void sort();
- [x] template <class Compare> void sort (Compare comp);
## reverse
- [x] void reverse();
## relational operators (list)
- [x] template <class T, class Alloc> bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
## swap (list)
- [x] template <class T, class Alloc> void swap (list<T,Alloc>& x, list<T,Alloc>& y);

# QUEUE________________________________________

- [x] explicit queue (const container_type& ctnr = container_type());
## empty
- [x] bool empty() const;
## size
- [x] size_type size() const;
## front
- [x] value_type& front()
- [x] const value_type& front() const;
## back
- [x] value_type& back()
- [x] const value_type& back() const;
## push
- [x] void push (const value_type& val);
## pop
- [x] void pop();
## relational operators
- [x] template <class T, class Container> bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [x] template <class T, class Container> bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [x] template <class T, class Container> bool operator< (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [x] template <class T, class Container> bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [x] template <class T, class Container> bool operator> (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [x] template <class T, class Container> bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);