# Compiler and Flags
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 # Common for these types of exercises
NAME     := PmergeMe

# Source files and Objects
SRCS     := main.cpp PmergeMe.cpp
OBJS     := $(SRCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# This ensures that if you change PmergeMe.hpp, the .o files rebuild
%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re