/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec_types_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:31:26 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 01:16:06 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_parsing.h"

/*
** 		Function:         void		hex_add_struct()
**
** 		Description:      function that changes the structure by adding
** a hex type
*/

int				hex_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}

/*
** 		Function:         void		unsigned_add_struct()
**
** 		Description:      function that changes the structure by adding
** a unsigned int type
*/

int				unsigned_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'u')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}

/*
** 		Function:         void		int_add_struct()
**
** 		Description:      function that changes the structure by adding
** a int type
*/

t_args			*int_add_struct(t_args *args, int *i, char *str)
{
	args->type = (void *)&str[*i];
	*i += 1;
	return (args);
}

int				percent_add_struct(t_args **args, int *i, char *str)
{
	if (str[*i] == '%')
	{
		(*args)->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	else
		return (0);
}

void			hello_norm(short *fl_hyphen, short *fl_plus, short *fl_space)
{
	*fl_hyphen = 0;
	*fl_plus = 0;
	*fl_space = 0;
}
