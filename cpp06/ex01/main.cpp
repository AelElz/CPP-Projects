#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.id = 42;
	data.name = "Ayoub";

	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);

	std::cout << "original address     : " << &data << std::endl;
	std::cout << "serialized value     : " << raw << std::endl;
	std::cout << "deserialized address : " << ptr << std::endl;
	std::cout << std::endl;

	if (ptr == &data)
		std::cout << "OK : the pointers are the same" << std::endl;
	else
		std::cout << "KO : the pointers are different" << std::endl;

	std::cout << "id   : " << ptr->id << std::endl;
	std::cout << "name : " << ptr->name << std::endl;

	return (0);
}
