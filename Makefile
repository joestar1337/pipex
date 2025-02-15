NAME = pipex

CC = cc

RM = rm -rf

#dCFLAGS = -Wall -Wextra -Werror 

LIBFT = libft/libft.a

SRC = src/pipex.c src/utils.c libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ${LIBFT} -o $(NAME)

%.o : %.c src/pipex.h
	make all -C libft/
	$(CC) $(CFLAGS) -c $< -o $@

fclean :
	make fclean -C libft/
	$(RM) $(NAME)
	$(RM) $(OBJ)
	
clean : 
	make clean -C libft/
	$(RM) $(OBJ)

re : fclean all
.PHONY : clean fclean 