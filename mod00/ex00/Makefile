NAME = megaphone

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
FORMAT = clang-format -i

all: $(NAME)

%.o: %.cpp
	@$(FORMAT) $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leaks:
	valgrind -q --leak-check=full --show-leak-kinds=all --trace-children=yes \
	 --track-fds=yes --track-origins=yes \
	./$(NAME)

install:
	clang-format

.PHONY: all clean fclean re leaks install