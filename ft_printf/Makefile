NAME = libftprintf.a
CC = cc
ifneq ($(CI),)
    CFLAGS = -Wall -Wextra -Werror -g
else
    CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
endif
SRCDIR = .
OBJDIR = .objs
SRCS = ft_printf.c ft_printchar.c ft_puthexlow.c ft_puthexupp.c ft_printint.c ft_putptr.c ft_putstr.c ft_putuint.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
