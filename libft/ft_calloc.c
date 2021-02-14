/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:17:52 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 21:14:49 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
** Function:		void	*ft_calloc(size_t count, size_t size
**
** Description:		The calloc() function contiguously allocates enough space
** for count objects that are size bytes of memory each and returns a pointer
** to the allocated memory.  The allocated memory is filled with  bytes of
** value zero
*/

void	*ft_calloc(size_t count, size_t size)
{
	void *tmp;

	if (!(tmp = (void *)malloc(count * size)))
		return (NULL);
	ft_bzero(tmp, size * count);
	return (tmp);
}
