/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_wa_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:19:18 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 23:01:11 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:         void		work_str_width()
**
** 		Description:      function which add width to the output string
*/

int				work_str_width(t_args *args, char **return_str, \
		va_list *arg)
{
	int		size_width;
	char	*str;

	str = NULL;
	if (args->width != -1)
	{
		size_width = args->width;
		if (*return_str == NULL)
		{
			str = va_arg(*arg, char *);
			if (str == NULL)
			{
				if (!(*return_str = ft_strdup("(null)")))
					return (-1);
			}
			else
			{
				if (!(*return_str = ft_strdup(str)))
					return (-1);
			}
		}
		if (!insert_width(args, return_str, size_width, 1))
			return (-1);
	}
	return (1);
}

/*
** 		Function:         void		work_str_width()
**
** 		Description:      function which add accuracy to the output string
*/

int				work_str_accuracy(t_args *args, char **return_str, \
		va_list *arg)
{
	int		size_accuracy;
	char	*str;
	char	*str_tmp;

	str_tmp = NULL;
	if (args->accuracy != -1)
	{
		str = NULL;
		size_accuracy = args->accuracy;
		str = va_arg(*arg, char *);
		if (str == NULL)
		{
			if (!(str_tmp = ft_strdup("(null)")))
				return (-1);
			if (!(*return_str = ft_substr(str_tmp, 0, size_accuracy)))
				return (-1);
			free(str_tmp);
		}
		else
		{
			if (!(*return_str = ft_substr(str, 0, size_accuracy)))
				return (-1);
		}
	}
	return (1);
}
