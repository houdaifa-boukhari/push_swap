NAME = push_swap
HEADER = push_swap.h
SRC = big_sorting.c ft_split.c push_swap.c tools_list.c tools_string.c \
	operations.c sorting.c tools_list2.c  tools_string2.c
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@rm -f $(OBJS)
fclean : clean
	@rm -f $(NAME)
re : fclean all