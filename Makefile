# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 23:05:13 by aiblanco          #+#    #+#              #
#    Updated: 2023/09/30 23:05:21 by aiblanco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
library.h = push_swap.h
CFLAGS = -Wall -Wextra -Werror
CreateList_Functions = ./CreateList/main.o ./CreateList/format_list_1.o \
./CreateList/format_list_0.o ./CreateList/error.o \
./CreateList/frees.o ./CreateList/ft_atoi.o 
Movement_Commands_Functions = ./MovementCommands/sa.o ./MovementCommands/ss_sa.o \
./MovementCommands/sb.o ./MovementCommands/ss_sb.o ./MovementCommands/ss.o \
./MovementCommands/pa.o ./MovementCommands/pb.o ./MovementCommands/ra.o \
./MovementCommands/rr_ra.o ./MovementCommands/rb.o ./MovementCommands/rr_rb.o \
./MovementCommands/rr.o ./MovementCommands/rra.o ./MovementCommands/rrb.o \
./MovementCommands/rrr_rra.o ./MovementCommands/rrr_rrb.o \
./MovementCommands/rrr.o
Algorithm_Functions = ./Algorithm/algorithm.o ./Algorithm/nodecount.o \
./Algorithm/other_case.o ./Algorithm/recharge.o ./Algorithm/too_long_ft.o \
./Algorithm/few_arguments.o
Algorithm2_Functions = ./Algorithm_2/algorithm_2.o
b_functions = $(CreateList_Functions) $(Movement_Commands_Functions) \
	$(Algorithm_Functions) $(Algorithm2_Functions)

all: $(NAME)

$(NAME): $(library.h) $(b_functions)
	make -C ./libft
	gcc -g -o $(NAME) $(CFLAGS) $(b_functions) ./libft/libft.a

update: $(b_functions)
	make -C ./libft
	gcc -g -o $(NAME) $(CFLAGS) $(b_functions) ./libft/libft.a

$(@D)/%.o: $(@D)/%.c
	

clean:
	rm -f $(CreateList_Functions)
	rm -f $(Movement_Commands_Functions)
	rm -f $(Algorithm_Functions)
	rm -f $(Algorithm2_Functions)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
