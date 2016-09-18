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

int			test_ar_2(t_struct *s, int k, int j, int i)
{
	int		y1;
	int		x1;

	y1 = s->y1 - k + j;
	x1 = s->x1 - k + i;
	if (y1 > s->y - 1 || x1 > s->x - 1 || y1 < 0 || x1 < 0)
	{
		i++;
		return (0);
	}
	if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1))
		if (search(s, y1, x1))
			return (1);
	return (0);
}

int			test_around(t_struct *s)
{
	int		i;
	int		j;
	int		k;

	k = 1;
	while (k <= 3)
	{
		j = 0;
		while (s->y1 - k + j <= s->y1 + k)
		{
			i = 0;
			while (s->x1 - k + i <= s->x1 + k)
			{
				if (test_ar_2(s, k, j, i))
					return (1);
				else
					continue;
				i++;
			}
			j++;
		}
		k++;
	}
	return (0);
}

int			touch_op2(t_struct *s, int k, int j, int i)
{
	int		y1;
	int		x1;

	y1 = s->y1 - k + j;
	x1 = s->x1 - k + i;
	if (y1 > s->y - 1 || x1 > s->x - 1 || y1 < 0 || x1 < 0)
	{
		i++;
		return (0);
	}
	if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1)\
		&& touch_around(s, y1, x1))
		if (search(s, y1, x1))
			return (1);
	return (0);
}

int			touch_opponent(t_struct *s)
{
	int		i;
	int		j;
	int		k;

	k = 1;
	while (k <= 10)
	{
		j = 0;
		while (s->y1 - k + j <= s->y1 + k)
		{
			i = 0;
			while (s->x1 - k + i <= s->x1 + k)
			{
				if (touch_op2(s, k, j, i))
					return (1);
				else
					continue;
				i++;
			}
			j++;
		}
		k++;
	}
	return (0);
}
