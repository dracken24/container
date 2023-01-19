/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:57:08 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/19 16:32:02 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_HPP
# define CONTAINER_HPP

// For the sake of the project, I'm including all the files here.

// Functions //
#include "functions/lexicographicalCompare.hpp"
#include "functions/isIntegral.hpp"
#include "functions/enableIf.hpp"
#include "functions/equal.hpp"
#include "functions/pair.hpp"

// Containers //
#include "templates/Iterator.hpp"
#include "templates/Vector.hpp"
#include "templates/Stack.hpp"
#include "templates/Map.hpp"

// Other //

#include "color.hpp"

// std Library //

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <stack>
#include <assert.h>
#include <vector>
#include <cstddef>
#include <iterator>
#include <memory>

// Functions //

void    randomAccessIteratorTestInt(void);
void    randomAccessIteratorTestFloat(void);

void	chooseVectorTests(void);
void	reverseIteratorTest(void);

void	vectorTest(void);


#endif
