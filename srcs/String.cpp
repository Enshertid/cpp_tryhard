#include "string.hpp"

my_string :: my_string(size_t size, char c)
{
	size_t i;
	this->size = size;
	this->str = new char[size + 1];
	i = 0;
	while (i < size)
		this->str[i++] = c;
};

my_string :: my_string(const char *str)
{
		this->size = strlen(str);
		this->str = new char[this->size + 1];
		this->str = strcpy(this->str, str);
};

my_string :: my_string(my_string &orig)
{
	size_t		i;

	this->size = orig.size;
	this->str = new char[this->size + 1];
	this->str[this->size] = '\0';
	i = 0;
	while (i < this->size)
	{
		this->str[i] = orig.str[i];
		i++;
	}
};

my_string & my_string :: operator=(const my_string &orig)
{
	if (this != &orig)
	{
		delete [] str;
		size = orig.size;
		str = new char [size + 1];
		str[size] = '\0';
		for (size_t i = 0; i < size; i++)
			str[i] = orig.str[i];
	}
	return(*this);
};

my_string :: ~my_string()
{
	delete []this->str;
};

void my_string :: append(my_string &other)
{
	char	*new_str;
	char	*help;
	char	*tmp;

	if (!(*other.str))
		return ;
	this->size = other.size + this->size;
	new_str = new char[this->size + 1];
	help = this->str;
	tmp = new_str;
	while (*help)
		*tmp++ = *help++;
	help = other.str;
	while (*help)
		*tmp++ = *help++;
	*tmp = '\0';
	delete []this->str;
	this->str = new_str;
};

char * my_string :: ret_str(void)
{
	return (this->str);
};

size_t my_string :: ret_size(void)
{
	return (this->size);
};
