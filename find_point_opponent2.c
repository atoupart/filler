/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_point_opponent2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 10:13:37 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/25 10:13:44 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				find_point_opponent_gh(t_struct *s)
{
	s->x2 = 0;
	while (s->x2 < s->x)
	{
		s->y2 = 0;
		while (s->y2 < s->y)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->y2++;
		}
		s->x2++;
	}
	return (0);
}

int				find_point_opponent_gb(t_struct *s)
{
	s->x2 = 0;
	while (s->x2 < s->x)
	{
		s->y2 = s->y - 1;
		while (s->y2 >= 0)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->y2--;
		}
		s->x2++;
	}
	return (0);
}

int				find_point_opponent_dh(t_struct *s)
{
	s->x2 = s->x - 1;
	while (s->x2 >= 0)
	{
		s->y2 = 0;
		while (s->y2 < s->y)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->y2++;
		}
		s->x2--;
	}
	return (0);
}

int				find_point_opponent_db(t_struct *s)
{
	s->x2 = s->x - 1;
	while (s->x2 >= 0)
	{
		s->y2 = s->y - 1;
		while (s->y2 >= 0)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->y2--;
		}
		s->x2--;
	}
	return (0);
}
