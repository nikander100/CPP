NAME = tests
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
OBJSDIR = objs
INCLUDES = Account.hpp 

OBJS = Account tests
_OBJS = $(addsuffix .o, $(addprefix $(OBJSDIR)/, $(OBJS)))

all:	$(NAME)

$(NAME): $(_OBJS)
	@$(CC) $(CFLAGS) -o $(_OBJS) -I./$(INCLUDES) -v

$(OBJSDIR)/%.o: %.cpp ./$(INCLUDES)
	@mkdir -p $(OBJSDIR)/$(dir $*)
	@$(CC) -c $(CFLAGS) -I./$(INCLUDES) -o $@ $< -v

clean:
	@$(RM) -r $(OBJSDIR)

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
