/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 00:45:45 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/13 00:45:49 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			search(t_struct *s, int y1, int x1)
{
	if (s->res_orient < s->res_orient2)
	{
		if (search_position2(s, y1, x1) == 1)
		{
			print_piece(s);
			return (1);
		}
		else
			return (0);
	}
	else
	{
		if (search_position(s, y1, x1) == 1)
		{
			print_piece(s);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int			touch_around_2(t_struct *s, int y1, int x1)
{
	int			k;

	k = 0;
	if (y1 - 1 >= 0)
	{
		if (s->plateau[y1 - 1][x1] == s->l_opponent ||\
			s->plateau[y1 - 1][x1] == s->l_opponent2)
			k++;
		if (s->plateau[y1 - 1][x1 + 1] == s->l_opponent ||\
			s->plateau[y1 - 1][x1 + 1] == s->l_opponent2)
			k++;
	}
	if (x1 - 1 >= 0)
	{
		if (s->plateau[y1 + 1][x1 - 1] == s->l_opponent ||\
			s->plateau[y1 + 1][x1 - 1] == s->l_opponent2)
			k++;
		if (s->plateau[y1][x1 - 1] == s->l_opponent ||\
			s->plateau[y1][x1 - 1] == s->l_opponent2)
			k++;
	}
	return (k);
}

int			touch_around(t_struct *s, int y1, int x1)
{
	int		k;

	k = touch_around_2(s, y1, x1);
	if (y1 - 1 >= 0 && x1 - 1 >= 0 && (s->plateau[y1 - 1][x1 - 1]\
		== s->l_opponent || s->plateau[y1 - 1][x1 - 1] == s->l_opponent2))
		k++;
	if (s->plateau[y1][x1 + 1] == s->l_opponent ||\
		s->plateau[y1][x1 + 1] == s->l_opponent2)
		k++;
	if (s->plateau[y1 + 1][x1] == s->l_opponent ||\
		s->plateau[y1 + 1][x1] == s->l_opponent2)
		k++;
	if (s->plateau[y1 + 1][x1 + 1] == s->l_opponent ||\
		s->plateau[y1 + 1][x1 + 1] == s->l_opponent2)
		k++;
	return (k);
}

int			calcul_o(t_struct *s, int y2, int x2)
{
	int		result;

	if (y2 < 0 || x2 < 0)
		return (-1);
	if (s->plateau[y2][x2] != s->l_opponent \
		&& s->plateau[y2][x2] != s->l_opponent2)
		return (-1);
	result = ((s->x1 - x2) * (s->x1 - x2)) + ((s->y1 - y2) * (s->y1 - y2));
	return (result);
}

int			calcul_p(t_struct *s, int y1, int x1)
{
	int		result;

	if (y1 < 0 || x1 < 0)
		return (-1);
	if (s->plateau[y1][x1] != s->l_player)
		return (-1);
	result = ((x1 - s->x2) * (x1 - s->x2)) + ((y1 - s->y2) * (y1 - s->y2));
	return (result);
}
