/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point_player2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 00:44:04 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/23 00:44:05 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int				find_point_player_gh(t_struct *s)
{
	s->x1 = 0;
	while (s->x1 < s->x)
	{
		s->y1 = 0;
		while (s->y1 < s->y)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->y1++;
		}
		s->x1++;
	}
	return (0);
}

int				find_point_player_gb(t_struct *s)
{
	s->x1 = 0;
	while (s->x1 < s->x)
	{
		s->y1 = s->y -1;
		while (s->y1 >= 0)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->y1--;
		}
		s->x1++;
	}
	return (0);
}
int				find_point_player_dh(t_struct *s)
{
	s->x1 = s->x - 1;
	while (s->x1 >= 0)
	{
		s->y1 = 0;
		while (s->y1 < s->y)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->y1++;
		}
		s->x1--;
	}
	return (0);
}
int				find_point_player_db(t_struct *s)
{
	s->x1 = s->x - 1;
	while (s->x1 < s->x)
	{
		s->y1 = s->y -1;
		while (s->y1 >= 0)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->y1--;
		}
		s->x1--;
	}
	return (0);
}
