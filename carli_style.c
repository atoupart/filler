/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carli_style.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:08:25 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/22 23:08:27 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			carli_style_bd(t_struct *s, int k)
{
	s->b = verif_rim_h(s);
	if ((s->w > s->h && !(s->a = verif_rim_g(s))) || (!s->a && s->b))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = s->y1;
		s->x2 = 0;
		s->v = 1;
		return (0);
	}
	else if ((s->a && s->b && k > 0) || (s->a && s->blok == 2 && (s->v = 2)))
		return (find_point_opponent_gb(s) + find_point_player_gb(s));
	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = 0;
		s->x2 = s->x1;
		s->v = 2;
		return (0);
	}
	else if ((s->a && s->b && k < 0) || (!s->b && s->blok == 1 && (s->v = 0)))
		return (find_point_opponent_hd(s) + find_point_player_hd(s));
	return (0);
}

int			carli_style_bg(t_struct *s, int k)
{
	s->b = verif_rim_h(s);
	if ((s->w > s->h && !(s->a = verif_rim_d(s))) || (!s->a && s->b))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = s->y1;
		s->x2 = s->x - 1;
		s->v = 1;
		return (0);
	}
	else if ((s->a && s->b && k > 0) || (s->a && s->blok == 2 && (s->v = 0)))
		return (find_point_player_db(s) + find_point_opponent_db(s));
	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = 0;
		s->x2 = s->x1;
		s->v = 2;
		return (0);
	}
	else if ((s->a && s->b && k < 0) || (!s->b && s->blok == 1 && (s->v = 0)))
		return (find_point_player_hg(s) + find_point_opponent_hg(s));
	return (0);
}

int			carli_style_hg(t_struct *s, int k)
{
	s->b = verif_rim_b(s);
	if ((s->w > s->h && !(s->a = verif_rim_d(s))) || (!s->a && s->b))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = s->y1;
		s->x2 = s->x - 1;
		s->v = 1;
		return (0);
	}
	else if ((s->a && s->b && k > 0) || (!s->b && s->blok == 2 && (s->v = 0)))
		return (find_point_player_dh(s) + find_point_opponent_dh(s));
	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = s->y - 1;
		s->x2 = s->x1;
		s->v = 2;
		return (0);
	}
	else if ((s->a && s->b && k < 0) || (!s->b && s->blok == 1 && (s->v = 0)))
		return (find_point_player_bg(s) + find_point_opponent_bg(s));
	return (0);
}

int			carli_style_hd(t_struct *s, int k)
{
	s->b = verif_rim_b(s);
	if ((s->w > s->h && !(s->a = verif_rim_g(s))) || (!s->a && s->b))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = s->y1;
		s->x2 = 0;
		s->v = 1;
		return (0);
	}
	else if ((s->a && s->b && k > 0) || (!s->b && s->blok == 2 && (s->v = 0)))
		return (find_point_player_gh(s) + find_point_opponent_gh(s));
	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = s->y - 1;
		s->x2 = s->x1;
		s->v = 2;
		return (0);
	}
	else if ((s->a && s->b && k < 0) || (!s->b && s->blok == 1 && (s->v = 0)))
		return (find_point_player_bd(s) + find_point_opponent_bd(s));
	return (0);
}
