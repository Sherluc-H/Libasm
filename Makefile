# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 18:25:37 by lhuang            #+#    #+#              #
#    Updated: 2020/02/05 14:37:18 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libasm.a
FLAGS= -f macho64
SRCS= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS= ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o
RM= rm -f

all: $(NAME)

ft_strlen.o: ft_strlen.s
		nasm -f macho64 ft_strlen.s
		
ft_strcpy.o: ft_strcpy.s
		nasm -f macho64 ft_strcpy.s

ft_strcmp.o: ft_strcmp.s
		nasm -f macho64 ft_strcmp.s
 
ft_write.o: ft_write.s
		nasm -f macho64 ft_write.s

ft_read.o: ft_read.s
		nasm -f macho64 ft_read.s

ft_strdup.o: ft_strdup.s
		nasm -f macho64 ft_strdup.s

ft_atoi_base.o: ft_atoi_base.s
		nasm -f macho64 ft_atoi_base.s

ft_list_push_front.o: ft_list_push_front.s
		nasm -f macho64 ft_list_push_front.s

$(NAME): $(OBJS)
		gcc main.c $(OBJS)

bonus: $(OBJS) ft_atoi_base.o ft_list_push_front.o
		gcc main.c $(OBJS) ft_atoi_base.o ft_list_push_front.o

clean:
		$(RM) $(OBJS) ft_atoi_base.o ft_list_push_front.o

fclean: clean
		$(RM) $(NAME)

re:

.PHONY: all bonus fclean clean re
