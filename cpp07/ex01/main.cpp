#include "iter.hpp"

void time_Two(int &x)
{
	x = x * 2;
}

void to_Upper(std::string &str)
{
	size_t i = 0;
	while (i < str.length())
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int main()
{
	int _int_arr[] = {1, 2, 3};
	int i;
	::iter(_int_arr, 3, time_Two);

	i = 0;
	while (i < 3)
	{
		std::cout << _int_arr[i] << std::endl;
		i++;
	}

	std::string _str_arr[] = {"Hello", "From", "World", "!"};
	::iter(_str_arr, 4, to_Upper);

	i = 0;
	while (i < 4)
	{
		std::cout << _str_arr[i] << std::endl;
		i++;
	}
}
