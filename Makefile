SRCS =	str_uti.c		\
		ft_printf.c		\
		printf_uti.c	\
		ft_split.c 		\
		pipe_uti_01.c	\
		pipex.c

OBJS	= ${SRCS:.c=.o}

NAME	= pipex
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all