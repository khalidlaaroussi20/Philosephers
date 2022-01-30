CC = gcc
#FLAGS = -Wall -Wextra -Werror
SRC = philo.c \
	includes/libft/libft.a 
NAME = philo
RM = rm -f

ALL:${NAME}

${NAME}:
	cd includes/libft/ && make && cd ../..
	${CC} ${CFLAGS} ${SRC} -pthread -o ${NAME}
clean:
	${RM} /includes/libft/*.o
fclean:clean
	${RM} ${NAME} includes/libft/libft.a
re: fclean ALL