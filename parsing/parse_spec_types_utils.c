/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec_types_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:58:15 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:54:35 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_parsing.h"

/*
** 		Function:         int		bonus_add_struct()
**
** 		Description:      function that changes the structure by adding
** a bonus types
*/

int				bonus_add_struct(t_args **args, int *i, char *str)
{
	if (n_add_struct(args, i, str))
		return (1);
	if (double_add_struct(args, i, str))
		return (1);
	if (g_add_struct(args, i, str))
		return (1);
	if (e_add_struct(args, i, str))
		return (1);
	return (0);
}

/*
** 		Function:         int		n_add_struct()
**
** 		Description:      function that changes the structure by adding
** a n specificator
*/

int				n_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'n')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}

/*
** 		Function:         int			double_add_struct()
**
** 		Description:      function that changes the structure by adding
** a double type
*/

int				double_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'f')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}

/*
** 		Function:         int			g_add_struct()
**
** 		Description:      function that changes the structure by adding
** a g specificator
*/

int				g_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'g')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}

/*
** 		Function:         int			e_add_struct()
**
** 		Description:      function that changes the structure by adding
** a e specificator
*/

int				e_add_struct(t_args **args, int *i, char *str)
{
	t_args *tmp;

	tmp = *args;
	if (str[*i] == 'e')
	{
		tmp->type = (void *)&str[*i];
		*i += 1;
		return (1);
	}
	return (0);
}
