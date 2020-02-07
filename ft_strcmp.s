# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 16:17:36 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 19:19:54 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global	_ft_strcmp
			section	.text
_ft_strcmp:
			mov		al, 0
			mov		bl, 0
loop:
			mov		al, [rdi]			; store char from s1
			mov		bl, [rsi]			; store char from s2
			inc		rdi					; go next char s1
			inc		rsi					; go next char s2
			cmp		al, 0
			je		reach_end
			cmp		bl, 0
			je		reach_end
			cmp		al, bl				; 
			je		loop				; jump  up in loop if equal
			sub		al, bl				; put the sub bl - al in al
			movsx	rax, al				; convert byte to rax size
			ret							;
reach_end:
			cmp		al, bl
			je		same
			sub		al, bl				; put the sub bl - al in al
			movsx	rax, al				; convert byte to rax size
			ret							;
same:
			mov		rax, 0
			ret
