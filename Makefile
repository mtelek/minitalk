SERVER = server
CLIENT = client
CC = cc
ifneq ($(CI),)
    CFLAGS = -Wall -Wextra -Werror -g
else
    CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
endif
LIBFTPRINTF = ft_printf/libftprintf.a
NAME = $(SERVER) $(CLIENT)
OBJS_DIR = .objs

# Source files (all in srcs directory)
SERVER_SRCS = server.c utils.c utils2.c
CLIENT_SRCS = client.c utils.c utils2.c

# Object files will be in .objs/srcs/
SERVER_OBJS = $(addprefix $(OBJS_DIR)/srcs/, $(SERVER_SRCS:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJS_DIR)/srcs/, $(CLIENT_SRCS:.c=.o))

# ANSI color codes
GREEN = \033[0;32m
NC = \033[0m

all: $(NAME)
	@echo "$(GREEN)All targets built successfully$(NC)"

$(OBJS_DIR)/srcs:
	@mkdir -p $(OBJS_DIR)/srcs

# Pattern rule for object files
$(OBJS_DIR)/srcs/%.o: srcs/%.c | $(OBJS_DIR)/srcs
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $<$(NC)"

$(LIBFTPRINTF):
	@make -s -C ft_printf
	@echo "$(GREEN)libftprintf built successfully$(NC)"

$(SERVER): $(SERVER_OBJS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -Lft_printf -lftprintf -o $(SERVER)
	@echo "$(GREEN)Server built successfully$(NC)"

$(CLIENT): $(CLIENT_OBJS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -Lft_printf -lftprintf -o $(CLIENT)
	@echo "$(GREEN)Client built successfully$(NC)"

clean:
	@make clean -s -C ft_printf
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Clean completed successfully$(NC)"

fclean: clean
	@make fclean -s -C ft_printf
	@rm -f $(SERVER) $(CLIENT)
	@echo "$(GREEN)Full clean completed successfully$(NC)"

re: fclean all
	@echo "$(GREEN)Rebuild completed successfully$(NC)"
