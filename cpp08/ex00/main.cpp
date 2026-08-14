#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void	check(T &container, int value) {
	try
    {
		easyfind(container, value);
		std::cout << value << " -> found" << std::endl;
	}
    catch (std::exception &e)
    {
		std::cout << value << " -> " << e.what() << std::endl;
	}
}

int main() {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

    int i = 0;
	while (i <= 3)
    {
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
        i++;
	}
	std::cout << "--- vector ---" << std::endl;
	check(v, 2);
	check(v, 42);

	std::cout << "--- list ---" << std::endl;
	check(l, 2);
	check(l, 42);

	std::cout << "--- deque ---" << std::endl;
	check(d, 2);
	check(d, 42);
}
