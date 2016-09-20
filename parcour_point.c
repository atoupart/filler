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
		return (1);
	else if (test_around(s))
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
