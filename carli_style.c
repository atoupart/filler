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

void			carli_style_bd(t_struct *s, int k)
{
	if (s->w > s->h && verif_rim_g(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = 0;			
	}
	else if (verif_rim_g(s) != 0 && k < 0)
	{
		find_point_player_gh(s);
		find_point_opponent_hg(s);
	}
	if (s->h > s->w && verif_rim_h(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = 0;
			s->x2 = s->x1;
	}
	else if (verif_rim_h(s) != 0 && k > 0)
	{
		find_point_player_hg(s);
		find_point_opponent_bd(s);			
	}
}

void			carli_style_bg(t_struct *s, int k)
{
	if (k < 0 && verif_rim_d(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = s->x - 1;			
	}
	else if (k < 0)
	{
		find_point_player_dh(s);
		find_point_opponent_hd(s);
	}
	if (k > 0 && verif_rim_h(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = 0;
			s->x2 = s->x1;
	}
	else if (k > 0)
	{
		find_point_player_hd(s);
		find_point_opponent_bg(s);			
	}
}

void			carli_style_hg(t_struct *s, int k)
{
	if (k < 0 && verif_rim_b(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y - 1;
			s->x2 = s->x1;			
	}
	else if (k < 0)
	{
		find_point_player_db(s);
		find_point_opponent_bd(s);
	}
	if (k > 0 && verif_rim_d(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = s->x - 1;
	}
	else if (k > 0)
	{
		find_point_player_bd(s);
		find_point_opponent_hg(s);			
	}
}

void			carli_style_hd(t_struct *s, int k)
{
	if (k < 0 && verif_rim_g(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = 0;			
	}
	else if (k < 0)
	{
		find_point_player_gb(s);
		find_point_opponent_bg(s);
	}
	if (k > 0 && verif_rim_b(s) == 0)
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y - 1;
			s->x2 = s->x1;
	}
	else if (k > 0)
	{
		find_point_player_bg(s);
		find_point_opponent_hd(s);
	}
}
