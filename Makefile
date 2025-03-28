CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long
MAKE = make --no-print-directory

OBJS = $(SRCS:.c=.o)

#-------------------------------------------------------COLORS--------------------------------------------------#

BLACK = "\e[30m"
RED = "\e[31m"
GREEN = "\e[32m"
YELLOW = "\e[33m"
BLUE = "\e[34m"
MAGENTA = "\e[35m"
CYAN = "\e[36m"
LIGHT_GRAY = "\e[37m"
DARK_GRAY = "\e[90m"
LIGHT_RED = "\e[91m"
LIGHT_GREEN = "\e[92m"
LIGHT_YELLOW = "\e[93m"
LIGHT_BLUE = "\e[94m"
LIGHT_MAGENTA = "\e[95m"
LIGHT_CYAN = "\e[96m"
WHITE = "\e[97m"
DEFAULT = "\e[39m"

#-------------------------------------------------------SRCS----------------------------------------------------#

PRINTF_PATH = src/ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a

LIBFT_PATH = src/libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)/libmlx_Linux.a

SRCS =	src/gnl/get_next_line.c\
		src/gnl/get_next_line_utils.c\
		main.c\
		utils.c\
		parsing.c\
		map_fill.c\
		flood_fill.c\
		image_treatment.c


#-----------------------------------------------------RULES-----------------------------------------------#

all: $(NAME)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH) -s -j

$(NAME): $(LIBFT) $(PRINTF) $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF) -Iminilibx-linux $(MLX) -lXext -lX11 -lm -lz
	@echo $(BLUE)
	@echo "███████  ██████          ███████ ██   ██  ██████  ██████  ████████ "
	@echo "██      ██    ██         ██      ██   ██ ██    ██ ██   ██    ██    "
	@echo "███████ ██    ██         ███████ ███████ ██    ██ ██████     ██    "
	@echo "     ██ ██    ██              ██ ██   ██ ██    ██ ██   ██    ██    "
	@echo "███████  ██████  ███████ ███████ ██   ██  ██████  ██   ██    ██    "
	
                                                                   
	@echo $(DEFAULT)

%.o: %.c
	@echo -n $(CYAN)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo -n $(DEFAULT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINTF_PATH) clean
	@rm -f $(OBJS)
	@echo $(YELLOW)
	@echo "███████  ██████          ███████ ██   ██  ██████  ██████  ████████                                                             ██ ███████"
	@echo "██      ██    ██         ██      ██   ██ ██    ██ ██   ██    ██        ██ ██"
	@echo "███████ ██    ██         ███████ ███████ ██    ██ ██████     ██        ██ ███████"
	@echo "     ██ ██    ██              ██ ██   ██ ██    ██ ██   ██    ██        ██      ██"
	@echo "███████  ██████  ███████ ███████ ██   ██  ██████  ██   ██    ██        ██ ███████"
	@echo ""
	@echo " ██████ ██      ███████  █████  ███    ██  ███████ ██████"
	@echo "██      ██      ██      ██   ██ ████   ██  ██      ██   ██"
	@echo "██      ██      █████   ███████ ██ ██  ██  █████   ██   ██"
	@echo "██      ██      ██      ██   ██ ██  ██ ██  ██      ██   ██"
	@echo " ██████ ███████ ███████ ██   ██ ██   ████  ███████ ██████"
	@echo $(DEFAULT)

fclean: clean
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re : fclean all