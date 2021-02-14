/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:45:32 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:52:29 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_parsing.h"

/*
** 		Function:         int		ch_add_struct()
**
** 		Description:      function that changes the structure by adding
** a char type
*/

void				ch_add_struct(t_args **args, int *i, char *str)
{
	if (str[*i] == 'c')
	{
		(*args)->type = (void *)&str[*i];
		*i += 1;
	}
}

/*
** 		Function:         void		str_add_struct()
**
** 		Description:      function that changes the structure by adding
** a string type
*/

int					str_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 's')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}

/*
** 		Function:         void		ptr_add_struct()
**
** 		Description:      function that changes the structure by adding
** a ptr type
*/

int					ptr_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'p')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}
