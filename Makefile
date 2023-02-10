# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 13:22:35 by nadesjar          #+#    #+#              #
#    Updated: 2023/02/10 15:40:04 by dracken24        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_OBJS 			= ./objs/srcs/
P_SRCS			= ./myTests/srcs/

INCLUDE_PATH	= ./myTests/includes/

FILES			= $(P_SRCS)main.cpp \
				$(P_SRCS)vectorTest.cpp \
				$(P_SRCS)stackTest.cpp \
				$(P_SRCS)mapTest.cpp \
				$(P_SRCS)timeOut.cpp \

OBJS			= $(patsubst $(P_SRCS)%.cpp, $(P_OBJS)%.o, $(FILES))

CC				= c++

CFLAGS			= -Wall -Werror -Wextra -std=c++98

NAME			= TestContainer

# ------------------------------- Compilation -------------------------------- #

all: signat msg_in $(NAME) msg_out

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

# --------------------------- Recompilation Headers --------------------------- #

$(P_OBJS)main.o: $(P_SRCS)main.cpp $(INCLUDE_PATH)container.hpp
	@mkdir -p $(P_OBJS)
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$C■"

$(P_OBJS)mapTest.o: $(P_SRCS)mapTest.cpp $(INCLUDE_PATH)container.hpp
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$G■"

$(P_OBJS)stackTest.o: $(P_SRCS)stackTest.cpp $(INCLUDE_PATH)container.hpp
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$C■"

$(P_OBJS)vectorTest.o: $(P_SRCS)vectorTest.cpp $(INCLUDE_PATH)container.hpp
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$G■"

$(P_OBJS)timeOut.o: $(P_SRCS)timeOut.cpp $(INCLUDE_PATH)container.hpp
	@$(CC) -I $(CFLAGS) -c $< -o $@
	@printf "$G■"

# ----------------------------------- Git ------------------------------------ #

COMMIT = $(shell date "+%d %B %T")
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push

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
