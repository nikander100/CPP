NAME = runme
SRCS = AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \
		main.cpp
OBJS = $(addprefix obj/,$(SRCS:.cpp=.o))
CC = clang++
INC_DIR = .
INC = -I$(INC_DIR)
FLAGS = -Wall -Werror -Wextra $(INC)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

obj/%.o: %.cpp $(INCLUDE)
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re