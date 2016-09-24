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

	s->a = verif_rim_g(s);
	s->b = verif_rim_h(s);
	fprintf(stderr, "s->a = %d\ns->b = %d\n", s->a, s->b);

	int e = 0;
	if ((s->w > s->h && !s->a) || (!s->a && s->b))
	{	
		e++;
		fprintf(stderr, "passe 1\n");
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = 0;			
	}
	else if (s->a && s->b && k > 0)
	{
		e++;
		fprintf(stderr, "passe 2\n");

		find_point_player_gh(s);
		find_point_opponent_hg(s);
	}


	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
		e++;
		fprintf(stderr, "passe 3\n");
		s->y1 = s->yinit;
		s->x1 = s->xinit;
		s->y2 = 0;
		s->x2 = s->x1;
	}
	else if (s->a && s->b && k < 0)
	{
		e++;
		fprintf(stderr, "passe 4\n");

		find_point_player_hg(s);
		find_point_opponent_hg(s);			
	}
	if (e == 0)
	fprintf(stderr, "CARLY STYLE BD FAIL\n");


}

void			carli_style_bg(t_struct *s, int k)
{
	s->a = verif_rim_d(s);
	s->b = verif_rim_h(s);
	if ((s->w > s->h && !s->a) || (!s->a && s->b))
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = s->x - 1;			
	}
	else if (s->a && s->b && k > 0)
	{
		find_point_player_dh(s);
		find_point_opponent_hd(s);
	}
	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = 0;
			s->x2 = s->x1;
	}
	else if (s->a && s->b && k < 0)
	{
		find_point_player_hd(s);
		find_point_opponent_bg(s);			
	}
}

void			carli_style_hg(t_struct *s, int k)
{
	s->a = verif_rim_b(s);
	s->b = verif_rim_d(s);
	if ((s->w > s->h && !s->a) || (!s->a && s->b))
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y - 1;
			s->x2 = s->x1;			
	}
	else if (s->a && s->b && k > 0)
	{
		find_point_player_db(s);
		find_point_opponent_bd(s);
	}
	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = s->x - 1;
	}
	else if (s->a && s->b && k < 0)
	{
		find_point_player_bd(s);
		find_point_opponent_hg(s);			
	}
}

void			carli_style_hd(t_struct *s, int k)
{
	s->a = verif_rim_g(s);
	s->b = verif_rim_b(s);
	if ((s->w > s->h && !s->a) || (!s->a && s->b))
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y1;
			s->x2 = 0;			
	}
	else if (s->a && s->b && k > 0)
	{
		find_point_player_gb(s);
		find_point_opponent_bg(s);
	}
	if ((s->h >= s->w && !s->b) || (!s->b && s->a))
	{
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = s->y - 1;
			s->x2 = s->x1;
	}
	else if (s->a && s->b && k < 0)
	{
		find_point_player_bg(s);
		find_point_opponent_hd(s);
	}
}
