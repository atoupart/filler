/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 10:20:13 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/02 10:20:18 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			inside_search_position(t_struct *s, int y1, int x1)
{
	while (s->piece[s->py + s->j][s->app + s->i] != '*')
		s->i++;
	if (verif_piece_posable(s, y1, x1) == 1)
	{
		s->y1 = y1 - (s->py + s->j);
		s->x1 = x1 - (s->app + s->i);
		return (1);
	}
	else
		s->i++;
	return (0);
}

int			search_position(t_struct *s, int y1, int x1)
{
	int		nb;
	int		nb_star;

	s->j = 0;
	s->height = height_piece(s);
	s->py = find_first_star(s, 0);
	s->px = s->ap;
	while (s->py + s->j < s->height)
	{
		find_first_star(s, s->py + s->j);
		nb_star = nb_star_line(s, s->py + s->j);
		s->app = s->ap;
		nb = 0;
		s->i = 0;
		s->ecart = s->app - s->px;
		while (nb < nb_star)
		{
			if (inside_search_position(s, y1, x1))
				return (1);
			else
				nb++;
		}
		s->j++;
	}
	return (0);
}

int			verif_piece_posable(t_struct *s, int y1, int x1)
{
	int		j;
	int		px2;

	s->op = find_first_star(s, 0);
	px2 = s->ap;
	j = 0;
	while (s->op + j < s->height)
	{
		find_first_star(s, s->op + j);
		s->diff = s->ap - px2;
		if (verif_line_piece(s, j, y1, x1) == 1)
			j++;
		else
			return (0);
	}
	if (s->ok_star == 0)
		return (0);
	return (1);
}

int			inside_verif_ligne_piece(t_struct *s, int y1, int x1)
{
	s->xx = x1 + s->ii + s->diff - s->i - s->ecart;
	s->ppx = s->ap + s->ii;
	if (s->yy < 0 || s->xx < 0 || !s->plateau[s->yy][s->xx] ||\
		!s->piece[s->ppy][s->ppx])
		return (0);
	while (s->piece[s->ppy][s->ppx] != '*')
	{
		s->ii++;
		s->xx = x1 + s->ii + s->diff - s->i - s->ecart;
		s->ppx = s->ap + s->ii;
	}
	if (s->yy == y1 && s->xx == x1 && s->piece[s->ppy][s->ppx] == '*')
	{
		s->ok_star = 1;
		s->ii++;
	}
	else if (s->piece[s->ppy][s->ppx] == '*' && s->plateau[s->yy][s->xx] == '.')
		s->ii++;
	else
		return (0);
	return (1);
}

int			verif_line_piece(t_struct *s, int j, int y1, int x1)
{
	int		nb_star;
	int		nb;

	nb_star = nb_star_line(s, s->op + j);
	nb = 0;
	s->ii = 0;
	s->yy = y1 + j - s->j;
	s->ppy = s->op + j;
	while (nb < nb_star)
	{
		if (!inside_verif_ligne_piece(s, y1, x1))
		{
			s->ok_star = 0;
			return (0);
		}
		nb++;
	}
	return (1);
}
