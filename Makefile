# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 15:11:32 by xuwang            #+#    #+#              #
#    Updated: 2021/09/09 19:36:52 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC 	= gcc

CFLAGS 	= -Wall -Wextra -Werror

IFLAGS = -I. -I./libft

LFLAGS = -L./libft -lft



SRCS_P	:= 	srcs/push_swap/num_to_stack.c \
			srcs/push_swap/ft_p.c \
			srcs/push_swap/ft_r.c \
			srcs/push_swap/ft_rr.c \
			srcs/push_swap/ft_s.c \
			srcs/push_swap/num_less_five.c \
			srcs/push_swap/num_more.c \
			srcs/push_swap/push_swap.c \
			srcs/push_swap/utils.c \
			srcs/push_swap/for_quit.c

SRCS_C	:= 	srcs/push_swap/num_to_stack.c \
			srcs/push_swap/ft_p.c \
			srcs/push_swap/ft_r.c \
			srcs/push_swap/ft_rr.c \
			srcs/push_swap/ft_s.c \
			srcs/push_swap/num_less_five.c \
			srcs/push_swap/num_more.c \
			srcs/push_swap/utils.c \
			srcs/push_swap/for_quit.c \
			srcs/checker/ft_checker.c \
			srcs/checker/checker.c
			

OBJS_P := $(SRCS_P:%.c=%.o)
OBJS_C := $(SRCS_C:%.c=%.o)

$(NAME): $(OBJS_P) $(OBJS_C)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS_P) $(LFLAGS) $(IFLAGS) -o $(NAME)


$(CHECKER): $(OBJS_P) 
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS_C) $(LFLAGS) $(IFLAGS) -o $(CHECKER)

all: $(NAME) $(CHECKER) 

bonus: $(CHECKER)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJS_C)
	rm -rf $(OBJS_P)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re
