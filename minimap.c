/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:51:11 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/22 17:51:13 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int				find_point_player_hd(t_struct *s)
{
	s->y1 = 0;
	while (s->y1 < s->y)
	{
		s->x1 = s->x -1;
		while (s->x1 >= 0)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->x1--;
		}
		s->y1++;
	}
	return (0);
}

int				find_point_opponent_hd(t_struct *s)
{
	s->y2 = 0;
	while (s->y2 < s->y)
	{
		s->x2 = s->x - 1;
		while (s->x2 >= 0)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->x2--;
		}
		s->y2++;
	}
	return (0);
}

int			pose_x_by_y(t_struct *s)
{
	int y1;
	int x1;
	x1 = 0;
	while (x1 < s->x)
	{
		y1 = 0;
		while (y1 < s->y)
		{
			if (s->plateau[y1][x1] == s->l_player && search(s, y1, x1))
				return (1);
			y1++;
		}
		x1++;
	}
	return (0);
}

void		minimap(t_struct *s, int k, int i)
{
	k = -1;
	// i++;
	if (i == 0)
		determine_rim(s);
	s->rim = verif_rim(s);
	// if (s->rim == 0)
	// {
	// 	s->x1 = s->xinit;
	// 	s->y1 = s->yinit;
	// 	s->x2 = s->xrim;
	// 	s->y2 = s->yrim;
	// }
	// if (find_point_player_hg(s) && s->y1 > s->y / 4)
	// {
	// 	s->y2 = s->y / 4;
	// 	s->x2 = s->x1;
	// }
	// else if (s->x1 > 0)
	// {
	// 	s->y2 = s->y1;
	// 	s->x2 = 0;

	// }
	// else
	// {
		// find_point_opponent_hd(s);

	// }




	// if (s->rim == 0)
	// {
	// 	find_point_player_hd(s);
	// 	s->y2 = 0;
	// 	s->x2 = s->x1;
	// }
	// else
	// {
	// 	find_point_player_hg(s);
		find_point_opponent_hg(s);

	// }

	recursive_find_best_points(s);
	orientate_piece(s);

	if (parcour_point_hd(s) == 0)
	{
		s->y1 = 0;
		s->x1 = 0;
		print_piece(s);
	}
	

	// fprintf(stderr, "s->y1 = %d\ns->x1 = %d\n", s->y1, s->x1);
	// fprintf(stderr, "s->y2 = %d\ns->x2 = %d\n", s->y2, s->x2);
	// fprintf(stderr, "test-search\n");

	// if (search(s, s->y1, s->x1) == 0)
	// {
	// 	fprintf(stderr, "test-opponent\n");

	// 	if (touch_opponent(s) == 0)
	// 	{
				
	// 		fprintf(stderr, "test-around\n");

	// 		if (test_around(s) == 0)
	// 		{
	// 			fprintf(stderr, "test-pose_x_y\n");

	// 			if (pose_x_by_y(s) == 0)
	// 			{
	// 				fprintf(stderr, "end of possibilities\n");

	// 				s->y1 = 0;
	// 				s->x1 = 0;
	// 				print_piece(s);
	// 			}
	// 		}

	// 	}
	// }
}
