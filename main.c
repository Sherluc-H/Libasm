/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:56:19 by lhuang            #+#    #+#             */
/*   Updated: 2020/02/08 13:55:31 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t		ft_strlen(const char*);
char		*ft_strcpy(char*, const char*);
int			ft_strcmp(const char*, const char*);
ssize_t		ft_write(int, const void*, size_t);
ssize_t		ft_read(int, void*, size_t);
char		*ft_strdup(const char *);

int	main(void)
{

						//ft_strlen
	printf("\t\t\tFT_STRLEN\n");
	printf("%zu\n", ft_strlen("Helloabcdefghijklmnopqrstuvwxyz"));
	printf("%zu\n", strlen("Helloabcdefghijklmnopqrstuvwxyz"));
	printf("%zu\n", ft_strlen(""));
	printf("%zu\n", strlen(""));
	printf("%zu\n", ft_strlen("HEY\0abc"));
	printf("%zu\n", strlen("HEY\0abc"));
//	printf("%zu\n", ft_strlen(NULL));
//	printf("%zu\n", strlen(NULL));
//	printf("%zu\n", ft_strlen());
//	printf("%zu\n", strlen());

						//ft_strcpy
	printf("\t\t\tFT_STRCPY\n");
	char dest1[10];
	char dest2[10];
	printf("%s\n", ft_strcpy(dest1, "abc"));
	printf("%s\n", strcpy(dest2, "abc"));
	char dest3[10];
	char dest4[10];
	printf("%s\n", ft_strcpy(dest3, ""));
	printf("%s\n", strcpy(dest4, ""));
//	char dest5[10];
//	char dest6[10];
//	printf("%s\n", ft_strcpy(dest1, NULL));
//	printf("%s\n", strcpy(dest2, NULL));
//	char dest7[1];
//	char dest8[1];
//	printf("%s\n", ft_strcpy(dest7, "abc"));
//	printf("%s\n", strcpy(dest8, "abc"));
//	char *dest9 = "abcdef";
//	char *dest10 = "abcdef";
//	printf("%s\n", dest9);
//	printf("%s\n", dest10);
//	printf("%s\n", ft_strcpy(dest9, "c"));
//	printf("%s\n", strcpy(dest10, "c"));

						//ft_strcmp
	printf("\t\t\tFT_STRCMP\n");
	printf("%d\n", ft_strcmp("bc", "bc8"));
	printf("%d\n", strcmp("bc", "bc8"));
	printf("%d\n", ft_strcmp("abc", "abct"));
	printf("%d\n", strcmp("abc", "abct"));
	printf("%d\n", ft_strcmp("abc", "a"));
	printf("%d\n", strcmp("abc", "a"));
	printf("%d\n", ft_strcmp("0", "9"));
	printf("%d\n", strcmp("0", "9"));
	printf("%d\n", ft_strcmp("0", "8"));
	printf("%d\n", strcmp("0", "8"));
	printf("%d\n", ft_strcmp("007", "007"));
	printf("%d\n", strcmp("007", "007"));
	printf("%d\n", ft_strcmp("abc", ""));
	printf("%d\n", strcmp("abc", ""));
	printf("%d\n", ft_strcmp("", "abc"));
	printf("%d\n", strcmp("", "abc"));

						//ft_write
	printf("\t\t\tFT_WRITE\n");
	printf("%zd\n", ft_write(1, "Hello \0aworld\n", 12));
	printf("%zd\n", write(1, "Hello \0aworld\n", 12));
	printf("%zd\n", ft_write(-3, "Hello \0aworld\n", 12));
	printf("%zd\n", write(-3, "Hello \0aworld\n", 12));
	printf("%zd\n", ft_write(-1, "Hello \0aworld\n", 12));
	printf("%zd\n", write(-1, "Hello \0aworld\n", 12));
	printf("%zd\n", ft_write(-1, "Hello \0aworld\n", 12));
	printf("%zd\n", write(-1, "Hello \0aworld\n", 12));
	printf("%zd\n", ft_write(0, "Hello \0aworld\n", 9));
	printf("%zd\n", write(0, "Hello \0aworld\n", 9));
	printf("%zd\n", ft_write(3, "Hello \0aworld\n", 9));
	printf("%zd\n", write(3, "Hello \0aworld\n", 9));
	printf("%zd\n", ft_write(2, "Hello \0aworld\n", 2));
	printf("%zd\n", write(2, "Hello \0aworld\n", 2));
						//ft_read	
	printf("\t\t\tFT_READ\n");
	char t1[10];
	char t2[10];
	int fd;
	fd = open("test", O_RDONLY);
	printf("=%zd\n", ft_read(fd, t1, 5));
	write(1, t1, 5);
	close(fd);
	fd = open("test", O_RDONLY);
	printf("=%zd\n", read(fd, t2, 5));
	write(1, t2, 5);
	close(fd);
	char t3[100];
	int a = ft_read(0, t3, 50);
	write(1, t3, a);
	printf("%d\n", a);
	char t4[100];
	int	b = read(0, t4, 50);
	write(1, t4, b);
	printf("%d\n", b);
	char t5[50];
	char t6[50];
	printf("!=%zu\n", ft_read(-1, t5, 5));
	printf("!=%zu\n", read(-1, t6, 5));

						//ft_strdup
	printf("\t\t\tFT_STRDUP\n");
	char *p;
	p = ft_strdup("a");
	printf("%s\n", p);
	free(p);
	//free(p);
	p = NULL;
	char *p2;
	p2 = strdup("a");
	printf("%s\n", p2);
	free(p2);
	//free(p2);
	p2 = NULL;
	printf("%s\n", ft_strdup("abced"));
	printf("%s\n", strdup("abced"));
//	printf("%s\n", ft_strdup(NULL));
//	printf("%s\n", strdup(NULL));
	printf("%s\n", ft_strdup("abcihfjcnd\0dsndfsnfd"));
	printf("%s\n", strdup("abcihfjcnd\0dsndfsnfd"));
	printf("-%s-\n", ft_strdup(""));
	printf("-%s-\n", strdup(""));
	printf("%s\n", p);
	printf("%s\n", p2);
//	system("leaks a.out");
	return (0);
}
