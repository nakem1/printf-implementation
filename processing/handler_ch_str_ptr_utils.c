/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_ch_str_ptr_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:49:13 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 06:03:58 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:         int		handling_bs_zero()
**
** 		Description:      fn which created for norm. Handling case with '\0'
*/

int			handling_bs_zero(t_args *args, char **return_str, int count)
{
	char *str;

	str = NULL;
	if (args->hyphen == NULL)
	{
		ft_putstr(*return_str + 1, ft_strlen(*return_str));
	}
	else
	{
		ft_putchar('\0');
		if (!(str = ft_substr((const char *)*return_str, 0, \
				ft_strlen(*return_str) - 1)))
			return (-1);
		ft_putstr(str, ft_strlen(str));
		free(str);
	}
	count = ft_strlen(*return_str);
	free(*return_str);
	return (count);
}

/*
** 		Function:         int		convert_ptr_hex()
**
** 		Description:      fn which created for norm. Convert to hex. print.
*/

int			convert_ptr_hex(char **return_str, unsigned long long int n, \
		int *count)
{
	if (!(*return_str = ft_itoa_base(n, 16, LOWERCASE)))
		return (-1);
	ft_putstr("0x", 2);
	ft_putstr(*return_str, ft_strlen(*return_str));
	*count = ft_strlen(*return_str) + 2;
	return (1);
}

/*
** 		Function:         int		work_ptr_wa()
**
** 		Description:      fn which created for norm. Insert width and accuracy
*/

int			work_ptr_wa(t_args *args, char **return_str, va_list *arg)
{
	if (work_ptr_accuracy(args, return_str, arg) == -1)
		return (-1);
	if (work_ptr_width(args, return_str, arg) == -1)
		return (-1);
	return (1);
}

/*
** 		Function:         int		work_ptr_wa()
**
** 		Description:      fn which created for norm. Insert width and accuracy
*/

int			work_str_wa(t_args *args, char **return_str, va_list *arg)
{
	if (work_str_accuracy(args, return_str, arg) == -1)
		return (-1);
	if (work_str_width(args, return_str, arg) == -1)
		return (-1);
	return (1);
}
