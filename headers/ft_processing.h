/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:07:35 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/09 16:16:39 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSING_H
# define FT_PROCESSING_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../headers/libft.h"
# include "../headers/t_args.h"

# define MINUS 1
# define PLUS 0

int			processing(t_args *args, va_list *arg, int *return_len);

int			select_handler_int_unsign(t_args *args, va_list *arg, \
		int *return_len);
int			select_handler_ch_str_ptr(t_args *args, va_list *arg, \
		int *return_len);
int			select_handler_hex(t_args *args, va_list *arg, \
		int *return_len);
void		select_handler_bonus(t_args *args, va_list *arg, \
		int *return_len);

int			add_int_specificators(t_args *args, int *d, va_list *arg);
int			add_char_specificators(t_args *args, va_list *arg);
int			add_str_specificators(t_args *args, va_list *arg);
int			add_ptr_specificators(t_args *args, va_list *arg);
int			add_percent_specificators(t_args *args, int *return_len);

int			work_int_accuracy(t_args *args, int *d, char **return_str, \
		va_list *arg);
int			work_int_width(t_args *args, int *d, char **return_str, \
		va_list *arg);

int			work_char_width(t_args *args, char **return_str, \
		va_list *arg, char *ch);
int			work_str_width(t_args *args, char **return_str, \
		va_list *arg);
int			work_str_accuracy(t_args *args, char **return_str, \
		va_list *arg);
int			work_ptr_width(t_args *args, char **return_str, \
		va_list *arg);
int			work_ptr_accuracy(t_args *args, char **return_str, \
		va_list *arg);
void		*work_percent_width(t_args *args, char **return_str);

void		*insert_width(t_args *args, char **str, int size_width, int n);
void		*insert_left_zero(t_args *args, char **str, int size_width, int n);
void		*insert_left_spaces(t_args *args, char **str, int size_width);
void		*insert_right_spaces(t_args *args, char **str, int size_width);
void		*handler_minus(char **nulls, char **str, int n, t_args *args);

int			work_with_star(va_list *arg);
void		*create_nullspace(int count, char **nulls, char tmp);

int			convert_ptr_hex(char **return_str, unsigned long long int n, \
		int *count);
int			work_ptr_wa(t_args *args, char **return_str, va_list *arg);
int			work_str_wa(t_args *args, char **return_str, va_list *arg);
int			handling_bs_zero(t_args *args, char **return_str, int count);
int			join_str(char **str, char **nullspaces, char **str_tmp);

#endif
