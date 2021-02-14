/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 03:59:02 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 16:34:45 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_parsing.h"

/*
** 		Function:         void
**
** 		Description:      function which parse specificators from string and
** add them to the struct
*/

void			parse_specificators(t_args **args, int *i, char *str, \
		va_list *arg)
{
	parse_spec_flags(args, i, str);
	parse_spec_width(args, i, str, arg);
	parse_spec_accuracy(args, i, str, arg);
	parse_spec_modifiers(args, i, str);
	parse_spec_type(args, i, str);
}

/*
** 		Function:         void struct_initialization
**
** 		Description:      function which inititalization struct
*/

void			struct_initialization(t_args **args)
{
	t_args *tmp;

	tmp = *args;
	tmp->hyphen = NULL;
	tmp->plus = NULL;
	tmp->space = NULL;
	tmp->lattice = NULL;
	tmp->zero = NULL;
	tmp->width = -1;
	tmp->accuracy = -1;
	tmp->modifiers = NULL;
	tmp->type = NULL;
}

/*
** 		Function:         t_args		create_struct()
**
** 		Description:      function create and fill struct t_args
*/

int				create_struct(t_args **args, int *i, char *str, va_list *arg)
{
	if (!(*args = (t_args *)malloc(sizeof(t_args))))
		return (0);
	struct_initialization(args);
	parse_specificators(args, i, str, arg);
	return (1);
}
