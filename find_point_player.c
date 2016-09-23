/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:43:49 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/23 00:43:51 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				find_point_player_hg(t_struct *s)
{
	s->y1 = 0;
	while (s->y1 < s->y)
	{
		s->x1 = 0;
		while (s->x1 < s->x)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->x1++;
		}
		s->y1++;
	}
	return (0);
}

int				find_point_player_bg(t_struct *s)
{
	s->y1 = s->y -1;
	while (s->y1 >= 0)
	{
		s->x1 = 0;
		while (s->x1 < s->x)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->x1++;
		}
		s->y1--;
	}
	return (0);
}

int				find_point_player_hd(t_struct *s)
{
	s->y1 = 0;
	while (s->y1 < s->y)
	{
		s->x1 = s->x - 1;
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

int				find_point_player_bd(t_struct *s)
{
	s->y1 = s->y - 1;
	while (s->y1 >= 0)
	{
		s->x1 = s->x - 1;
		while (s->x1 >= 0)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->x1--;
		}
		s->y1--;
	}
	return (0);
}
