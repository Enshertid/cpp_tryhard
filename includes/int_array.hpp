#ifndef HEADER_HPP
# define HEADER_HPP

#include <cstddef> // size_t
#include <cstring> //strlen

class int_array
{
	public:
		explicit int_array(size_t size);
		int_array(int_array const &orig);
		int_array &operator=(int_array &orig);
		~int_array();
		void			swap(int_array &orig);
		size_t	ret_size();
		int		ret_val(size_t i);
		int				&ret_link_to_val(size_t i);
		void			resize_data(size_t new_size);
	private:
		int *data;
		size_t size;
};

#endif
