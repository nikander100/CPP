NAME = phonebook
SRCS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(addprefix obj/,$(SRCS:.cpp=.o))
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
INC_DIR = .
INC = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INC) $(OBJS) -o $(NAME)

obj/%.o: %.cpp
	mkdir -p obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re