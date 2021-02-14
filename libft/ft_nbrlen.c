/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 06:33:37 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:49:14 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
** 		Function:         		static size_t		work_with_int()
**
** 		Description:      		function which work with int
*/

static size_t		work_with_int(int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/*
** 		Function:         static size_t		work_with_unsigned()
**
** 		Description:      function which work with unsigned int
*/

static size_t		work_with_unsigned(unsigned int n)
{
	size_t count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/*
** 		Function:         int		ft_nbrlen()
**
** 		Description:      function which counts the rank of the number
*/

int					ft_nbrlen(void *n, char type)
{
	int				*n_int;
	unsigned int	*n_unsign;
	size_t			count;

	count = 0;
	if (type == 'i' || type == 'd')
	{
		n_int = (int *)n;
		count = work_with_int(*n_int);
	}
	else if (type == 'u')
	{
		n_unsign = (unsigned int *)n;
		count = work_with_unsigned(*n_unsign);
	}
	return (count);
}
