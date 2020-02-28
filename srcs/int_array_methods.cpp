#include "int_array.hpp"

void int_array :: swap(int_array&orig)
{
	int *tmp_arr;
	size_t tmp_size;

	tmp_size = orig.size;
	orig.size = this->size;
	this->size = tmp_size;
	tmp_arr = orig.data;
	orig.data = this->data;
	this->data = tmp_arr;
};

void int_array :: resize_data(size_t new_size)
{
	int_array new_obj(new_size);
	size_t tmp;
	tmp = new_size > size ? size : new_size;
	for (size_t i = 0; i < tmp; i++)
		new_obj.data[i] = this->data[i];
	swap(new_obj);
};

size_t int_array :: ret_size()
{
	return (this->size);
};

int int_array :: ret_val(size_t i)
{
	return (this->data[i]);
};

int & int_array :: ret_link_to_val(size_t i)
{
	return (this->data[i]);
};
