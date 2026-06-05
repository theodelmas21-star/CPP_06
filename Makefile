NAME = convert
CXX = c++
MY_SOURCES = srcs/main.cpp	 \
			 srcs/ScalarConverter.cpp

			 

MY_OBJECTS = $(MY_SOURCES:.cpp=.o) 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(MY_OBJECTS)
	$(CXX) $(CXXFLAGS) $(MY_OBJECTS) -o $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re