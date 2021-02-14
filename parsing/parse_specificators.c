/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specificators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 06:15:53 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 01:16:54 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_parsing.h"

/*
** 		Function:         void		parse_spec_flags()
**
** 		Description:      parse flags from string
*/

void			parse_spec_flags(t_args **args, int *i, char *str)
{
	short	fl_hyphen;
	short	fl_plus;
	short	fl_space;
	short	fl_lattice;
	short	fl_zero;

	fl_lattice = 0;
	fl_zero = 0;
	hello_norm(&fl_hyphen, &fl_plus, &fl_space);
	while (str[*i] == '-' || str[*i] == '+' || str[*i] == ' ' \
			|| str[*i] == '#' || str[*i] == '0')
	{
		if (fl_hyphen == 0)
			add_to_struct_hyphen(args, i, str, &fl_hyphen);
		if (fl_plus == 0)
			add_to_struct_plus(args, i, str, &fl_plus);
		if (fl_space == 0)
			add_to_struct_space(args, i, str, &fl_space);
		if (fl_lattice == 0)
			add_to_struct_lattice(args, i, str, &fl_lattice);
		if (fl_zero == 0)
			add_to_struct_zero(args, i, str, &fl_zero);
		*i += 1;
	}
}

/*
** 		Function:         void		parse_spec_width()
**
** 		Description:      parse width from string
*/

void			parse_spec_width(t_args **args, int *i, char *str, \
		va_list *arg)
{
	char	*star;
	int		width;
	char	*hyphen;

	hyphen = "-";
	star = "*";
	if (str[*i] == *star)
	{
		width = va_arg(*arg, int);
		if (width < 0)
		{
			(*args)->hyphen = (void *)&hyphen[0];
			width *= -1;
		}
		(*args)->width = width;
		*i += 1;
		return ;
	}
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		width = ft_atoi(&str[*i]);
		(*args)->width = width;
		while (str[*i] >= '0' && str[*i] <= '9')
			*i += 1;
	}
}

/*
** 		Function:         parse_spec_accuracy()
**
** 		Description:      parse accuracy from string
*/

void			parse_spec_accuracy(t_args **args, int *i, char *str, \
		va_list *arg)
{
	char	*star;
	int		accuracy;

	star = "*";
	if (str[*i] == '.')
	{
		*i += 1;
		if (str[*i] == *star)
		{
			accuracy = va_arg(*arg, int);
			if (accuracy < 0)
			{
				*i += 1;
				return ;
			}
			else
				(*args)->accuracy = accuracy;
			*i += 1;
			return ;
		}
		accuracy = ft_atoi(&str[*i]);
		(*args)->accuracy = accuracy;
		while (str[*i] >= '0' && str[*i] <= '9')
			*i += 1;
	}
}

/*
** 		Function:         void		parse_spec_modifiers()
**
** 		Description:      parse modifiers from string
*/

void			parse_spec_modifiers(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'l' || str[*i] == 'h')
	{
		tmp->modifiers = (void *)&str[*i];
		*i += 1;
	}
	if (str[*i + 1] == 'l' || str[*i + 1] == 'h')
		*i += 1;
}

/*
** 		Function:         void		parse_spec_type()
**
** 		Description:      parse types from string
*/

void			parse_spec_type(t_args **args, int *i, char *str)
{
	if (str[*i] == 'c')
	{
		ch_add_struct(args, i, str);
		return ;
	}
	if (str[*i] == 'i' || str[*i] == 'd')
	{
		*args = int_add_struct(*args, i, str);
		return ;
	}
	if (str_add_struct(args, i, str))
		return ;
	if (ptr_add_struct(args, i, str))
		return ;
	if (unsigned_add_struct(args, i, str))
		return ;
	if (hex_add_struct(args, i, str))
		return ;
	if (percent_add_struct(args, i, str))
		return ;
	bonus_add_struct(args, i, str);
}
