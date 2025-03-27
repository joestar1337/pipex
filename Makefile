NAME = pipex

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC = src/pipex.c src/utils.c libft/libft.a

HEADER = src/pipex.h

HEADER2 = libft/libft.h

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(HEADER2)
	$(CC) $(CFLAGS) $(OBJ) ${LIBFT} -o $(NAME)

%.o : %.c $(HEADER) $(HEADER2)
	make all -C libft/
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	make clean -C libft/
	$(RM) $(OBJ)

fclean :
	make fclean -C libft/
	$(RM) $(NAME)
	$(RM) $(OBJ)
	
re : fclean all

.PHONY : clean fclean 