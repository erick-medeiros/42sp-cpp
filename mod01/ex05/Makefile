NAME = harl.out

SRC = main.cpp Harl.cpp
INC = Harl.hpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 $(LIBS) -g
LIBS = -I../../lib/
FORMAT = which clang-format >/dev/null 2>&1 && clang-format -i

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
--trace-children=yes --track-fds=yes --track-origins=yes

all: $(NAME)

%.o: %.cpp $(INC)
	@$(FORMAT) $< || true
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(FORMAT) $(INC) || true
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_TEST)

fclean: clean
	$(RM) $(NAME) $(TESTER)

re: fclean all

leaks: ./$(NAME)
	$(VALGRIND) ./$(NAME)

tests: $(NAME)
	bash tests.sh

install:
	sudo apt install clang-format

.PHONY: all clean fclean re leaks tests install