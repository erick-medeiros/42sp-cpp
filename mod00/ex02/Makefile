NAME = tests.out

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
FORMAT = which clang-format >/dev/null 2>&1 && clang-format -i

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
--trace-children=yes --track-fds=yes --track-origins=yes

all: $(NAME)

%.o: %.cpp
	@$(FORMAT) $< || true
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_TEST)

fclean: clean
	$(RM) $(NAME) $(TESTER)

re: fclean all

leaks:
	$(VALGRIND) ./$(NAME)

tests: $(NAME)
	@./$(NAME) > output.log
	@cut -d ' ' -f 2 19920104_091532.log > out1
	@cut -d ' ' -f 2 output.log > out2
	diff out1 out2
	@rm out1 out2

install:
	sudo apt install clang-format bear

bear:
	bear -- make re

.PHONY: all clean fclean re leaks tests install bear tests