FILES = fractol_utils.c fractol_utils2.c main.c manage_colors.c mandelbrot.c julia.c palettes.c parsing.c zoom_and_arrows.c

OBJS = ${FILES:.c=.o}

NAME = libfractol.a

FLAGS = -Wall -Wextra -Werror

%.o:	%.c
	gcc -c ${FLAGS} -o $@ $<

all:	${NAME}

${NAME}:${OBJS}
	ar rc ${NAME} ${OBJS}
	gcc ${FLAGS} -o fractol ${OBJS} -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}
	rm -f fractol

re:	fclean all

.PHONY:	all clean fclean re
