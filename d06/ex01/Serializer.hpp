#pragma once

#include <iostream>
#include <string>
#include <cstdint>

typedef struct Data
{
	std::string	str;
	int			val;
}	Data;

class Serializer {
public:
	static uintptr_t	serialize(Data *ptr);
	static Data 		*deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &rhs);
	virtual ~Serializer();

};