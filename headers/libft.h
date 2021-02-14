/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:21:23 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 01:43:16 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define LOWERCASE 10
# define UPPERCASE 20

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *str);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_itoa(int n);
char				*ft_itoa_unsign(unsigned int n);
char				*ft_itoa_base(unsigned long long int value, \
		unsigned long long int base, int regist);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s);
void				ft_putchar(char ch);
void				ft_putstr(char *str, int count);
void				ft_putnbr(unsigned int nb);
int					ft_nbrlen(void *n, char type);
char				*ft_substr(const char *s, unsigned int start, size_t len);

#endif
