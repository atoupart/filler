/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_position2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 05:40:32 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/10 05:40:34 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			inside_search_position1(t_struct *s, int nb_star, int pxx)
{
	find_first_star(s, s->height - s->j);
	find_last_star(s, s->height - s->j);
	nb_star = nb_star_line(s, s->height - s->j);
	s->i = 0;
	s->ecart = s->app - pxx;
	return (nb_star);
}

int			inside_search_position2(t_struct *s, int y1, int x1)
{
	while (s->piece[s->height - s->j][s->app - s->i] != '*')
		s->i++;
	if (verif_piece_posable2(s, y1, x1) == 1)
	{
		s->y1 = y1 - s->diff_h - s->py + s->j;
		s->x1 = x1 - s->diff_l - s->px + s->i - s->ecart;
		return (1);
	}
	else
		s->i++;
	return (0);
}

int			search_position2(t_struct *s, int y1, int x1)
{
	int		pxx;
	int		nb;
	int		nb_star;

	s->j = 0;
	s->height = height_piece(s) - 1;
	s->py = find_first_star(s, 0);
	s->px = find_apleft(s);
	find_last_star(s, s->yp - 1);
	pxx = s->app;
	s->j = 0;
	while (s->height - s->j > s->py - 1)
	{
		nb = 0;
		nb_star = inside_search_position1(s, nb_star, pxx);
		while (nb < nb_star)
		{
			if (inside_search_position2(s, y1, x1))
				return (1);
			else
				nb++;
		}
		s->j++;
	}
	return (0);
}

int			verif_piece_posable2(t_struct *s, int y1, int x1)
{
	int		j;
	int		px2;

	s->op = find_first_star(s, 0);
	px2 = find_apleft(s);
	j = 0;
	while (s->op + j < s->height + 1)
	{
		find_first_star(s, s->op + j);
		s->diff = s->ap - px2;
		if (verif_line_piece2(s, j, y1, x1) == 1)
			j++;
		else
			return (0);
	}
	if (s->ok_star == 0)
		return (0);
	return (1);
}

int			verif_line_piece2(t_struct *s, int j, int y1, int x1)
{
	int		nb_star;
	int		nb;

	nb_star = nb_star_line(s, s->op + j);
	nb = 0;
	s->ii = 0;
	s->yy = y1 + j + s->j - s->diff_h;
	s->ppy = s->op + j;
	while (nb < nb_star)
	{
		if (!inside_verif_ligne_piece2(s, y1, x1))
		{
			s->ok_star = 0;
			return (0);
		}
		nb++;
	}
	return (1);
}
