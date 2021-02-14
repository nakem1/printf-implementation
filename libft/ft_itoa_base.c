/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:15:08 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/09 16:34:24 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static void		ft_baselen(unsigned long int digit, unsigned long int base, \
		int *len)
{
	while (digit)
	{
		digit /= base;
		*len += 1;
	}
}

static char		*get_register(int regist)
{
	if (regist == LOWERCASE)
		return ("0123456789abcdef");
	else if (regist == UPPERCASE)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

char			*ft_itoa_base(unsigned long long int value, \
		unsigned long long int base, int regist)
{
	int						len;
	unsigned long long int	digit;
	char					*return_str;
	char					*base_tmp;

	base_tmp = get_register(regist);
	if (value == 0)
	{
		return_str = (char *)ft_calloc(2, sizeof(char));
		return_str[0] = '0';
		return (return_str);
	}
	len = 0;
	digit = value;
	ft_baselen(digit, base, &len);
	if (!(return_str = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (digit)
	{
		return_str[--len] = base_tmp[digit % base];
		digit /= base;
	}
	if (value < 0 && base == 10)
		return_str[0] = '-';
	return (return_str);
}
