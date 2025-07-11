# Compiler
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Iincludes

# Source and object files
SRC_DIR := src
OBJ_DIR := build

SRCS := $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/AMateria.cpp \
	$(SRC_DIR)/Character.cpp \
	$(SRC_DIR)/ICharacter.cpp \
	$(SRC_DIR)/Cure.cpp \
	$(SRC_DIR)/Ice.cpp \

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Executable name
NAME := Materia

# Default target
all: $(NAME)

# Link the final executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and binary
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)


re: fclean all

# Convenience
.PHONY: all clean fclean re