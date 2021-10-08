NAME = philo_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pthread

SRCS =	main.c \
		ft_action.c \
		ft_forks.c \
		ft_parsing.c \
		ft_semaphores.c \
		ft_status.c \
		ft_thread.c \
		ft_utils.c \
		ft_itoa.c

SRC = $(addprefix srcs/, $(SRCS))

OBJS = $(SRC:.c=.o)

all :	$(NAME)

%.o :	%.c include/philo_bonus.h
		$(CC) $(CFLAGS) -c $< -o $@ -I include/

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re :	fclean $(NAME)

.PHONY :	re clean fclean .c.o