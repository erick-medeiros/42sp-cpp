NAME = megaphone

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
FORMAT = which clang-format >/dev/null 2>&1 && clang-format -i

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all
VALGRIND += --trace-children=yes --track-fds=yes --track-origins=yes

all: $(NAME)

%.o: %.cpp
	@$(FORMAT) $< || true
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

leaks:
	$(VALGRIND) ./$(NAME)

install:
	clang-format bear

bear:
	bear -- make re

.PHONY: all clean fclean re leaks install bear