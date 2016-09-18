/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 00:45:45 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/13 00:45:49 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		search(t_struct *s, int y1, int x1)
{
	if (s->res_orient < s->res_orient2)
	{
		if (search_position2(s, y1, x1) == 1)
		{
			print_piece(s);
			return (1);
		}
		else
			return (0);
	}
	else
	{
		if (search_position(s, y1, x1) == 1)
		{
			print_piece(s);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
