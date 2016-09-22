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

int			verif_rim_h(t_struct *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < s->x)
	{
		if (s->plateau[0][i] == s->l_player)
			ret = 1;
		i++;
	}
	return (ret);
}

int			verif_rim_b(t_struct *s)
{
	int i;
	int ret;

	i = 0;
	while (i < s->x)
	{
		if (s->plateau[s->y - 1][i] == s->l_player)
			ret = 1;
		i++;
	}
	return (ret);
}

int			verif_rim_g(t_struct *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < s->y)
	{
		if (s->plateau[i][0] == s->l_player)
			ret = 1;
		i++;
	}
	return (ret);
}

int			verif_rim_d(t_struct *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < s->y)
	{
		if (s->plateau[i][s->x - 1] == s->l_player)
			ret = 1;
		i++;
	}
	return (ret);
}
void			carli_style(t_struct *s, int k)
{
	fprintf(stderr, "k = %d\n", k);
	if (k < 0)
	{
		// if (verif_rim_b(s) == 0)
		// {
		// 	find_point_player_bd(s);
		// 	s->y2 = s->y - 1;
		// 	s->x2 = s->x / 2;			
		// 	fprintf(stderr, "\033[94mverif_rim_b = 0 donc\ns->y1 = %d\ns->x1 = %d\ns->y2 = %d\ns->x2 = %d", s->y1, s->x1, s->y2, s->x2);
		// }
		if (verif_rim_g(s) == 0)
		{

			// find_point_player_bg(s);

			s->y1 = s->yinit;
			s->x1 = s->xinit;

			s->y2 = s->y1;
			s->x2 = 0;			
			fprintf(stderr, "\033[93mverif_rim_g = 0 donc\ns->y1 = %d\ns->x1 = %d\ns->y2 = %d\ns->x2 = %d", s->y1, s->x1, s->y2, s->x2);
		}
		else
		{
			find_point_player_hg(s);
			find_point_opponent_hg(s);
			fprintf(stderr, "\033[95mall aquis donc\ns->y1 = %d\ns->x1 = %d\ns->y2 = %d\ns->x2 = %d", s->y1, s->x1, s->y2, s->x2);
		}


	}
	else
	{
		// if (verif_rim_d(s) == 0)
		// {
		// 	find_point_player_hd(s);
		// 	s->y2 = s->y / 2;
		// 	s->x2 = s->x - 1;
		// 	fprintf(stderr, "\033[92mverif_rim_d = 0 donc\ns->y1 = %d\ns->x1 = %d\ns->y2 = %d\ns->x2 = %d", s->y1, s->x1, s->y2, s->x2);


		// }
		if (verif_rim_h(s) == 0)
		{	
			// find_point_player_hg(s);
			s->y1 = s->yinit;
			s->x1 = s->xinit;
			s->y2 = 0;
			s->x2 = s->x1;
			fprintf(stderr, "\033[91mverif_rim_h = 0 donc\ns->y1 = %d\ns->x1 = %d\ns->y2 = %d\ns->x2 = %d", s->y1, s->x1, s->y2, s->x2);


		}
		else
		{
			find_point_player_bd(s);
			find_point_opponent_bd(s);			
			fprintf(stderr, "\033[95mall aquis donc\ns->y1 = %d\ns->x1 = %d\ns->y2 = %d\ns->x2 = %d", s->y1, s->x1, s->y2, s->x2);

		}
	}
}















































