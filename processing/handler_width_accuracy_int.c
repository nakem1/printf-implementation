/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_width_accuracy_int.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 03:25:54 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 03:38:15 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

static int		unsigned_handling(t_args *args, char **str, int *d)
{
	if (!ft_memcmp(args->type, (void *)"u", 1))
	{
		if (!(*str = ft_itoa_unsign(((unsigned int)*d))))
			return (-1);
	}
	else
	{
		if (!(*str = ft_itoa(*d)))
			return (-1);
	}
	return (1);
}

/*
** 		Function:         int		insert_accuracy()
**
** 		Description:      function which created for norm. Fn insert nulls
** to the str
*/

static int		insert_accuracy(char **str, char **return_str, \
		t_args *args, int *d)
{
	int				difference;
	char			*nulls;
	int				size_str;

	if (*d < 0)
		size_str = ft_strlen(*str) - 1;
	else
		size_str = ft_strlen(*str);
	if ((difference = args->accuracy - size_str) > 0)
	{
		if (!create_nullspace(difference, &nulls, '0'))
			return (-1);
		if (!(handler_minus(&nulls, str, *d, args)))
			return (-1);
		if (!(*return_str = ft_strjoin((const char *)nulls, \
				(const char *)*str)))
			return (-1);
		free(nulls);
	}
	else
	{
		if (!(*return_str = ft_strdup((const char *)*str)))
			return (-1);
	}
	return (1);
}

/*
** 		Function:         void		work_accuracy()
**
** 		Description:      function which add accuracy to the output string
*/

int				work_int_accuracy(t_args *args, int *d, char **return_str, \
		va_list *arg)
{
	char			*str;

	str = NULL;
	if (args->accuracy != -1)
	{
		*d = va_arg(*arg, int);
		if (args->accuracy == 0 && *d == 0)
		{
			if (!(*return_str = ft_strdup("")))
				return (-1);
			return (1);
		}
		if (unsigned_handling(args, &str, d) == -1)
			return (-1);
		if (insert_accuracy(&str, return_str, args, d) == -1)
			return (-1);
		free(str);
	}
	return (1);
}

/*
** 		Function:         void		work_width()
**
** 		Description:      function which add width to the output string
*/

int				work_int_width(t_args *args, int *d, char **return_str, \
		va_list *arg)
{
	char			*str;

	if (args->width != -1)
	{
		if (*return_str == NULL)
		{
			*d = va_arg(*arg, int);
			if (unsigned_handling(args, &str, d) == -1)
				return (-1);
		}
		else
		{
			if (!(str = ft_strdup(*return_str)))
				return (-1);
		}
		if (!insert_width(args, &str, args->width, *d))
			return (-1);
		free(*return_str);
		*return_str = str;
	}
	return (1);
}
