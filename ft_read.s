# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 17:03:56 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 18:02:42 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global _ft_read
			section .text
_ft_read:
			mov		rax, 0x02000003		; read syscall
			syscall
			cmp		rdx, 0
			je		exit
			mov		rax, -1				; value to return if rdx != 0
			ret
exit:
			ret
