/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:15:37 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/25 16:15:39 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			free_piece(t_struct *s)
{
	int i;

	i = 0;
	while (i < s->yp + 1)
	{
		ft_strdel(&s->piece[i]);
		i++;
	}
	free(s->piece);
}

void			free_all(t_struct *s)
{
	int i;

	i = 0;
	while (i < s->y + 1)
	{
		ft_strdel(&s->plateau[i]);
		i++;
	}
	free(s->plateau);
	free_piece(s);
}
