/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point_opponent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:35:07 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/23 02:35:08 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				find_point_opponent_hg(t_struct *s)
{
	s->y2 = 0;
	while (s->y2 < s->y)
	{
		s->x2 = 0;
		while (s->x2 < s->x)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->x2++;
		}
		s->y2++;
	}
	return (0);
}

int				find_point_opponent_bd(t_struct *s)
{
	s->y2 = s->y - 1;
	while (s->y2 >= 0)
	{
		s->x2 = s->x - 1;
		while (s->x2 >= 0)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->x2--;
		}
		s->y2--;
	}
	return (0);
}

int				find_point_opponent_hd(t_struct *s)
{
	s->y2 = 0;
	while (s->y2 < s->y)
	{
		s->x2 = s->x -1;
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

int				find_point_opponent_bg(t_struct *s)
{
	s->y2 = s->y - 1;
	while (s->y2 >= 0)
	{
		s->x2 = 0;
		while (s->x2 < s->x)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->x2++;
		}
		s->y2--;
	}
	return (0);
}