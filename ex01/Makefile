NAME = convert
SRC = $(wildcard *.cpp)

OBJS	= ${SRC:.cpp=.o}

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

OBJ = $(SRC:.cpp=.o)

all:	${NAME}

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) ${OBJ} -o ${NAME}

exe:
	./$(NAME)

clean:
		@${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: clean exe fclean re all