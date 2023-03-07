#include <iostream>
#include <map>
# include "myTests/includes/container.hpp"

bool compareStringLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

int main()
{
    A val = A("Ichigo", 6785, (Vector2){387, 562});
    std::map<int, A> test;

    test.insert(std::make_pair(24, val));

    A ret = test[9];

    for (typename std::map<int, A>::iterator it = test.begin(); it != test.end(); it++)
	{
		std::cout << "[" << it->first << ", " << it->second.getNbr() << "] ";
	}

    // std::cout << ret << std::endl;

    return 0;
}