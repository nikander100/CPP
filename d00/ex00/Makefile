NAME = megaphone

CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all: $(NAME)

$(NAME):
	@$(CC) megaphone.cpp -o $(NAME)

# vvv ¯\_(ツ)_/¯ not needed fucntion whut? ¯\_(ツ)_/¯ vvv
clean:
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯ This function does normally delete output files but there are none (just ignore it) ¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"
	@echo "¯\_(ツ)_/¯"

fclean:
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
