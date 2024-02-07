NAME := runme
SRCS := AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \
		main.cpp
INC_DIR := .
OBJ_DIR := obj
OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
CXX := clang++
CXXFLAGS := -Wall -Werror -Wextra
CPPFLAGS := -I $(INC_DIR)

DIR_DUP = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	$(DIR_DUP)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re