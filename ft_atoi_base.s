# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_atoi_base.s                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 14:25:44 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 18:25:50 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

				global	_ft_atoi_base
				section	.text
_ft_atoi_base:
				push	rdi					; param 1
				push	rsi					; param 2
				mov		r13, 1
				mov		rcx, rsi
				mov		r8, -1
loop:										; get the length of param 2
				inc		r8
				mov		al, [rcx]
				inc		rcx
				cmp		al, 0
				jne		loop				; r8 = length param 1, r9 = count same char found
				cmp		r8, 1				; check length of param 2
				jle		error2
				mov		r9, 0
				pop		rsi
				mov		rdx, rsi			; rdx store param 2
				push	rsi
check:										; check if param 2 contains the same char multiple time
				pop		rsi					; get the 2nd param back
				mov		rcx, rsi			; rcx start from beginning of param 2
				push	rsi
				mov		al,	[rdx]			; al store char of param 2
				cmp		al, 0				; check if last char of param 2 reached
				je		end2				; if reached go end 2
				cmp		al, 43				; check if base ok
				je		error
				cmp		al, 45
				je		error
				cmp		al, 32
				jle		error
				cmp		al, 127
				jge		error
				inc		rdx					; prepare to use next char
loop2:
				cmp		[rcx], al			; if the char is found, increase r9
				je		add
				cmp		r9, 1				; if r9 greater than 1 so error, end the loop
				jg		error2				; more than one same char
				cmp		[rcx], byte 0		; if checking a char reach \0 check next char
				je		check_next
				inc		rcx					; if not found and not == \0, go next char
				jmp		loop2
error:										; if same char are found in param 2
				pop		rsi
				pop		rdi
				mov		rax, 1
				ret
error2:										; if same char are found in param 2
				pop		rsi
				pop		rdi
				mov		rax, 2
				ret
end2:										; param 2 ok
				pop 	rsi
				pop		rdi
				push	rsi					; put the param 2 in stack
				mov		r11, 0				; return value
				jmp		start_calculate
add:
				inc		r9					; al char was found
				inc		rcx					; prepare next char to compare with
				jmp		loop2
check_next:
				mov		r9, 0				; initialise r9 same char counter
				jmp		check
start_calculate:
				mov		al, [rdi]			; get the char in param 1
				inc		rdi					; prepare next char in param
skip_whitespace:							; 32 == ' ' | 9 == '\t' | 10 == '\n' | 11 == '\v' | 12 == '\f' | 13 == '\r'
				cmp		al, 32
				je		move_next
				cmp		al, 9
				je		move_next
				cmp		al, 11
				je		move_next
				cmp		al, 10
				je		move_next
				cmp		al, 13
				je		move_next
				cmp		al, 12
				je		move_next
				cmp		al, 45				; 45 == -
				je		found_sign
				cmp		al, 43				; 43 == +
				je		found_sign
				dec		rdi
				jmp		start_search
move_next:
				mov		al, [rdi]
				inc		rdi
				jmp		skip_whitespace
found_sign:
				cmp		al, 45
				je		change_sign
				cmp		al, 43
				je		next_sign
				dec		rdi					; no more sign 
				jmp		start_search
change_sign:
				imul	r13, -1				; change the sign if '-'
				mov		al, [rdi]
				inc		rdi
				jmp		found_sign
next_sign:
				mov		al, [rdi]
				inc		rdi
				jmp		found_sign
start_search:								; prepare search of the char
				mov		al, [rdi]			; get the char in param 1
				inc		rdi					; prepare next char in param
				cmp		al, 0				; if reach end of param 1
				je		end					; return r11 if end, else go search
				mov		r10, 0
				pop		rsi
				mov		rcx, rsi			; param 2
				push	rsi
loop3:
				cmp		al, [rcx]			; if found, add the number to r11
				je		add_number			; change to: go next char in param 1 if found already
				cmp		[rcx], byte 0		; if reached and of param 2, means char not in param 2 stop calculation
				je		end
				inc		rcx					; if not found and not reach and of param 2
				inc		r10					; count index of param 2 
				jmp		loop3
add_number:
				imul	r11, r8				; multiply r11 by r8,store value une r11
				add		r11, r10
				jmp		start_search
end:
				pop		rsi
				mov		rax, r11
				imul	rax, r13			; to get negatif number if r13 == -1
				ret
