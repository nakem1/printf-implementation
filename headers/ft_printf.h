/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 06:05:10 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 16:35:24 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../headers/t_args.h"
# include "../headers/libft.h"

int			create_struct(t_args **args, int *i, char *str, va_list *arg);
int			processing(t_args *args, va_list *arg, int *return_len);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
