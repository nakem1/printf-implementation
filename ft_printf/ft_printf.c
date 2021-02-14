/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 03:59:02 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 16:34:52 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

/*
** 		Function:         int       parse_one_argument()
**
** 		Description:      function parse all flags/modificators/types etc
*/

int			work_with_one_argument(int *i, char *str, va_list *arg, \
		int *return_len)
{
	t_args *args;

	*i += 1;
	if (create_struct(&args, i, str, arg) == 0)
		return (0);
	if (processing(args, arg, return_len) == 0)
		return (0);
	free(args);
	return (1);
}

/*
** 		Function:         int       ft_printf()
**
** 		Description:      My ft_printf. The function completely
** mimics the behavior of printf()
*/

int			ft_printf(char *str, ...)
{
	int		i;
	int		return_len;
	va_list arg;

	i = 0;
	return_len = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i++]);
			return_len++;
		}
		else
		{
			if (work_with_one_argument(&i, str, &arg, &return_len) == 0)
				return (-1);
		}
	}
	va_end(arg);
	return (return_len);
}
