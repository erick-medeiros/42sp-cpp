NAME = string.out

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 $(LIBS) -g
LIBS = -I../../lib/
FORMAT = clang-format -i

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
--trace-children=yes --track-fds=yes --track-origins=yes

all: $(NAME)

%.o: %.cpp
	@$(FORMAT) $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_TEST)

fclean: clean
	$(RM) $(NAME) $(TESTER)

re: fclean all

leaks: $(NAME)
	$(VALGRIND) ./$(NAME)

install:
	sudo apt install clang-format bear

bear:
	bear -- make re

.PHONY: all clean fclean re leaks tests install bear tests