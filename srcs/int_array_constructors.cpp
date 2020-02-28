#include "int_array.hpp"


int_array :: int_array(size_t size)
	: data(new int[size]), size (size)
{
	for (size_t i = 0; i < size; i++)
		data[i] = 0;
};

int_array :: int_array(int_array const &orig)
	: data(new int [orig.size]), size(orig.size)
{
	for(size_t i = 0; i < size; i++)
		data[i] = orig.data[i];
};

int_array &int_array :: operator=(int_array &orig)
{
	if (this != &orig)
	int_array(orig).swap(*this);
	return (*this);
};

int_array :: ~int_array()
{
	delete[]this->data;
};
