NAME = easyphone

SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
FORMAT = clang-format -i

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all
VALGRIND += --trace-children=yes --track-fds=yes --track-origins=yes

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
	$(VALGRIND) ./$(NAME)

tests.out: tests.cpp
	$(CXX) $(CXXFLAGS) tests.cpp -o tests.out -lcriterion

tests: tests.out
	./tests.out

install:
	sudo apt install clang-format bear libcriterion-dev

bear:
	bear -- make re

.PHONY: all clean fclean re leaks tests install bear