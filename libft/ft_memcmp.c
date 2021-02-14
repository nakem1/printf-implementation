/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:58:01 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:47:00 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
** Function:		int ft_memcmp
**
** Description:		The ft_memcmp() function compares byte string s1 against
** byte string s2.  Both strings are assumed to be n bytes long.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	const unsigned char		*str1;
	const unsigned char		*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n)
	{
		if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
