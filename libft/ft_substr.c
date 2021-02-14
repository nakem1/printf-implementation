/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:37:11 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:49:25 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
** Function:		char *ft_substr
**
** Description:		Allocates (with malloc(3)) and returns a substring
** from the string ’s’.
** The substring begins at index ’start’ and is of
** maximum size ’len’.
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(str = (char *)malloc(1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (s[i] != s[start])
		i++;
	if (!(str = (char *)malloc((len * sizeof(char)) + 1)))
		return (NULL);
	while (j < len && s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
