/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/11 11:06:08 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../functions/utils.hpp"

#include <iostream>
#include <limits>
#include <memory>
#include <iterator>

#include "iterator.hpp"

namespace ft {

  template <typename T, typename Allocator = std::allocator<T> >
    class vector {
      public:
        typedef T                                                 value_type;
        typedef Allocator                                         allocator_type;
        typedef typename allocator_type::difference_type          diff_type;
        typedef std::size_t                                       size_type;
        typedef std::ptrdiff_t                                    difference_type;
        typedef value_type&                                       reference;
        typedef const value_type&                                 const_reference;
        typedef T*                                                pointer;
        typedef const T*                                          const_pointer;
        typedef random_access_iterator<pointer, vector>           iterator;
        typedef random_access_iterator<const_pointer, vector>     const_iterator;
        typedef ft::reverse_iterator<iterator>                    reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>              const_reverse_iterator;

      private:
        pointer                                                   _first;
        pointer                                                   _end;
        pointer                                                   _capacity;
        allocator_type                                            _alloc;

      public:
        vector() : _first(), _end(_first), _capacity(_first), _alloc() {}
        
        explicit vector(const Allocator& alloc) : _first(NULL), _end(_first), _capacity(_first), _alloc(alloc) {}
        
        explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _first(NULL) , _end(_first) , _capacity(_first) , _alloc(alloc) {
              _capacity_check(count);
              _init_storage(value, count);
        }

        template <typename InputIt>
        vector(typename enable_if<!(is_integral<InputIt>::value), InputIt>::type first, InputIt last, const Allocator& alloc = Allocator()): 
              _first(NULL) , _end(_first) , _capacity(_first) , _alloc(alloc) {
              insert(begin(), first, last);
        }

        vector(const vector& other) : _first(NULL) , _end(_first) , _capacity(_first) , _alloc(Allocator()){
          _alloc_storage(other.capacity());
          insert(_first, other.begin(), other.end());
        }

        ~vector() {
          clear();
          if (capacity() != 0)
            _alloc.deallocate(_first, _capacity - _first);
        }

        vector& operator=(const vector& other) {
          clear();
          if (capacity() != 0)
            _alloc.deallocate(_first, _capacity - _first);
          _alloc_storage(other.capacity());
          insert(_first, other.begin(), other.end());
          return *this;
        }

        reference               operator[](size_type pos)       { return *(this->_first + pos);                 }
        const_reference         operator[](size_type pos) const { return *(this->_first + pos);                 }
        allocator_type          get_allocator() const           { return (this->_alloc);                        }
        reference               front()                         { return *begin();                              }
        const_reference         front() const                   { return *begin();                              }
        reference               back()                          { return *(end() - 1);                          }
        const_reference         back() const                    { return *(end() - 1);                          }
        iterator                begin()                         { return iterator(this->_first);                }
        const_iterator          begin() const                   { return const_iterator(this->_first);          }
        iterator                end()                           { return iterator(this->_end);                  }
        const_iterator          end() const                     { return const_iterator(this->_end);            }
        reverse_iterator        rend()                          { return reverse_iterator(this->_first);        }
        const_reverse_iterator  rend() const                    { return const_reverse_iterator(this->_first);  }
        size_type               size() const                    { return std::distance(begin(), end());         }
        bool                    empty() const                   { return begin() == end();                      }
        size_type               capacity() const                { return _capacity - _first;                    }
        void                    pop_back()                      { erase(end() - 1);                             }
        reverse_iterator        rbegin()                        { return reverse_iterator(this->_end);          }
        const_reverse_iterator  rbegin() const {
          if (empty())
            return reverse_iterator(this->_end);
          return const_reverse_iterator(this->_end);
        }

        void assign(size_type count, const T& value) {
          clear();
          if (count <= 0)
            return;
          _capacity_check(count);
          _init_storage(value, count);
        }

        template <class InputIt>
        void assign(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type last) {
          vector<value_type> tmp(first, last);
          clear();
          if (capacity() != 0) {
            _alloc.deallocate(_first, _capacity - _first);
            _first = NULL;
            _end = NULL;
            _capacity = NULL;
          }
          insert(_first, tmp.begin(), tmp.end());
        }

        reference at(size_type pos) {
          if (pos >= size()) {
            throw std::out_of_range("at(): position is greater or equal to size");
          }
          return *(_first + pos);
        }

        const_reference at(size_type pos) const {
          if (pos >= size()) {
            throw std::out_of_range("at(): position is greater or equal to size");
          }
          return *(_first + pos);
        }
        
        T* data() {
          if (empty())
            return NULL;
          return _first;
        }

        const T* data() const {
          if (empty())
            return NULL;
          return _first;
        }
        
        size_type max_size() const {
          return std::min(_alloc.max_size(), static_cast<size_type>(std::numeric_limits<diff_type>::max()));
        }

        void reserve(size_type size) {
          pointer first, last;
          if (size > max_size()){
            throw std::length_error("Can't reserve vector size: bigger than max_size()");
          }
          if (size == 0)
            size = 1;
          if (size <= capacity())
            return;
          first = _alloc.allocate(size);
          last = _copy_storage(first, _first, _end);
          clear();
          if (_capacity != _first)
            _alloc.deallocate(_first, _capacity - _first);
          _first = first;
          _end = last;
          _capacity = _first + size;
        }

        void clear(){
          if (empty() == false)
            _destroy_storage(_first, _end);
          _end = _first;
        }

