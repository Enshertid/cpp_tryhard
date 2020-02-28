NAME = first

SRCS_DIR = srcs/

OBJ_DIR = obj/

CC = g++

FLAGS = -g -Wall -Wextra -Werror -I$(HEADER_DIR)

HEADER_DIR = includes/

SRCS_CPP = main.cpp String.cpp int_array_constructors.cpp int_array_methods.cpp

SRCS_O = $(addprefix $(OBJ_DIR),$(SRCS_CPP:.cpp=.o))

all : $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(SRCS_O)
	@$(CC) $(FLAGS) $(SRCS_O) -o $(NAME)

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -Rf $(NAME)
