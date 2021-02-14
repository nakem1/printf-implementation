/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_ch_str_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:09:30 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 04:43:16 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:         size_t		add_ptr()
**
** 		Description:      function which add "p" specificator
*/

int				add_ptr_specificators(t_args *args, va_list *arg)
{
	char					*return_str;
	unsigned long long int	n;
	int						count;

	return_str = NULL;
	if (work_ptr_wa(args, &return_str, arg) == -1)
		return (-1);
	if (return_str == NULL)
	{
		n = va_arg(*arg, unsigned long long int);
		if (n == 0)
		{
			ft_putstr("0x0", 3);
			return (3);
		}
		if (convert_ptr_hex(&return_str, n, &count) == -1)
			return (-1);
	}
	else
	{
		ft_putstr(return_str, ft_strlen(return_str));
		count = ft_strlen(return_str);
	}
	free(return_str);
	return (count);
}

/*
** 		Function:         size_t		add_str_specificators()
**
** 		Description:      function which add "s" specificator
*/

int				add_str_specificators(t_args *args, va_list *arg)
{
	char	*return_str;
	char	*str;
	int		count;

	return_str = NULL;
	if (work_str_wa(args, &return_str, arg) == -1)
		return (-1);
	if (return_str == NULL)
	{
		str = va_arg(*arg, char *);
		if (str == NULL)
		{
			ft_putstr("(null)", 6);
			return (6);
		}
		ft_putstr(str, ft_strlen(str));
		if (!(return_str = ft_strdup(str)))
			return (-1);
	}
	else
		ft_putstr(return_str, ft_strlen(return_str));
	count = ft_strlen(return_str);
	free(return_str);
	return (count);
}

/*
** 		Function:         size_t		add_char_specificators()
**
** 		Description:      function which add "c" specificator to str
*/

int				add_char_specificators(t_args *args, va_list *arg)
{
	char	*return_str;
	char	ch;
	int		count;

	return_str = NULL;
	count = -1;
	ch = -1;
	if (work_char_width(args, &return_str, arg, &ch) == -1)
		return (-1);
	if (ch == '\0')
		return (handling_bs_zero(args, &return_str, count));
	if (return_str == NULL)
	{
		ch = va_arg(*arg, unsigned int);
		ft_putchar(ch);
		return (1);
	}
	else
		ft_putstr(return_str, ft_strlen(return_str));
	count = ft_strlen(return_str);
	free(return_str);
	return (count);
}

/*
** 		Function:         void		select_handler_ch_str_ptr()
**
** 		Description:      function which sends the struct to the
** required handle depending on the type
*/

int				select_handler_ch_str_ptr(t_args *args, va_list *arg, \
		int *return_len)
{
	int tmp;

	if (!ft_memcmp(args->type, (void *)"c", 1))
	{
		tmp = add_char_specificators(args, arg);
		if (tmp == -1)
			return (0);
		*return_len += tmp;
	}
	else if (!ft_memcmp(args->type, (void *)"s", 1))
	{
		tmp = add_str_specificators(args, arg);
		if (tmp == -1)
			return (0);
		*return_len += tmp;
	}
	else if (!ft_memcmp(args->type, (void *)"p", 1))
	{
		tmp = add_ptr_specificators(args, arg);
		if (tmp == -1)
			return (0);
		*return_len += tmp;
	}
	return (1);
}
