# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:04:57 by kangkim           #+#    #+#              #
#    Updated: 2022/01/10 17:42:14 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes
MLX_DIR = $(SRCS_DIR)/minilibx

SRCS = main.c utils.c
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
MLX = $(MLX_DIR)/libmlx.a
LINK_MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

vpath $.c $(SRCS_DIR)
vpath $.h $(INCLUDES_DIR)

all : $(NAME)

$(NAME) : $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(LINK_MLX) -o $@ $^

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c -o $@ $<

$(MLX) :
	$(MAKE) -C $(MLX_DIR) all

bonus : all

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re