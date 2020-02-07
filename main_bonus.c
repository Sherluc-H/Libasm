/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:00:21 by lhuang            #+#    #+#             */
/*   Updated: 2020/02/07 19:47:55 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi_base(char*, char*);

int		main()
{
					//ft_atoi_base
	printf("\t\t\tFT_ATOI_BASE\n");

	printf("%d\n", ft_atoi_base("123", "0123456789"));
	printf("%d\n", ft_atoi_base("0101010", "01"));
	printf("%d\n", ft_atoi_base("101010", "01"));
	printf("%d\n", ft_atoi_base("123abc", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("1235588", "01234567"));
	printf("%d\n", ft_atoi_base("    123", "0123456789"));
	printf("%d\n", ft_atoi_base("    -\n\t\t\v\r123", "0123456789"));
	printf("%d\n", ft_atoi_base("    ++++-------123", "0123456789"));
	printf("%d\n", ft_atoi_base("    ++++--123", "0123456789"));
	printf("%d\n", ft_atoi_base("  -123", "0123456789"));
	printf("%d\n", ft_atoi_base("   +123", "0123456789"));
	printf("%d\n", ft_atoi_base("   ++++123idhofihnfh", "0123456789"));
	return (0);
}
