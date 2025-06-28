# Compiler
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Source and object files
SRCS := megaphone.cpp
OBJS := $(SRCS:.cpp=.o)

# Executable name
NAME := megaphone

# Default target
all: $(NAME)

# Link the final executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and binary
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Convenience
.PHONY: all clean fclean re
