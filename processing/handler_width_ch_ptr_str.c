/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_width_ch_ptr_str.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:38:43 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/09 04:07:53 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:         int		convert_hex()
**
** 		Description:      fn which convert to hex
*/

int				convert_hex(unsigned long long int n, char **str_tmp)
{
	if (n == 0)
	{
		if (!(*str_tmp = ft_strdup("0")))
			return (-1);
	}
	else
	{
		if (!(*str_tmp = ft_itoa_base(n, 16, LOWERCASE)))
			return (-1);
	}
	return (1);
}

/*
** 		Function:         void		work_ptr_width()
**
** 		Description:      function which add accuracy to the output string
*/

int				work_ptr_accuracy(t_args *args, char **return_str, \
		va_list *arg)
{
	int						size_accuracy;
	char					*str_tmp;
	char					*str;
	unsigned long long int	n;

	str_tmp = NULL;
	str = NULL;
	if (args->accuracy != -1)
	{
		size_accuracy = args->accuracy;
		n = va_arg(*arg, unsigned long long int);
		if (!(str = ft_itoa_base(n, 16, LOWERCASE)))
			return (-1);
		if (!(*return_str = ft_substr(str, 0, size_accuracy)))
			return (-1);
		free(str);
		if (!(str_tmp = ft_strjoin("0x", *return_str)))
			return (-1);
		free(*return_str);
		*return_str = str_tmp;
	}
	return (1);
}

/*
** 		Function:         void		work_ptr_width()
**
** 		Description:      function which add width to the output string
*/

int				work_ptr_width(t_args *args, char **return_str, \
		va_list *arg)
{
	int						size_width;
	char					*str_tmp;
	unsigned long long int	n;

	if (args->width != -1)
	{
		size_width = args->width;
		if (*return_str == NULL)
		{
			n = va_arg(*arg, unsigned long long int);
			if (convert_hex(n, &str_tmp) == -1)
				return (-1);
			if (!(*return_str = ft_strjoin("0x", str_tmp)))
				return (-1);
			free(str_tmp);
		}
		if (!insert_width(args, return_str, size_width, 1))
			return (-1);
	}
	return (1);
}

/*
** 		Function:         void		work_char_width()
**
** 		Description:      function which add width to the output string
*/

int				work_char_width(t_args *args, char **return_str, \
		va_list *arg, char *arg_ch)
{
	int		size_width;
	char	*str;

	if (!(str = (char *)ft_calloc(2, sizeof(char))))
		return (-1);
	if (args->width != -1)
	{
		size_width = args->width;
		*arg_ch = va_arg(*arg, unsigned int);
		str[0] = *arg_ch;
		if (!insert_width(args, &str, size_width, 1))
			return (-1);
		free(*return_str);
		if (!(*return_str = ft_strdup(str)))
			return (-1);
	}
	free(str);
	return (1);
}
