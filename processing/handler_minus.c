/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:18:10 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 03:43:11 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_processing.h"

/*
** 		Function:         void		join_str()
**
** 		Description:      fn which created for norm. Join str with nulls
*/

int				join_str(char **str, char **nullspaces, char **str_tmp)
{
	if (!(*str_tmp = ft_strjoin((const char *)*nullspaces, \
			(const char *)*str)))
		return (-1);
	free(*nullspaces);
	free(*str);
	*str = *str_tmp;
	return (1);
}

/*
** 		Function:         void		*special_case_accurace()
**
** 		Description:      fn which handling special case
*/

static void		*special_case_acc(t_args *args, char **str1, char **nulls)
{
	int i;

	i = args->accuracy;
	if (!(*str1 = ft_strjoin("-", (const char *)*nulls)))
		return (NULL);
	free(*nulls);
	return (str1);
}

/*
** 		Function:         void		handler_minus()
**
** 		Description:      function which handling minus in the str
*/

void			*handler_minus(char **nulls, char **str, int n, t_args *args)
{
	char	*str1;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (n < 0)
	{
		if (!special_case_acc(args, &str1, nulls))
			return (NULL);
		if (!(*nulls = ft_strdup(str1)))
			return (NULL);
		free(str1);
		if (!(str1 = (char *)malloc(sizeof(char) * ft_strlen(*str))))
			return (NULL);
		str1[ft_strlen(*str) - 1] = '\0';
		while ((*str)[i++] != '\0')
		{
			if ((*str)[i] <= '9' && (*str)[i] >= '0')
				str1[j++] = (*str)[i];
		}
		free(*str);
		*str = str1;
	}
	return (str);
}
