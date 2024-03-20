SRC = main.c color.c fractals.c init.c keys.c render.c

NAME = fractol

CFLAGS = -Werror -Wall -Wextra

INCLUDE = fractal.h ./mlx/

CC =	gcc

RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g

OBJS = ${SRC:.c=.o}

%.o:%.c ${INCLUDE} Makefile
	${CC} ${CFLAGS} -c $< -o $@

all: mlx ${NAME} Makefile

mlx:
	$(MAKE) -C ./mlx/

${NAME}: $(OBJS) ./mlx/libmlx.a $(INCLUDE)
	$(CC) $(CFLAGS) -o ${NAME} ${OBJS} -L./mlx -llx

clean:
		${RM} ${OBJS}
		$(MAKE) -C ./mlx clean
	
fclean:	clean
		${RM} ${NAME}
		${MAKE} -C ./mlx fclean

re:	fclean all

.PHONY: all clean fclean re mlx
