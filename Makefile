# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 18:25:37 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 19:37:15 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libasm.a
NAME_BONUS= libasm_bonus.a
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

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

bonus: $(OBJS) ft_atoi_base.o
		ar rc $(NAME_BONUS) $(OBJS) ft_atoi_base.o

clean:
		$(RM) $(OBJS) ft_atoi_base.o

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
