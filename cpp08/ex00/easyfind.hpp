#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class ValueNotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Value not found in container";
        }
};

template <typename T>
void    easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
    std::cout << "Value " << value << " found in container" << std::endl;
}

#endif