NAME = polymorphism

SRC = main.cpp Animal.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I../../lib/
CPPFLAGS = -MMD -MP
BUILD_DIR = build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
DEP = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.d))

TESTER = tests.out
SRC_TEST = $(wildcard $(SRC:.cpp=_test.cpp))
OBJ_TEST = $(addprefix $(BUILD_DIR)/, $(SRC_TEST:.cpp=.o))

FORMAT = which clang-format >/dev/null 2>&1 \
&& echo $^ | tr ' ' '\n' | grep -v 'doctest.h' | tr '\n' ' ' \
| xargs clang-format -i || true

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
--trace-children=yes --track-origins=yes --track-fds=yes

all: $(NAME)

$(BUILD_DIR)/%.o: %.cpp
	@$(FORMAT)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	$(RM) $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d

fclean: clean
	$(RM) *.out $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

leaks: $(NAME)
	$(VALGRIND) ./$(NAME)

$(TESTER): $(NAME) $(OBJ_TEST) | $(BUILD_DIR) #doctest.h
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_TEST) $(filter-out %main.o, $(OBJ))

tests: #$(TESTER)
#	@$(VALGRIND) ./$(TESTER)

retests: fclean tests

doctest.h:
	@curl https://raw.githubusercontent.com/erick-medeiros/42sp-cpp/main/lib/doctest.h > doctest.h

-include $(DEP)

.PHONY: all clean fclean re run leaks tests retests