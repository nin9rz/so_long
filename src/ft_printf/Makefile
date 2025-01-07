NAME = libftprintf.a

CFLAGS = -Werror -Wall -Wextra -g

CSRC = ft_printf_utils.c\
		ft_printf.c

COBJ = $(CSRC:.c=.o)

%.o:%.c
	cc $(CFLAGS) $< -c -o $@

$(NAME): $(COBJ)
	ar rcs $(NAME) $(COBJ)

clean: 
	rm -f $(COBJ) 

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: re all fclean clean
