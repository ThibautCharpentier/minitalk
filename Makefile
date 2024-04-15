NAME = minitalk

CLIENT = client
SERVER = server

HDR = srcs/minitalk.h

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = ${addprefix srcs/,${SRCS_CLIENT:.c=.o}}
OBJS_SERVER = ${addprefix srcs/,${SRCS_SERVER:.c=.o}}

LIBFT_AR = ./libft/libft.a 

INCLUDE = -I libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${HDR} ${LIBFT_AR} Makefile
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE}

all: libft ${NAME}

${NAME}: ${CLIENT} ${SERVER}

${CLIENT}: ${OBJS_CLIENT}
	${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT} -Llibft -lft

${SERVER}: ${OBJS_SERVER}
	${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER} -Llibft -lft

libft:
	make -C libft

clean:
	rm -f ${OBJS_CLIENT} ${OBJS_SERVER}
	make clean -C libft

fclean: clean
	rm -f ${CLIENT} ${SERVER}
	make fclean -C libft

re: fclean all

bonus: libft ${NAME}

.PHONY: all libft clean fclean re bonus
