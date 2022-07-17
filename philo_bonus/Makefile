# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 19:47:14 by orekabe           #+#    #+#              #
#    Updated: 2022/07/17 19:44:00 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus

HEADER = philo.h

SRC = create_philos.c ft_atoi.c ft_check_error.c ft_isdigit.c get_time.c init_data.c is_dead.c \
		is_eating.c is_sleeping.c is_thinking.c join_philos.c my_sleep.c philo_bonus.c routine.c taken_a_fork.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all