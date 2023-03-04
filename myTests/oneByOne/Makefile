# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 13:22:35 by nadesjar          #+#    #+#              #
#    Updated: 2023/03/03 19:15:02 by dracken24        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_OBJS 			= ./objs/
P_SRCS			= ./srcs/

INCLUDE_PATH	= ../includes/

FILES			= $(P_SRCS)pair.cpp $(P_SRCS)is_integral.cpp \
				$(P_SRCS)mainOne.cpp \

OBJS			= $(patsubst $(P_SRCS)%.cpp, $(P_OBJS)%.o, $(FILES))

CC				= c++

CFLAGS			= -Wall -Werror -Wextra

NAME			= oneByOne

# ------------------------------- Compilation -------------------------------- #

all: signat msg_in $(NAME) msg_out

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

# --------------------------- Recompilation Headers --------------------------- #

$(P_OBJS)pair.o: $(P_SRCS)pair.cpp $(INCLUDE_PATH)container.hpp
	@mkdir -p $(P_OBJS)
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$C■"

$(P_OBJS)is_integral.o: $(P_SRCS)is_integral.cpp $(INCLUDE_PATH)container.hpp
	@mkdir -p $(P_OBJS)
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$C■"

$(P_OBJS)mainOne.o: $(P_SRCS)mainOne.cpp $(INCLUDE_PATH)container.hpp
	@mkdir -p $(P_OBJS)
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$C■"

# --------------------------------- Messages --------------------------------- #

msg_in:
	@echo $L"COMPILATION DE Container EN COURS..."$W

msg_out:
	@echo $L"\nContainer READY !!!\n"$W

signat:
	@echo "$G\n\|/~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~\|/"
	@echo " |             ---------------------------------------------             |"
	@echo " |             *--* $LPROJET:  Container    PAR: NADESJAR$G *--*             |"
	@echo " |             ---------------------------------------------             |"
	@echo "/|\~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~/|\ \n$W"
	
# ---------------------------------- Colors ---------------------------------- #

L	= $(shell tput -Txterm setaf 5)
R	= $(shell tput -Txterm setaf 1)
G	= $(shell tput -Txterm setaf 2)
C	= $(shell tput -Txterm setaf 6)
W	= $(shell tput -Txterm setaf 7)

# ---------------------------------- Clean ----------------------------------- #

clean:	
	@rm -fr $(P_OBJS)

fclean: clean
	@echo $G"                                    BYE BYE !!!"$W
	@rm -f $(NAME)

re: fclean all


.PHONY: all msg_in msg_out clean fclean re signat
