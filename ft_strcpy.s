# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 15:16:46 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 18:08:53 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global		_ft_strcpy
			section		.text
_ft_strcpy:
			mov			rbx, rdi	; rbx stores the dest ptr first addr
			mov			rcx, rsi	; rcx contains the src ptr
loop:
			mov			al, [rcx]	; store the char of src in al
			mov			[rdi], al	; put the char of src in dest
			inc			rdi			; go to next char of dest
			inc			rcx			; go to next char of src
			cmp			al, 0		; check if \0
			jne			loop		; if not jump up
			mov			rax, rbx	; return the first addr of dest
			ret
