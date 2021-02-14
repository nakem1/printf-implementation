/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 08:44:21 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/02 11:41:36 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/libft.h"

/*
** Function:		static char
**
** Description:		reverses the string and adds minus sign
*/

static char		*ft_strrev(char *str, int count)
{
	int		i;
	char	*str1;

	i = 0;
	if (!(str1 = (char *)ft_calloc(count * sizeof(char) + 1, 1)))
		return (NULL);
	while (count - 1 >= 0)
		str1[i++] = str[--count];
	free(str);
	return (str1);
}

/*
** Function: special_argiment
**
** Description: handles special cases. 0 and lower limit int
*/

static void		*special_argiment(char **num)
{
	if (!(*num = (char *)ft_calloc(2, 1)))
		return (NULL);
	num[0][0] = '0';
	return (*num);
}

static void		*allocate_num(int n, int *count, char *num)
{
	unsigned int tmp;

	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		*count += 1;
	}
	if (!(num = (char *)ft_calloc(*count * sizeof(char) + 1, 1)))
		return (NULL);
	return (num);
}

static int		checker(char **num, unsigned int *n)
{
	unsigned int	x;

	x = *n;
	if (x == 0)
	{
		if (special_argiment(num) != NULL)
			return (1);
		else
			return (0);
	}
	*n = x;
	return (2);
}

char			*ft_itoa_unsign(unsigned int n)
{
	int				i;
	char			*num;
	int				count;
	unsigned int	tmp;

	num = NULL;
	tmp = checker(&num, &n);
	if (tmp == 1)
		return (num);
	else if (tmp == 0)
		return (NULL);
	i = 0;
	count = 0;
	if (!(num = allocate_num(n, &count, num)))
		return (NULL);
	while (i < count)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_strrev(num, count));
}
