/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:56:19 by lhuang            #+#    #+#             */
/*   Updated: 2020/02/07 18:21:35 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct		s_list
{
	void			*data;
	char			*str;
}					t_list;

size_t		ft_strlen(const char*);
char		*ft_strcpy(char*, const char*);
int			ft_strcmp(const char*, const char*);
ssize_t		ft_write(int, const void*, size_t);
ssize_t		ft_read(int, void*, size_t);
char		*ft_strdup(const char *);
int			ft_atoi_base(const char*, const char*);
//char		*ft_list_push_front(char *);
//t_list		*ft_list_push_front(t_list**);

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
	printf("%s\n", ft_strcpy(dest1, ""));
	printf("%s\n", strcpy(dest2, ""));
//	char dest5[10];
//	char dest6[10];
//	printf("%s\n", ft_strcpy(dest1, NULL));
//	printf("%s\n", strcpy(dest2, NULL));
//	char dest7[1];
//	char dest8[1];
//	printf("%s\n", ft_strcpy(dest7, "abc"));
//	printf("%s\n", strcpy(dest8, "abc"));
	char *dest9 = "abcdef";
	char *dest10 = "abcdef";
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
						//ft_read	
	printf("\t\t\tFT_READ\n");
	char t1[10];
	char t2[10];
	int fd;
	fd = open("test", O_RDONLY);
	printf("=%zd\n", ft_read(fd, t1, 5));
	write(1, &t1, 5);
	close(fd);
	fd = open("test", O_RDONLY);
	printf("=%zd\n", read(fd, t2, 5));
	write(1, &t2, 5);

/*	char t3[10];
	char t4[10];
	printf("!=%zu\n", ft_read(0, t3, 5));
	printf("!=%zu\n", read(0, t4, 5));
	char t5[10];
	char t6[10];
	printf("!=%zu\n", ft_read(-1, t3, 5));
	printf("!=%zu\n", read(-1, t4, 5));
*/
						//ft_strdup
	printf("\t\t\tFT_STRDUP\n");
	char *p;
	p = ft_strdup("a");
	printf("%s\n", p);
	free(p);
	//free(p);
	p = NULL;

	printf("%s\n", ft_strdup("abced"));
	printf("%s\n", strdup("abced"));
//	printf("%s\n", ft_strdup(NULL));
//	printf("%s\n", strdup(NULL));
	printf("%s\n", ft_strdup("abcihfjcnd\0dsndfsnfd"));
	printf("%s\n", strdup("abcihfjcnd\0dsndfsnfd"));
	printf("-%s-\n", ft_strdup(""));
	printf("-%s-\n", strdup(""));
	printf("%s\n", p);
	system("leaks a.out");

						//ft_atoi_base
	printf("\t\t\tFT_ATOI_BASE\n");
	printf("%d\n", ft_atoi_base("123", "0123456789"));
	printf("%d\n", ft_atoi_base("123", "01234567+89"));
	printf("%d\n", ft_atoi_base("123", "01234567890"));
	printf("%d\n", ft_atoi_base("123", "01234567892"));
	printf("%d\n", ft_atoi_base("   123", "01234567891"));
	printf("%d\n", ft_atoi_base("123", "01234556789"));
	printf("%d\n", ft_atoi_base("123", "01234056789"));

	printf("b%d\n", ft_atoi_base("   110101", "01"));
	printf("a%d\n", ft_atoi_base("  -\n\t\v\r  --+-+-+10101", "01"));
	printf("%d\n", ft_atoi_base("111", "1"));

						//ft_list_push_front
//	char *str;
//	str = malloc(sizeof(char) * 4);
//	str = "abc";
//	char *str2 = ft_list_push_front(&str);
/*	t_list *list;
	list = malloc(sizeof(t_list));
	list->data = "abc";
	list->str = "abcdef";
	t_list *p1;
	p1 = ft_list_push_front(&list);
	printf("%s, %s, %s, %s\n", list->str, list->data, p1->str, p1->data);*/
	//printf("%p, %s, %p, %p, %p, %lu\n", &str, str, &list, &list->data, &list->str, sizeof(list));
//	printf("%p, %p, %p, %s, %lu\n", &list, &list->data, &list->str, list->str, sizeof(list));
//	t_list *ab = p1;
//printf("%s, %s, %p, %s, %s\n", p1->data, p1->str, p1, (*p1).str, ab->str);
//	printf("%p, %p, %p\n", &p1, &p1->str, &p1->data);
	printf("%d, %d, %d, %d, %d, %d, %d, %d\n", ' ', '\t', '\v', '\n', '\r', '\f', '+', '-');
	printf("%d\n", atoi("2147483647564165612"));
	printf("%d\n", ft_atoi_base("2147483647564165612", "0123456789"));
	return (0);
}
