/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_rim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:30:56 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/23 02:30:57 by atoupart         ###   ########.fr       */
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
	ret = 0;
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
