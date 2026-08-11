#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &copy) : arr(new T[copy._size]), _size(copy._size)
{
	unsigned int i = 0;
	while (i < _size)
	{
		arr[i] = copy.arr[i];
		i++;
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}
template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
	unsigned int i = 0;
	if (this != &copy)
	{
		delete[] arr;
		_size = copy._size;
		arr = new T[_size];
		while (i < _size)
		{
			arr[i] = copy.arr[i];
			i++;
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (arr[i]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}

#endif