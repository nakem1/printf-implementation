/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_width_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:30:23 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/09 16:14:04 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:         void		insert_left_width()
**
** 		Description:      function which insert spaces or nulls left
*/

void			*insert_width(t_args *args, char **return_str, \
		int size_width, int n)
{
	if (!insert_left_zero(args, return_str, size_width, n))
		return (NULL);
	if (!insert_left_spaces(args, return_str, size_width))
		return (NULL);
	if (!insert_right_spaces(args, return_str, size_width))
		return (NULL);
	return (return_str);
}

/*
** 		Function:         void		insert_left_zero()
**
** 		Description:      function which insert left zero, when flags
** 05d for example
*/

void			*insert_left_zero(t_args *args, char **str, \
		int size_width, int n)
{
	char *str_tmp;
	char *nullspaces;

	str_tmp = NULL;
	if (args->zero != NULL && args->hyphen == NULL \
			&& size_width > (int)ft_strlen(*str))
	{
		if (args->accuracy == -1)
		{
			if (!create_nullspace(size_width - ft_strlen(*str), \
					&nullspaces, '0'))
				return (NULL);
			if (!handler_minus(&nullspaces, str, n, args))
				return (NULL);
		}
		else
		{
			if (!create_nullspace(size_width - ft_strlen(*str), \
					&nullspaces, ' '))
				return (NULL);
		}
		if (join_str(str, &nullspaces, &str_tmp) == -1)
			return (NULL);
	}
	return (str);
}

/*
** 		Function:         void		insert_left_zero()
**
** 		Description:      function which insert left spaces
*/

void			*insert_left_spaces(t_args *args, char **str, \
		int size_width)
{
	char *str_tmp;
	char *nullspaces;

	str_tmp = NULL;
	if (args->zero == NULL && args->hyphen == NULL \
			&& size_width > (int)ft_strlen(*str))
	{
		if (!create_nullspace(size_width - ft_strlen(*str), &nullspaces, ' '))
			return (NULL);
		if (!(str_tmp = ft_strjoin((const char *)nullspaces, \
				(const char *)*str)))
			return (NULL);
		free(nullspaces);
		free(*str);
		*str = str_tmp;
	}
	return (str);
}

/*
** 		Function:         void		insert_with_hyphen()
**
** 		Description:      function which handling hyphen
*/

void			*insert_right_spaces(t_args *args, char **str, \
		int size_width)
{
	char *str_tmp;
	char *nullspaces;

	str_tmp = NULL;
	if (args->hyphen != NULL && size_width > (int)ft_strlen(*str))
	{
		if (!create_nullspace(size_width - ft_strlen(*str), &nullspaces, ' '))
			return (NULL);
		if (!(str_tmp = ft_strjoin((const char *)*str, \
				(const char *)nullspaces)))
			return (NULL);
		free(nullspaces);
		free(*str);
		*str = str_tmp;
	}
	return (str);
}

/*
** 		Function:         void		create_nulls_str()
**
** 		Description:      function which create nulls str
*/

void			*create_nullspace(int count, char **nullspace, char tmp)
{
	int i;

	i = 0;
	if (count > 0)
	{
		if (!(*nullspace = (char *)malloc((count + 1) * sizeof(char))))
			return (NULL);
		nullspace[0][count] = '\0';
		while (i < count)
		{
			nullspace[0][i] = tmp;
			i++;
		}
	}
	return (nullspace);
}
