SUBDIR	= srcs

OBJDIR	= objs

SRCS	=	${SUBDIR}/push_swap.c\
			${SUBDIR}/p_s_sort.c\
			${SUBDIR}/p_s_utils.c\
			${SUBDIR}/p_s_checks.c\
			${SUBDIR}/p_s_instruct1.c\
			${SUBDIR}/p_s_instruct2.c\

OBJ		= $(patsubst ${SUBDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})

NAME	= push_swap

CFLAGS	= -Wall -Werror -Wextra -O2

CC = gcc

${NAME}:	${OBJ}
			make -C libft all
			${CC} ${OBJ} -o ${NAME} -Llibft -lft

${OBJDIR}/%.o:	${SUBDIR}/%.c | ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
		mkdir -p $@

all:	${NAME}

debug:
		make -C libft all
		${CC} -D DEBUG=1 ${SRCS} ${SUBDIR}/p_s_debug.c -o ${NAME} -Llibft -lft -fsanitize=address

clean:
		rm -rf ${OBJDIR}
		make -C libft clean

fclean:	clean
		rm -f ${NAME}
		rm -f libft/libft.a

re:		fclean all

.PHONY: all fclean clean re