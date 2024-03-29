# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 19:47:14 by orekabe           #+#    #+#              #
#    Updated: 2022/12/26 19:25:43 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus

HEADER = -I./include

SRCD = ./src

OBJD = ./objs

SRC = $(SRCD)/create_philos.c $(SRCD)/ft_atoi.c $(SRCD)/ft_check_error.c $(SRCD)/ft_isdigit.c $(SRCD)/get_time.c $(SRCD)/init_data.c $(SRCD)/is_dead.c \
		$(SRCD)/is_eating.c $(SRCD)/is_sleeping.c i$(SRCD)/is_thinking.c $(SRCD)/join_philos.c $(SRCD)/my_sleep.c $(SRCD)/philo_bonus.c $(SRCD)/routine.c $(SRCD)/taken_a_fork.c

OBJ = $(addprefix $(OBJD)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	@printf "                                               \r"
	@echo "██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗"
	@echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝"
	@echo "██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗"
	@echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║"
	@echo "██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝"
	@echo "                   			BY: MTRX"
	@$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(OBJD)
	@printf "                                               \r"
	@printf "Compiling $<\r"
	@$(CC) -c $(CFLAGS) $(HEADER) $< -o $@

clean:
	rm -rf $(OBJD)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all
