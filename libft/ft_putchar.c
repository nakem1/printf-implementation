/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 06:17:46 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/08 00:46:55 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

/*
** 		Function:         void      ft_putchar()
**
** 		Description:      print symbol
*/

void		ft_putchar(char ch)
{
	write(1, &ch, 1);
}
