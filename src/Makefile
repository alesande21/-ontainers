PROJECT_NAME	=s21_containers
O_DIR 			= ./obj
LIB_INC_DIR		= ./Includes
LIB_O_DIR		= $(ODIR)/$(LIB_SRC_DIR)


TEST_SRC_DIR	= Tests
TEST_INC_DIR	= $(LIB_INC_DIR)
TEST_O_DIR		= $(O_DIR)/$(TEST_SRC_DIR)
BUILD_DIR		= ../src
UNAME_S 		:= $(shell uname -s)
TEST_SRC		= ${PROJECT_NAME}_test.cc
TEST_SOURCES	= $(shell find $(TEST_SRC_DIR) -name '*.cc')
Flags 			= -std=c++17 -lstdc++ -Werror -Wall -Wextra $(DEBUG)
gcc 			= gcc $(Flags)
TEST_OBJ 		= $(patsubst %.cc,$(O_DIR)/%.o, $(TEST_SOURCES))
OBJ					=$(TEST_OBJ)
DEBUG_SOURCE= $(TEST_SRC)
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

ifeq ($(UNAME_S),Linux)
	gcc += -D OS_LINUX
	TEST_CHECK_F= -lcheck
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread
endif

ifeq ($(UNAME_S),Darwin)
	gcc += -D OS_MAC
	TEST_CHECK_F = -lgtest -lgmock -pthread
	OPEN_CMD = open
	ADD_LIB =
endif

all: clear test

$(TEST_O_DIR)/%.o: $(TEST_SRC_DIR)/%.cc
	@$(gcc) -I${LIB_INC_DIR} -I${TEST_INC_DIR} $< -c -o $@

clear:
	clear

clean:
	@rm -rf $(BUILD_DIR)/$(PROJECT_NAME).a test *.out
	@rm -rf $(shell find ./$(ODIR) -name '*.o')
	@rm -rf $(shell find ./ -name '*.gc*')
	@rm -rf ./*.dSYM
	@rm -rf $(BUILD_DIR)/$(PROJECT_NAME)

obj: $(OBJ)

no_warns:
	$(eval gcc = gcc)

clang:
	clang-format --style=Google -n $(shell find . -name '*.cc') $(shell find . -name '*.h')

clang-replace:
	clang-format --style=Google -i $(shell find . -name '*.cc') $(shell find . -name '*.h')

$(BUILD_DIR)/$(PROJECT_NAME): test
$(PROJECT_NAME): $(BUILD_DIR)/$(PROJECT_NAME)
debug:
	$(eval DEBUG = -g)
	@echo $(PROJECT_NAME):Debug build

test: $(OBJ)
	$(gcc) -I${TEST_INC_DIR} $(DEBUG_SOURCE) $^ $(TEST_CHECK_F) -o $(PROJECT_NAME)
	./$(PROJECT_NAME)
leaks: test
	leaks -atExit -- ./$(PROJECT_NAME)

valgrind: clean test
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./$(PROJECT_NAME)
	$(OPEN_CMD) ./RESULT_VALGRIND.txt
.PHONY: clean obj clear $(PROJECT_NAME) test clang-replace all $(BUILD_DIR)/$(PROJECT_NAME).a set_debug_gcc set_report_gcc gcov_report