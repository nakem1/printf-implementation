/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_int_unsign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:36:47 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 01:42:22 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:        int work_int_wa()
**
** 		Description:      add accurracy and width
*/

static int				work_int_wa(t_args *args, int *d, char **return_str, \
		va_list *arg)
{
	*return_str = NULL;
	if (work_int_accuracy(args, d, return_str, arg) == -1)
		return (-1);
	if (work_int_width(args, d, return_str, arg) == -1)
		return (-1);
	return (1);
}

/*
** 		Function:         void		add_specificators()
**
** 		Description:      function which add specificators to str
*/

int						add_int_specificators(t_args *args, int *d, \
		va_list *arg)
{
	char			*return_str;
	int				tmp;
	int				count;

	if (work_int_wa(args, d, &return_str, arg) == -1)
		return (-1);
	if (return_str == NULL)
	{
		tmp = va_arg(*arg, int);
		if (!ft_memcmp(args->type, (void *)"u", 1))
		{
			if (!(return_str = ft_itoa_unsign((unsigned int)tmp)))
				return (-1);
		}
		else
		{
			if (!(return_str = ft_itoa(tmp)))
				return (-1);
		}
	}
	count = ft_strlen(return_str);
	ft_putstr(return_str, count);
	free(return_str);
	return (count);
}

/*
** 		Function:         void		handler_int()
**
** 		Description:      function which handling and print
*/

int						select_handler_int_unsign(t_args *args, va_list *arg, \
		int *return_len)
{
	int		d;
	int		tmp;

	d = 0;
	tmp = add_int_specificators(args, &d, arg);
	if (tmp == -1)
		return (0);
	*return_len += tmp;
	return (1);
}
