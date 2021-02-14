/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:31:11 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:49:41 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
** Function:		char *ft_strdup
**
** Description:		The ft_strdup() function allocates sufficient memory for a
** copy of thestring s1, does the copy, and returns a pointer to it.
** The pointer may subsequently be used as an argument to the function free(3).
*/

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(s);
	if (!(dest = (char *)malloc((n * sizeof(char)) + 1)))
		return (NULL);
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[n] = '\0';
	return (dest);
}
