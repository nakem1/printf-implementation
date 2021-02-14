/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 06:18:07 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/10 01:42:53 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
** 		Function:         void		ft_putstr()
**
** 		Description:      function which print string
*/

void			ft_putstr(char *str, int count)
{
	write(1, str, count);
}
