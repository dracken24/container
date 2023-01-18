# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 13:22:35 by nadesjar          #+#    #+#              #
#    Updated: 2023/01/17 22:53:21 by dracken24        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_OBJS 			= ./objs/
P_OBJSSTACK 	= ./objsStack/
P_SRCS			= ./srcs/
P_CLASS			= ./srcs/templates/
P_FT			= ./srcs/templates/functions/

FILES			= $(P_SRCS)main.cpp 
FILES_STACK		= $(P_SRCS)mainStack.cpp 

OBJS			= $(patsubst $(P_SRCS)%.cpp, $(P_OBJS)%.o, $(FILES))
OBJS_STACK		= $(patsubst $(P_SRCS)%.cpp, $(P_OBJSSTACK)%.o, $(FILES_STACK))

CC				= c++

CFLAGS			= -Wall -Werror -Wextra -std=c++98

NAME			= Container
NAME_STACK		= Stack

# ---------------------------------------------------------------------------- #

all: signat msg_in $(NAME) msg_out

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(P_OBJS)%.o:	$(P_SRCS)%.cpp
	@mkdir -p $(P_OBJS)
	@mkdir -p $(P_OBJS)class
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	@printf "$G■"

# ---------------------------------------------------------------------------- #

stack: msg_in_stack $(NAME_STACK) 

$(NAME_STACK): $(OBJS_STACK)
	@$(CC) $(OBJS_STACK) $(CFLAGS) -o $(NAME_STACK)
	@echo $L"\nStack READY !!!"$W
	@./$(NAME_STACK)
	@rm -fr $(NAME_STACK)

$(P_OBJSSTACK)%.o:	$(P_SRCS)%.cpp
	@mkdir -p $(P_OBJSSTACK)
	@mkdir -p $(P_OBJSSTACK)class
	@$(CC) $(CFLAGS) -I. -c $< -o $@
	@printf "$G■"

# ---------------------------------------------------------------------------- #

msg_in:
	@echo $L"COMPILATION DE Container EN COURS..."$W

msg_out:
	@echo $L"\nContainer READY !!!\n"$W

msg_in_stack:
	@echo $L"COMPILATION DE Stack EN COURS..."$W

msg_out_stack:
	@echo $L"\nStack READY !!!"$W

signat:
	@echo "$G\n\|/~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~\|/"
	@echo " |             ---------------------------------------------             |"
	@echo " |             *--* $LPROJET:  Container    PAR: NADESJAR$G *--*             |"
	@echo " |             ---------------------------------------------             |"
	@echo "/|\~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~---~/|\ \n$W"
	
# ---------------------------------------------------------------------------- #

clean:	
	@rm -fr $(P_OBJS)
	@rm -fr $(P_OBJSSTACK)

fclean: clean
	@echo $G"                                    BYE BYE !!!"$W
	@rm -f $(NAME)
	@rm -f $(NAME_STACK)

re: fclean all

L	= $(shell tput -Txterm setaf 5)
R	= $(shell tput -Txterm setaf 1)
G	= $(shell tput -Txterm setaf 2)
C	= $(shell tput -Txterm setaf 6)
W	= $(shell tput -Txterm setaf 7)

.PHONY: all msg_in msg_out clean fclean re signat
