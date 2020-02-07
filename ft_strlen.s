# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 18:33:20 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 18:07:01 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global		_ft_strlen
			section		.text
_ft_strlen:
			mov			rcx, rdi		; move the string first address in rcx
			mov			r8,	-1			; put -1 in r8
loop:
			inc			r8				; r8 = 0 when the loop starts
			mov 		al, [rcx]		; put the char of string in al
			inc			rcx				; go to next char
			cmp			al, 0			; check if \0
			jne			loop			; if not \0 jump up of loop
			mov			rax, r8			; put the lenght of r8 in rax
			ret							; return rax
