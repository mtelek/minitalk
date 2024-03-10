NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printchar.c ft_puthexlow.c ft_puthexupp.c ft_printint.c ft_putptr.c ft_putstr.c ft_putuint.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
	
re: fclean all