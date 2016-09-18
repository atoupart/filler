/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 11:08:29 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/08 11:08:36 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			precise_opponent(t_struct *s)
{
	int		res;

	s->res_o = calcul_o(s, s->y2, s->x2);
	if ((res = calcul_o(s, s->y2 + 1, s->x2)) < s->res_o && res >= 0)
		s->y2++;
	else if ((res = calcul_o(s, s->y2 - 1, s->x2)) < s->res_o && res >= 0)
		s->y2--;
	else if ((res = calcul_o(s, s->y2, s->x2 + 1)) < s->res_o && res >= 0)
		s->x2++;
	else if ((res = calcul_o(s, s->y2, s->x2 - 1)) < s->res_o && res >= 0)
		s->x2--;
	else
		return (1);
	return (0);
}

int			precise_opponent_diag(t_struct *s)
{
	int		res;

	if ((res = calcul_o(s, s->y2 + 1, s->x2 + 1)) < s->res_o && res >= 0)
	{
		s->y2++;
		s->x2++;
	}
	else if ((res = calcul_o(s, s->y2 + 1, s->x2 - 1)) < s->res_o && res >= 0)
	{
		s->y2++;
		s->x2--;
	}
	else if ((res = calcul_o(s, s->y2 - 1, s->x2 + 1)) < s->res_o && res >= 0)
	{
		s->y2--;
		s->x2++;
	}
	else if ((res = calcul_o(s, s->y2 - 1, s->x2 - 1)) < s->res_o && res >= 0)
	{
		s->y2--;
		s->x2--;
	}
	else
		return (1);
	return (0);
}

int			precise_player(t_struct *s)
{
	int		res;

	s->res_p = calcul_p(s, s->y1, s->x1);
	if ((res = calcul_p(s, s->y1 + 1, s->x1)) < s->res_p && res >= 0)
		s->y1++;
	else if ((res = calcul_p(s, s->y1 - 1, s->x1)) < s->res_p && res >= 0)
		s->y1--;
	else if ((res = calcul_p(s, s->y1, s->x1 + 1)) < s->res_p && res >= 0)
		s->x1++;
	else if ((res = calcul_p(s, s->y1, s->x1 - 1)) < s->res_p && res >= 0)
		s->x1--;
	else
		return (1);
	return (0);
}

int			precise_player_diag(t_struct *s)
{
	int		res;

	if ((res = calcul_p(s, s->y1 + 1, s->x1 + 1)) < s->res_p && res >= 0)
	{
		s->y1++;
		s->x1++;
	}
	else if ((res = calcul_p(s, s->y1 + 1, s->x1 - 1)) < s->res_p && res >= 0)
	{
		s->y1++;
		s->x1--;
	}
	else if ((res = calcul_p(s, s->y1 - 1, s->x1 + 1)) < s->res_p && res >= 0)
	{
		s->y1--;
		s->x1++;
	}
	else if ((res = calcul_p(s, s->y1 - 1, s->x1 - 1)) < s->res_p && res >= 0)
	{
		s->y1--;
		s->x1--;
	}
	else
		return (1);
	return (0);
}

void		recursive_find_best_points(t_struct *s)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = precise_opponent(s);
	b = precise_opponent_diag(s);
	c = precise_player(s);
	d = precise_player_diag(s);
	if (a == 1 && b == 1 && c == 1 && d == 1)
		return ;
	recursive_find_best_points(s);
}
