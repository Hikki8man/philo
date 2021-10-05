NAME =	philo

CC =	gcc

CFLAGS =	-pthread -Wall -Werror -Wextra

SRCS =	main.c \
		ft_action.c \
		ft_parsing.c \
		ft_philo_lst.c \
		ft_routine.c \
		ft_status.c \
		ft_threads.c \
		ft_utils.c

SRC =	$(addprefix srcs/, $(SRCS))

OBJS =	$(SRC:.c=.o)

all :	$(NAME)

%.o :	%.c include/philo.h
		$(CC) $(CFLAGS) -c $< -o $@ -I include/

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re :	fclean $(NAME)

.PHONY :	re clean fclean .c.o