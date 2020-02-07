# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_push_front.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 14:29:14 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 12:06:16 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global	_ft_list_push_front
			section	.text
_ft_list_push_front:
		;			push	rdi
		;			pop		rdi
		;			mov		rbx, [rdi + 8]
		
;					leaq	rdi, 0
		;			mov		rcx, 0
		;			lea		rcx, [rdi + 8]
		;			mov		rcx, 0
		;			mov		[rdi+16], byte 0
		;			pop		rax
		;			pop		rdi
		;			pop		rdx
					mov		rax, rdi
					ret
