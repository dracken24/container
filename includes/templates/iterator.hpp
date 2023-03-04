/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:09:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/03 20:37:53 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>
# include <iterator>
# include <ostream>

# include "../functions/utils.hpp"
# include "../functions/isIntegral.hpp"
# include "../functions/pair.hpp"


namespace ft
{

//******************************************************************************************************//
//											iterator_traits									    		//
//******************************************************************************************************//

  template <typename Iterator>
	struct iterator_traits
	{
	  typedef typename Iterator::iterator_category iterator_category;
	  typedef typename Iterator::value_type value_type;
	  typedef typename Iterator::difference_type difference_type;
	  typedef typename Iterator::pointer pointer;
	  typedef typename Iterator::reference reference;
	};

	template <typename Tp>
	struct iterator_traits<Tp*>
	{
	  typedef std::random_access_iterator_tag iterator_category;
	  typedef Tp value_type;
	  typedef std::ptrdiff_t difference_type;
	  typedef Tp* pointer;
	  typedef Tp& reference;
	};

	template <typename Tp>
	struct iterator_traits<const Tp*>
	{
	  typedef std::random_access_iterator_tag iterator_category;
	  typedef Tp value_type;
	  typedef std::ptrdiff_t difference_type;
	  typedef const Tp* pointer;
	  typedef const Tp& reference;
	};
	
//******************************************************************************************************//
//										random_access_iterator								    		//
//******************************************************************************************************//

	template <typename Iterator_type, typename Container>
	class random_access_iterator
	{
		

		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//
		
	};

//******************************************************************************************************//
//										Overload Not Member Functions							   		//
//******************************************************************************************************//

	

//******************************************************************************************************//
//											reverse_iterator								    		//
//******************************************************************************************************//

	template<typename Iterator_type>
	class reverse_iterator
	{
		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//
	};

//******************************************************************************************************//
//										Overload Not Member Functions							   		//
//******************************************************************************************************//

		
}

#endif
