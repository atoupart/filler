/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_parcour_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:31:06 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/20 16:31:57 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			touch_op2(t_struct *s, int k, int j, int i)
{
	int		y1;
	int		x1;

	y1 = s->y1 - k + j;
	x1 = s->x1 - k + i;
	if (y1 > s->y - 1 || x1 > s->x - 1 || y1 < 0 || x1 < 0)
		return (2);
	if (s->plateau[y1][x1] == s->l_player && look_around(s, y1, x1)\
		&& touch_around(s, y1, x1))
		if (search(s, y1, x1))
			return (1);
	return (0);
}

int			test_ar_2(t_struct *s, int k, int j, int i)
{
	int		y1;
	int		x1;

	y1 = s->y1 - k + j;
	x1 = s->x1 - k + i;
	if (y1 > s->y - 1 || x1 > s->x - 1 || y1 < 0 || x1 < 0)
		return (2);
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
				if ((s->ver = test_ar_2(s, k, j, i)) == 1)
					return (1);
				else if (s->ver == 2 && i++)
					continue;
				i++;
			}
			j++;
		}
		k++;
	}
	return (0);
}

int			touch_opponent(t_struct *s)
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
				if ((s->ver = touch_op2(s, k, j, i)) == 1)
					return (1);
				else if (s->ver == 2 && i++)
					continue;
				i++;
			}
			j++;
		}
		k++;
	}
	return (0);
}

int			inside_verif_ligne_piece2(t_struct *s, int y1, int x1)
{
	s->xx = x1 + s->ii + s->diff + s->i - s->diff_l - s->ecart;
	s->ppx = s->ap + s->ii;
	if (s->yy < 0 || s->xx < 0 || !s->plateau[s->yy][s->xx] ||\
		!s->piece[s->ppy][s->ppx])
		return (0);
	while (s->piece[s->ppy][s->ppx] != '*')
	{
		s->ii++;
		s->xx = x1 + s->ii + s->diff + s->i - s->ecart - s->diff_l;
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
