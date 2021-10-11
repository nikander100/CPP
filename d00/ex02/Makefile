NAME = runme
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

OBJS = Account tests
_OBJS = $(addsuffix .o, $(OBJS))

all:	$(NAME)

$(NAME): $(_OBJS)
	@$(CC) $(_OBJS) $(CFLAGS) -o $(NAME)

%.o: %.cpp
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@$(RM) *.o

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
