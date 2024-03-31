NAME = ../checker
HEADER = checker.h
SRC = aplly_operations.c ft_split.c checker.c tools_list.c tools_string.c tools_string2.c \
	operations.c  tools_list2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
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