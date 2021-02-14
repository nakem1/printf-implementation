/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:16:37 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 01:50:58 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:         int		convert_accuracy_hex()
**
** 		Description:      fn which created for the norm. Convert to the hex
** and add zero's
*/

static int		convert_accuracy_hex(t_args *args, char **return_str, \
		char **nulls, char **str)
{
	if (!create_nullspace(args->accuracy - ft_strlen(*return_str), \
			nulls, '0'))
		return (-1);
	if (!(*str = ft_strjoin((const char *)*nulls, (const char *)*return_str)))
		return (-1);
	free(*nulls);
	free(*return_str);
	return (1);
}

/*
** 		Function:         void		work_hex_accuracy()
**
** 		Description:      function which add width to the output string
*/

int				work_hex_accuracy(t_args *args, char **return_str, \
		va_list *arg, int regist)
{
	char			*str;
	unsigned int	n;
	char			*nulls;

	str = NULL;
	if (args->accuracy != -1)
	{
		if (!(nulls = ft_strdup("")))
			return (-1);
		n = va_arg(*arg, unsigned int);
		if (args->accuracy == 0 && n == 0)
		{
			if (!(*return_str = ft_strdup("")))
				return (-1);
			return (1);
		}
		if (!(*return_str = ft_itoa_base(n, 16, regist)))
			return (-1);
		if (convert_accuracy_hex(args, return_str, &nulls, &str) == -1)
			return (-1);
		*return_str = str;
	}
	return (1);
}

/*
** 		Function:         void		work_ptr_width()
**
** 		Description:      function which add width to the output string
*/

int				work_hex_width(t_args *args, char **return_str, \
		va_list *arg, int regist)
{
	int				size_width;
	unsigned int	n;

	if (args->width != -1)
	{
		size_width = args->width;
		n = va_arg(*arg, unsigned int);
		if (*return_str == NULL)
		{
			if (!(*return_str = ft_itoa_base(n, 16, regist)))
				return (-1);
		}
		if (!insert_width(args, return_str, size_width, 1))
			return (-1);
	}
	return (1);
}

/*
** 		Function:         size_t		add_hex_specificators()
**
** 		Description:      function which add "x" or "X" specificator
*/

int				add_hex_specificators(t_args *args, va_list *arg, int regist)
{
	char			*return_str;
	unsigned int	n;
	int				count;

	return_str = NULL;
	if (work_hex_accuracy(args, &return_str, arg, regist) == -1)
		return (-1);
	if (work_hex_width(args, &return_str, arg, regist) == -1)
		return (-1);
	if (return_str == NULL)
	{
		n = va_arg(*arg, unsigned int);
		if (!(return_str = ft_itoa_base(n, 16, regist)))
			return (-1);
		ft_putstr(return_str, ft_strlen(return_str));
	}
	else
		ft_putstr(return_str, ft_strlen(return_str));
	count = ft_strlen(return_str);
	free(return_str);
	return (count);
}

/*
** 		Function:         void		select_handler_hex()
**
** 		Description:      functnion which sends the struct to the
** required handle depending on the type
*/

int				select_handler_hex(t_args *args, va_list *arg, int *return_len)
{
	int tmp;

	tmp = 0;
	if (!ft_memcmp(args->type, (void *)"x", 1))
	{
		tmp = add_hex_specificators(args, arg, LOWERCASE);
		if (tmp == -1)
			return (0);
		*return_len += (int)tmp;
	}
	if (!ft_memcmp(args->type, (void *)"X", 1))
	{
		tmp = add_hex_specificators(args, arg, UPPERCASE);
		if (tmp == -1)
			return (0);
		*return_len += (int)tmp;
	}
	return (1);
}
