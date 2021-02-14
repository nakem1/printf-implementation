/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_args.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurray <lmurray@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 03:20:12 by lmurray           #+#    #+#             */
/*   Updated: 2020/12/07 18:37:14 by lmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARGS_H
# define T_ARGS_H

typedef struct			s_args
{
	void				*hyphen;
	void				*plus;
	void				*space;
	void				*lattice;
	void				*zero;
	int					width;
	int					accuracy;
	void				*modifiers;
	void				*type;
}						t_args;

#endif
