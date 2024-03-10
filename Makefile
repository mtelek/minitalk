SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = ft_printf/libftprintf.a
NAME = $(SERVER) $(CLIENT)

all: $(NAME)

$(LIBFTPRINTF):
	make -s -C ft_printf

$(SERVER): server.c utils.c $(LIBFTPRINTF)
	$(CC) $(CFLAGS) server.c utils.c -Lft_printf -lftprintf -o $(SERVER)

$(CLIENT): client.c utils.c $(LIBFTPRINTF)
	$(CC) $(CFLAGS) client.c utils.c -Lft_printf -lftprintf -o $(CLIENT)

clean:
	make clean -s -C ft_printf
	rm -f $(SERVER) $(CLIENT) *.o

fclean: clean
	make fclean -s -C ft_printf

re: fclean all
