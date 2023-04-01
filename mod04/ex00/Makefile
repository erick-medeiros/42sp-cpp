NAME = polymorphism

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
CPPFLAGS = -MMD -MP

LIBS = -I../../lib/
CXXFLAGS += $(LIBS)
FORMAT = which clang-format >/dev/null 2>&1 && clang-format -i $< || true

TESTER = tests.out
OBJ_TEST = tests.o

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
--trace-children=yes --track-origins=yes --track-fds=yes

all: $(NAME)

%.o: %.cpp
	@$(FORMAT)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(DEP) $(OBJ_TEST)

fclean: clean
	$(RM) $(NAME) $(TESTER)

re: fclean all

run: $(NAME)
	./$(NAME)

leaks: $(NAME)
	$(VALGRIND) ./$(NAME)

tests: $(TESTER)
	$(VALGRIND) ./$(TESTER)

$(TESTER): $(NAME) $(OBJ_TEST) #doctest.h
	$(CXX) $(CXXFLAGS) -o $(TESTER) $(OBJ_TEST) $(filter-out main.o, $(OBJ))

doctest.h:
	@curl https://raw.githubusercontent.com/erick-medeiros/42sp-cpp/main/lib/doctest.h > doctest.h

-include $(DEP)

.PHONY: all clean fclean re run leaks tests