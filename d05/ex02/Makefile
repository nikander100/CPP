NAME = runme
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(addprefix obj/,$(SRCS:.cpp=.o))
CC = clang++
FLAGS = -Wall -Werror -Wextra
INC_DIR = .
INC = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INC) $(OBJS) -o $(NAME)

obj/%.o: %.cpp $(INCLUDE)
	mkdir -p obj
	$(CC) -I. -c $(FLAGS) $(INC) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re