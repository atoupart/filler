/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:07:00 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/17 03:07:03 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int			find_direction(t_struct *s, int l)
{
	find_point_opponent_hg(s);
	if (s->y2 < s->y / 2)
	{
		if (s->x2 < s->x / 2)
			l = 1;
		else
			l = 2;
	}
	else
	{
		if (s->x2 < s->x / 2)
			l = 3;
		else
			l = 4;
	}
	return (l);
}

void	indicate_direction(t_struct *s, int l, int k)
{
	if (l == 1 && k == 1)
	{
		find_point_player_bg(s);
		s->y2 = s->y1;
		s->x2 = 0;
	}
	else if (l == 1)
	{
		find_point_player_hd(s);
		s->y2 = 0;
		s->x2 = s->x1;
	}
	else if (l == 2 && k == 1)
	{
		find_point_player_hg(s);
		s->y2 = 0;
		s->x2 = s->x1;
	}
	else if (l == 2)
	{
		find_point_player_bd(s);
		s->y2 = s->y1;
		s->x2 = s->x -1;
	}
}

void	indicate_direction2(t_struct *s, int l, int k)
{
	if (l == 3 && k == 1)
	{
		find_point_player_hg(s);
		s->y2 = s->y1;
		s->x2 = 0;
	}
	else if (l == 3)
	{
		find_point_player_bd(s);
		s->y2 = s->y -1;
		s->x2 = s->x1;
	}
	else if (l == 4 && k == 1)
	{
		find_point_player_hd(s);
		s->y2 = s->y1;
		s->x2 = s->x - 1;
	}
	else if (l == 4)
	{
		find_point_player_bg(s);
		s->y2 = s->y -1;
		s->x2 = s->x1;
	}
}
