/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 07:53:42 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 01:15:13 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include <stdarg.h>
# include <stdlib.h>

# include "../headers/t_args.h"
# include "../headers/libft.h"

void			parse_specificators(t_args **args, int *i, char *str, \
		va_list *arg);
void			parse_spec_flags(t_args **args, int *i, char *str);
void			parse_spec_width(t_args **args, int *i, char *str, \
		va_list *arg);
void			parse_spec_accuracy(t_args **args, int *i, char *str, \
		va_list *arg);
void			parse_spec_modifiers(t_args **args, int *i, char *str);
void			parse_spec_type(t_args **args, int *i, char *str);

void			add_to_struct_hyphen(t_args **args, int *i, char *str, \
		short *fl_hyphen);
void			add_to_struct_plus(t_args **args, int *i, char *str, \
		short *fl_plus);
void			add_to_struct_space(t_args **args, int *i, char *str, \
		short *fl_space);
void			add_to_struct_lattice(t_args **args, int *i, char *str, \
		short *fl_lattice);
void			add_to_struct_lattice(t_args **args, int *i, char *str, \
		short *fl_lattice);
void			add_to_struct_zero(t_args **args, int *i, char *str, \
		short *fl_zero);

void			ch_add_struct(t_args **args, int *i, char *str);
int				str_add_struct(t_args **args, int *i, char *str);
int				ptr_add_struct(t_args **args, int *i, char *str);
int				hex_add_struct(t_args **args, int *i, char *str);
int				unsigned_add_struct(t_args **args, int *i, char *str);
void			hello_norm(short *fl_hyphen, short *fl_plus, short *fl_space);
t_args			*int_add_struct(t_args *args, int *i, char *str);
int				percent_add_struct(t_args **args, int *i, char *str);

int				bonus_add_struct(t_args **args, int *i, char *str);
int				n_add_struct(t_args **args, int *i, char *str);
int				double_add_struct(t_args **args, int *i, char *str);
int				g_add_struct(t_args **args, int *i, char *str);
int				e_add_struct(t_args **args, int *i, char *str);

#endif
