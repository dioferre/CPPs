# Compiler
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Iincludes

# Source and object files
SRC_DIR := src
OBJ_DIR := build

SRCS := $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/AForm.cpp \
	$(SRC_DIR)/Bureaucrat.cpp \
	$(SRC_DIR)/ShrubberyCreationForm.cpp \
	$(SRC_DIR)/RobotomyRequestForm.cpp \
	$(SRC_DIR)/PresidentialPardonForm.cpp \
	$(SRC_DIR)/Intern.cpp

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Executable name
NAME := ex03

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