        void insert(iterator pos, size_type count, const T& value)
        {
          if (count <= 0)
            return;
          size_type offset = pos - begin();
          _capacity_check(size() + count);
          for (size_type i = 0; i < count; ++i)
            _alloc.construct(_end + i, value_type());
          pos = begin() + offset;
          size_type end_len = size() + count;
          pointer first = pos.base();
          pointer last = end().base();
          pointer end = (begin() + end_len).base();
          std::copy_backward(first, last, end);
          for (size_type i = 0; i < count; ++i, ++pos) {
            *pos = value;
          }
          _end += count;
        }

        iterator insert(iterator pos, const T& value){
          difference_type offset = pos - begin();
          _capacity_check(size() + 1);
          _alloc.construct(end().base(), T());
          pointer last = _end;
          pointer first = _first + offset;
          pointer end = last + 1;
          std::copy_backward(first, last, end);
          *(_first + offset) = value;
          _end++;
          return begin() + offset;
        }

        template <typename InputIt>
        void insert(iterator pos , typename enable_if<!(is_integral<InputIt>::value), InputIt>::type first , InputIt last) {
            typedef typename iterator_traits<InputIt>::iterator_category Iter_category;
            _insert(pos, first, last, Iter_category());
          }

        iterator erase(iterator i) {
          if (i == end())
            return i;
          pointer first = (i + 1).base();
          pointer last = _end;
          pointer end = i.base();
          std::copy(first, last, end);
          _alloc.destroy(_end - 1);
          --_end;
          return i;
        }

        iterator erase(iterator first, iterator last) {
          size_type i = std::distance(first, last);
          size_type new_size = size() - i;
          size_type ret = last - begin() - i;
          pointer start = last.base();
          pointer end = _end;
          pointer res = first.base();
          std::copy(start, end, res);
          for (pointer destroy_pointer = _first + new_size; destroy_pointer != _end; ++destroy_pointer)
            _alloc.destroy(destroy_pointer);
          _end -= i;
          return (begin() + ret);
        }

        void push_back(const T& value) {
          _capacity_check(size() + 1);
          if (_first == NULL) {
            _alloc.construct(_first, value);
            _end = _first + 1;
          } else {
            _alloc.construct(_end, value);
            _end++;
          }
        }

        void resize(size_type count, T value = T()) {
          if (count > size()){
            _capacity_check(count);
            for (iterator i = end(); static_cast<size_type>(i - begin()) < count; ++i)
              _alloc.construct(i.base(), value);
            _end = begin().base() + count;
          }
          else if (count < size()) {
            _destroy_storage(begin() + count, end());
            _end = begin().base() + count;
          }
        }

        void swap(vector& other)
        {
          std::swap(_first, other._first);
          std::swap(_end, other._end);
          std::swap(_capacity, other._capacity);
        }

      private:

        void _alloc_storage(size_type count) {
          if (count <= 0)
            return;
          _first = _alloc.allocate(count);
          _end = _first;
          _capacity = _first + count;
        }

        iterator _init_storage(const T& value, size_type count) {
          size_type i = 0;
          for (; i < count; ++i) {
            _alloc.construct(_first + i, value);
          }
          _end = _first + i;
          return _end;
        }

          pointer _copy_storage(pointer dst, pointer it, pointer ite)
          {
            int i = 0;
            for (; it + i != ite; ++i)
            {
              _alloc.construct(dst + i, *(it + i));
            }
            return dst + i;
          }
//
        void _destroy_storage(iterator a, iterator b){
          for (; a != b; ++a){
            _alloc.destroy(a.base());
          }
        }

        template <typename InputIt>
          void _insert(iterator pos, InputIt first, InputIt last, std::input_iterator_tag)
          {
            difference_type offset = pos - begin();
            vector<value_type, allocator_type> tmp(begin(), end());
            iterator it = tmp.begin();

            clear();
            for (difference_type i = 0; i < offset; ++i, ++it)
            {
              push_back(*it);
            }
            for (; first != last; ++first)
            {
              push_back(*first);
            }
            for (; it != tmp.end(); ++it)
            {
              push_back(*it);
            }
          }

        template<typename InputIt>
          void _insert(iterator pos, InputIt first, InputIt last, std::forward_iterator_tag)
          {
            size_type offset = pos - begin();
            size_type count = 0;

            count = std::distance(first, last);

            if (size() + count > max_size())
              throw std::length_error("Can't reserve vector size: bigger than max_size()");

            size_type end_len = size() + count;

            _capacity_check(size() + count);
            for (size_type i = 0; i < count; ++i)
            {
              _alloc.construct(_end + i, value_type());
            }
            pos = begin() + offset;

            pointer first_copy = pos.base();
            pointer last_copy = end().base();
            pointer d_last_copy = (begin() + end_len).base();

            std::copy_backward(first_copy, last_copy, d_last_copy);

            for (; first != last; ++first, ++pos)
            {
              *pos = *first;
            }
            _end += count;
          }

        /*
         * Allocates twice the current storage until total storage is greater
         * than new_cap. new_cap represents the total storage elements needed
         */
        void _capacity_check(size_type new_cap)
        {
          if (new_cap > max_size()){
            throw std::length_error("Can't reserve vector size: bigger than max_size()");
          }
          while (new_cap > capacity()) {
              reserve(capacity() * 2);
          }
        }
    };

  template <typename T, typename Alloc>
    bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
    {
      return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

  template <typename T, typename Alloc>
    bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
    {
      return !(lhs == rhs);
    }

  template <typename T, typename Alloc>
    bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
    {
      return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

  template <typename T, typename Alloc>
    bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
    {
      return (lhs < rhs || lhs == rhs);
    }

  template <typename T, typename Alloc>
    bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
    {
      return (!(lhs < rhs) && !(lhs == rhs));
    }

  template <typename T, typename Alloc>
    bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
    {
      return (lhs > rhs || lhs == rhs);
    }

  template <typename T, typename Alloc>
    void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
    {
      lhs.swap(rhs);
    }
}

#endif
