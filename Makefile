# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ji-kim <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 17:24:50 by ji-kim            #+#    #+#              #
#    Updated: 2021/07/05 17:25:30 by ji-kim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= minishell

CC 				= gcc
CFLAGS	 		= -Wall -Wextra #-Werror

LIBFT 			= libft.a
INCLUDE 		= includes/
SRCS_DIR 		= ./srcs/

RL				= -lreadline
RL_DIR			= /Users/$(USER)/.brew/opt/readline/
RL_LIB			= -L $(RL_DIR)lib
RL_INC			= -I $(RL_DIR)include

SRCS 			= $(addprefix $(SRCS_DIR),\
				  builtin.c\
				  builtin_util.c\
				  env.c\
				  eof_handler.c\
				  exec.c\
				  init0.c init1.c\
				  list.c\
				  logo.c\
				  loop.c\
				  minishell.c\
				  parse0.c parse1.c\
				  pipe.c\
				  redirection0.c redirection1.c\
				  sig_handler.c\
				  utils0.c utils1.c\
				  )
OBJS 			= $(SRCS:.c=.o)
DEPS 			= $(SRCS:.c=.d)

#mine
RL_M1	= -L/usr/local/opt/readline/lib
RL_M2 = -I//usr/local/opt/readline/include

all : $(NAME)
$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L. -lft $(RL) $(RL_LIB) -lncurses

mine : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L. -lft $(RL) $(RL_M1) -lncurses

$(LIBFT) :
	@make all -C ./libft
	@cp ./libft/libft.h $(INCLUDE)
	@cp ./libft/libft.a ./

clean :
	@make clean -C ./libft
	@rm -f $(OBJS) $(DEPS)

fclean : clean
	@rm -f $(LIBFT) ./libft/libft.a
	@rm -f $(NAME)

re : fclean all

.c.o :
	@$(CC) $(CFLAGS) -MD -c -o $@ $< -I$(INCLUDE) $(RL_INC) $(RL_M2)

-include $(DEPS)

.PHONY: all clean fclean re
