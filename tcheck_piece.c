/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcheck_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 19:29:47 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/23 19:55:46 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void		tcheck_piece_height(t_struct *s)
{
	int j;
	int i;
	int ver;

	j = 0;
	while (j < s->yp)
	{
		i = 0;
		ver = 0;
		while (i < s->xp)
		{
			if (s->piece[j][i] == '*')
				ver = 1;
			i++;
		}
		if (ver)
			s->h++;
		j++;
	}
}

void			tcheck_piece_width(t_struct *s)
{
	int j;
	int i;
	int ver;

	i = 0;
	while (i < s->xp)
	{
		j = 0;
		ver = 0;
		while (j < s->yp)
		{
			if (s->piece[j][i] == '*')
				ver = 1;
			j++;
		}
		if (ver)
			s->w++;
		i++;
	}
}
