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
		// fprintf(stderr, "\033[97m >>IN SEARCH_POSITION 2 with plateau[%d][%d]\n", y1, x1);
		if (search_position2(s, y1, x1) == 1)
		{
			print_piece(s);
			return (1);
		}
		else
		{
			// fprintf(stderr, "\033[97m-->position not found with search2 plateau[%d][%d]<--\n", y1, x1);
			return (0);
		}
	}
	else
	{
		// fprintf(stderr, "\033[97m >>IN SEARCH_POSITION with plateau[%d][%d]\n", y1, x1);
		if (search_position(s, y1 , x1) == 1)
		{
			print_piece(s);
			return (1);
		}
		else
		{
			// fprintf(stderr, "\033[96m-->position not found with search plateau[%d][%d]--\n", y1, x1);
			return (0);
		}
	}
	return (0);
}

