/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:25:54 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/09 13:36:08 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

int				processing_utils(t_args *args, va_list *arg, int *return_len, \
		char *types)
{
	if (!ft_memcmp(args->type, (void *)&types[6], 1) || \
			!ft_memcmp(args->type, (void *)&types[7], 1))
	{
		if (select_handler_hex(args, arg, return_len) == 0)
			return (0);
	}
	if (!ft_memcmp(args->type, (void *)&types[8], 1))
	{
		if (add_percent_specificators(args, return_len) == 0)
			return (0);
	}
	return (1);
}

/*
** 		Function:         int		processing()
**
** 		Description:      function which sends the structure
** to the required handler depending on the type
*/

int				processing(t_args *args, va_list *arg, int *return_len)
{
	char *types;

	types = "diucpsxX%nfge";
	if (!ft_memcmp(args->type, (void *)&types[0], 1) || \
			!ft_memcmp(args->type, (void *)&types[1], 1) || \
			!ft_memcmp(args->type, (void *)&types[2], 1))
	{
		if (select_handler_int_unsign(args, arg, return_len) == 0)
			return (0);
	}
	if (!ft_memcmp(args->type, (void *)&types[3], 1) || \
			!ft_memcmp(args->type, (void *)&types[4], 1) || \
			!ft_memcmp(args->type, (void *)&types[5], 1))
	{
		if (select_handler_ch_str_ptr(args, arg, return_len) == 0)
			return (0);
	}
	if (processing_utils(args, arg, return_len, types) == 0)
		return (0);
	return (1);
}
