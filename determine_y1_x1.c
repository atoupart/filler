/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_y1_x1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 20:01:09 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/18 20:01:13 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		determine_rim(t_struct *s, int i)
{
	find_point_player_bg(s);
	s->xinit = s->x1;
	s->yinit = s->y1;
	if (s->y1 > s->y - s->y1)
		s->i = s->y - s->y1;
	else
		s->i = s->y;
	if (s->x1 > s->x - s->x1)
		s->j = s->x - s->x1;
	else
		s->j = s->x;
	follow_rim(s);
}

void		follow_rim(t_struct *s)
{
	if (s->y1 <= s->y / 2 && s->i <= s->j)
	{
		s->yrim = 0;
		s->xrim = s->x1;
	}
	else if (s->y1 <= s->y / 2 && s->i > s->j)
	{
		s->yrim = s->y1;
		s->xrim = 0;
	}
	else if (s->y1 > s->y / 2 && s->i <= s->j)
	{
		s->yrim = s->y - 1;
		s->xrim = s->x1;
	}
	else if (s->y1 > s->y / 2 && s->i > s->j)
	{
		s->yrim = s->y1;
		s->xrim = s->x - 1;
	}
}

int			verif_rim(t_struct *s)
{
	int u;
	int h;

	u = 0;
	while (u <= s->y - 1)
	{
		h = 0;
		while (h <= s->x - 1)
		{
			if (s->plateau[u][h] == s->l_player)
				if (u == 0 || u == s->y - 1 || h == 0 || h == s->x - 1)
					return (1);
			h++;
		}
		u++;
	}
	return (0);
}

void		determine_y1_x1(t_struct *s, int k, int i)
{
	if (i == 0)
		determine_rim(s, i);
	s->rim = verif_rim(s);
	if (s->rim == 0 && k < 0)
	{
		s->x1 = s->xinit;
		s->y1 = s->yinit;
		s->x2 = s->xrim;
		s->y2 = s->yrim;
	}
	else
	{
		if (k < 0)
		{
			find_point_player_hg(s);
			find_point_opponent_hg(s);
		}
		else
		{
			find_point_player_bd(s);
			find_point_opponent_bd(s);
		}
	}
	recursive_find_best_points(s);
	orientate_piece(s);
}
