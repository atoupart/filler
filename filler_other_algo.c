/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_other_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 03:55:05 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/26 03:55:06 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			make_filler(t_struct *s, int k, int i)
{
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	determine_plateau(s);
	determine_piece(s, str, tmp);
	determine_y1_x1(s, k, i);
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
