# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 16:57:42 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 18:24:26 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global	_ft_strdup
			extern	_malloc
			section	.text
_ft_strdup:
			push	rdi				; store in stack
			mov		rbx, rdi		; store first address of rdi in another register
			mov		r8, -1
count:								; get lenght of string
			mov		al, [rbx]		; store char
			inc		rbx				; go next char
			inc		r8				; increase the count
			cmp		al, 0			; check if end of string, if char equal 0
			jne		count
alloc:
			inc		r8				; add one for \0
			mov		rdi, r8			; use the size of r8 as param of malloc
			call	_malloc			;
			pop		rdi				; retrieve value from stack
			push	rax				; put the first address of the allocated memory in stack
			mov		rcx, rax		; store first address of allocated memory
count2:
			mov		al, [rdi]		; get char of string
			mov		[rcx], al		; put in the allocated address
			inc		rdi
			inc		rcx
			cmp		al, 0
			jne		count2			; until end of string
			mov		[rcx], byte 0	; add \0 at the end of the string
			pop		rax				; return first address of allacted address
			ret	
