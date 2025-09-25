NAME = account

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

HDRS = Account.hpp
SRC  = Account.cpp tests.cpp
OBJ  = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
