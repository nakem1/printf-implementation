/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec_flags_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:48:10 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:56:25 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_parsing.h"

/*
** 		Function:         void			add_to_struct_hyphen()
**
** 		Description:      a function that changes the structure by adding
** a hyphen flag.
*/

void			add_to_struct_hyphen(t_args **args, int *i, char *str, \
		short *fl_hyphen)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == '-')
	{
		tmp->hyphen = (void *)&str[*i];
		*fl_hyphen += 1;
	}
}

/*
** 		Function:         void		add_to_struct_plus()
**
** 		Description:      a funtion that changes the struct by adding
** a plus flag
*/

void			add_to_struct_plus(t_args **args, int *i, char *str, \
		short *fl_plus)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == '+')
	{
		tmp->plus = (void *)&str[*i];
		*fl_plus += 1;
	}
}

/*
** 		Function:         void		add_to_struct_space()
**
** 		Description:      function that changes the struct by adding a space
*/

void			add_to_struct_space(t_args **args, int *i, char *str, \
		short *fl_space)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == ' ')
	{
		tmp->space = (void *)&str[*i];
		*fl_space += 1;
	}
}

/*
** 		Function:         void		add_to_struct_lattice()
**
** 		Description:      function that changes the struct by addin
** a lattice flag
*/

void			add_to_struct_lattice(t_args **args, int *i, char *str, \
		short *fl_lattice)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == '#')
	{
		tmp->lattice = (void *)&str[*i];
		*fl_lattice += 1;
	}
}

/*
** 		Function:         void		add_to_struct_zero()
**
** 		Description:      function that changes the struct by addin
** a lattice flag
*/

void			add_to_struct_zero(t_args **args, int *i, char *str, \
		short *fl_zero)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == '0')
	{
		tmp->zero = (void *)&str[*i];
		*fl_zero += 1;
	}
}
