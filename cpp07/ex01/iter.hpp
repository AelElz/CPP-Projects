#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>

void iter(T *array, size_t length, F f)
{
	size_t i = 0;
	while (i < length)
	{
		f(array[i]);
		i++;
	}
}

#endif
