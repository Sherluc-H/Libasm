# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 16:51:31 by lhuang            #+#    #+#              #
#    Updated: 2020/02/07 18:05:16 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			global	_ft_write
			section	.text
_ft_write:
			mov		rax, 0x02000004 ; write syscall
			syscall					;
			cmp		rdx, 0			; if write ok rdx == 0
			je		ok
			mov		rax, -1			; if not ok return -1
			ret						;
ok:
			ret						;
