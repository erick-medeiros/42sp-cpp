NAME = convert

SRC = main.cpp ScalarConverter.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I../../lib/
CPPFLAGS = -MMD -MP
BUILD_DIR = build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
DEP = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.d))

FORMAT = which clang-format >/dev/null 2>&1 \
&& echo $^ | tr ' ' '\n' | grep -v 'doctest.h' | tr '\n' ' ' \
| xargs clang-format -i || true

VALGRIND = valgrind -q --leak-check=full --show-leak-kinds=all \
--trace-children=yes --track-origins=yes --track-fds=yes

all: $(NAME)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@$(FORMAT)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
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
	$(VALGRIND) ./$(NAME) 1

tests: $(NAME)
	@chmod +x tests.sh
	./tests.sh

retests: fclean tests

debug: CXXFLAGS += -DDEBUG=1
debug: all

redebug: fclean debug

doctest.h:
	@curl -s https://raw.githubusercontent.com/erick-medeiros/42sp-cpp/main/lib/doctest.h > doctest.h

-include $(DEP)

.PHONY: all clean fclean re run leaks tests retests debug redebug