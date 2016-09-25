/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 19:59:48 by atoupart          #+#    #+#             */
/*   Updated: 2016/08/22 19:59:59 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			determine_position(t_struct *s)
{
	find_point_player_hg(s);
	find_point_opponent_hg(s);
	s->yinit = s->y1;
	s->xinit = s->x1;
	if (s->y1 < s->y2)
	{
		if (s->x1 < s->x2)
			s->position = 1;
		else
			s->position = 2;
	}
	else
	{
		if (s->x1 < s->x2)
			s->position = 3;
		else
			s->position = 4;
	}
}

void			determine_carli(t_struct *s, int i, int k)
{
	if (i == 0)
		determine_position(s);
	if (s->position == 1)
		carli_style_hg(s, k);
	else if (s->position == 2)
		carli_style_hd(s, k);
	else if (s->position == 3)
		carli_style_bg(s, k);
	else if (s->position == 4)
		carli_style_bd(s, k);
	recursive_find_best_points(s);
	orientate_piece(s);
}

void			make_filler(t_struct *s, int k, int i)
{
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	determine_plateau(s);
	determine_piece(s, str, tmp);
	s->h = 0;
	s->w = 0;
	tcheck_piece_height(s);
	tcheck_piece_width(s);
	determine_carli(s, i, k);
	if (search(s, s->y1, s->x1) == 0)
	{
		if (parcour(s, k) == 0)
		{
			s->y1 = 0;
			s->x1 = 0;
			print_piece(s);
		}
	}
}

int				thank_norm(t_struct *s, char *str)
{
	s->ret = get_next_line(0, &str);
	if (s->ret == 0)
	{
		ft_strdel(&str);
		free_all(s);
		return (0);
	}
	free_piece(s);
	ft_strdel(&str);
	return (1);
}
