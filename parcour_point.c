/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcour_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 11:20:51 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/13 11:20:53 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			parcour(t_struct *s, int k)
{
	if (touch_opponent(s))
	{
		if (s->v == 1)
			s->blok = 1;
		else if (s->v == 2)
			s->blok = 2;
		return (1);
	}
	else if ((s->blok = 1) == 1 && test_around(s))
		return (1);
	else if (k > 0 && parcour_point_hg(s))
		return (1);
	else if (parcour_point_bd(s))
		return (1);
	else if (parcour_point_hd(s))
		return (1);
	return (0);
}

int			parcour_point_hg(t_struct *s)
{
	int		y1;
	int		x1;

	y1 = 0;
	while (y1 < s->y)
	{
		x1 = 0;
		while (x1 < s->x)
		{
			if (s->plateau[y1][x1] == s->l_player &&\
				look_around(s, y1, x1)\
			&& touch_around(s, y1, x1))
				if (search(s, y1, x1))
					return (1);
			x1++;
		}
		y1++;
	}
	return (0);
}

int			parcour_point_bd(t_struct *s)
{
	int		y1;
	int		x1;

	y1 = s->y - 1;
	while (y1 >= 0)
	{
		x1 = s->x - 1;
		while (x1 >= 0)
		{
			if (s->plateau[y1][x1] == s->l_player &&\
				look_around(s, y1, x1)\
				&& touch_around(s, y1, x1))
				if (search(s, y1, x1))
					return (1);
			x1--;
		}
		y1--;
	}
	return (0);
}

int			parcour_point_hd(t_struct *s)
{
	int		y1;
	int		x1;

	y1 = 0;
	while (y1 < s->y)
	{
		x1 = s->x - 1;
		while (x1 >= 0)
		{
			if (s->plateau[y1][x1] == s->l_player &&\
				look_around(s, y1, x1))
				if (search(s, y1, x1))
					return (1);
			x1--;
		}
		y1++;
	}
	return (0);
}

int			look_around(t_struct *s, int y1, int x1)
{
	int k;

	k = 0;
	if (y1 - 1 >= 0)
		if (s->plateau[y1 - 1][x1] == '.' ||\
			s->plateau[y1 - 1][x1 + 1] == '.')
			k++;
	if (x1 - 1 >= 0)
		if (s->plateau[y1][x1 - 1] == '.' ||\
			s->plateau[y1 + 1][x1 - 1] == '.')
			k++;
	if (y1 - 1 >= 0 && x1 - 1 >= 0 && \
		s->plateau[y1 - 1][x1 - 1] == '.')
		k++;
	if (s->plateau[y1][x1 + 1] == '.' ||\
		s->plateau[y1 + 1][x1] == '.')
		k++;
	if (s->plateau[y1 + 1][x1 + 1] == '.')
		k++;
	return (k);
}
