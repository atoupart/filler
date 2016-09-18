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

int			search_position(t_struct *s, int y1, int x1)
{
	int		py;
	int		px;
	int		nb;
	int		nb_star;

	s->j = 0;
	s->height = height_piece(s);
	py = find_first_star(s, 0);
	px = s->ap;
	while (py + s->j < s->height)
	{
		find_first_star(s, py + s->j);
		nb_star = nb_star_line(s, py + s->j);
		s->app = s->ap;
		nb = 0;
		s->i = 0;
		s->ecart = s->app - px;
		while (nb < nb_star)
		{
			while (s->piece[py + s->j][s->app + s->i] != '*')
				s->i++;
			if (verif_piece_posable(s, y1, x1) == 1)
			{
				s->y1 = y1 - (py + s->j);
				s->x1 = x1 - (s->app + s->i);
				return (1);
			}
			else
			{
				nb++;
				s->i++;
			}
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

int			verif_line_piece(t_struct *s, int j, int y1, int x1)
{
	int		nb_star;
	int		nb;
	int		i;
	int		x;
	int		y;
	int		px;
	int		py;

	nb_star = nb_star_line(s, s->op + j);
	nb = 0;
	i = 0;
	y = y1 + j - s->j;
	py = s->op + j;
	while (nb < nb_star)
	{
		x = x1 + i + s->diff - s->i - s->ecart;
		px = s->ap + i;
		if (y < 0 || x < 0 || !s->plateau[y][x] || !s->piece[py][px])
		{
			s->ok_star = 0;
			return (0);
		}
		while (s->piece[py][px] != '*')
		{
			i++;
			x = x1 + i + s->diff - s->i - s->ecart;
			px = s->ap + i;
		}
		if (y == y1 && x == x1 && s->piece[py][px] == '*')
		{
			s->ok_star = 1;
			i++;
		}
		else if (s->piece[py][px] == '*' && s->plateau[y][x] == '.')
			i++;
		else
		{
			s->ok_star = 0;
			return (0);
		}
		nb++;
	}
	return (1);
}
