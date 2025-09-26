NAME = phonebook

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

HDRS = Contact.hpp PhoneBook.hpp
SRC  = PhoneBook.cpp Contact.cpp Main.cpp
OBJ  = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CPP) $(CPP_FLAGS) -c $< -o $@


clean :
	rm -f $(OBJ)

flcean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
