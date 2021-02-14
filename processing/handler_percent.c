/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 06:39:25 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 01:51:22 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

int				add_percent_specificators(t_args *args, int *return_len)
{
	char			*return_str;
	size_t			count;

	return_str = NULL;
	if (!work_percent_width(args, &return_str))
		return (0);
	if (return_str == NULL)
	{
		ft_putchar('%');
		*return_len += 1;
		return (1);
	}
	else
		ft_putstr(return_str, ft_strlen(return_str));
	count = ft_strlen(return_str);
	free(return_str);
	*return_len += count;
	return (1);
}

/*
** 		Function:         void		work_percent_width()
**
** 		Description:      function which handling percent character
*/

void			*work_percent_width(t_args *args, char **return_str)
{
	int		size_width;
	char	*str;

	if (!(str = (char *)ft_calloc(2, sizeof(char))))
		return (NULL);
	if (args->width != -1)
	{
		size_width = args->width;
		str[0] = '%';
		if (!insert_width(args, &str, size_width, 1))
			return (NULL);
		free(*return_str);
		if (!(*return_str = ft_strdup(str)))
			return (NULL);
	}
	free(str);
	return (return_str);
}
