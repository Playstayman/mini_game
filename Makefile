NAME = wiff_adv

SRC = main.c \
	place_floor.c \
	set_wiff.c \
	input.c \
	utils.c \
	utils2.c \
	input2.c \
	moves.c \
	animate_stuff.c \
	lib/get_next_line.c \
	lib/get_next_line_utils.c \
	lib1/ft_bzero.c \
	lib1/ft_calloc.c \
	lib1/ft_isdigit.c\
	lib1/ft_itoa.c \
	lib1/ft_printf.c \
	lib1/ft_putchar_fd.c\
	lib1/ft_putstr_fd.c \
	lib1/ft_split.c \
	lib1/ft_strchr.c \
	lib1/ft_strjoin.c \
	lib1/ft_strlcpy.c \
	lib1/ft_strlen.c \
	lib1/ft_strncmp.c \
	lib1/ft_strtrim.c \
	lib1/ft_substr.c \
	lib1/search.c \
	lib1/hex.c \
	lib1/uitoa.c 
CC = cc
CFLAGS = -g 

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(CC) $(CFLAGS) -o $(NAME) $^ MLX42/build/libmlx42.a -lglfw

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm -f lib/*.o
	rm -f lib1/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean re fclean

