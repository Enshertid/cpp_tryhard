#ifndef STRING_HPP
# define STRING_HPP

#include <cstddef> // size_t
#include <cstring> //strlen
#include <iostream> // stdcout stdcin

using std::cout;
using std::cin;
using std::endl;

class my_string
{
	public:
		my_string(const char *str = "");
		my_string(size_t size, char c);
		my_string(my_string &orig);
		my_string & operator=(const my_string &orig);
		~my_string();
		void	append(my_string &other);
		char	*ret_str(void);
		size_t	ret_size(void);
		char & at(size_t idx)       { cout << "!Const\n"; return str[idx]; }
    	char   at(size_t idx) const { cout << "! non const\n";return str[idx]; }
	private:
		char *str;
		size_t size;
};

#endif
