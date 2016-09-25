/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajust_trankil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <atoupart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:57:32 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/25 15:57:35 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ajust_array(t_struct *s)
{
	int i;
	int h;

	h = 0;
	if (s->y > 0 && s->y <= 20)
		h = 15 - s->yp;
	else if (s->y > 20 && s->y <= 60)
		h = 20 - s->yp;
	else if (s->y > 60 && s->y <= 150)
		h = 40 - s->yp;
	i = 0;
	while (i++ < h)
		ft_putchar_fd('\n', 2);
}

void			trankil(int i)
{
	i = 0;
	while (i < 99999999)
		i++;
}

int				main(void)
{
	int			i;
	int			k;
	char		*str;
	t_struct	s;

	ft_bzero(&s, sizeof(t_struct));
	str = NULL;
	i = -1;
	k = 1;
	while (42)
	{
		trankil(i);
		i++;
		k *= -1;
		if (s.player == 0 || s.plateau == NULL)
			init_player_plateau(&s);
		else if (!thank_norm(&s, str))
			return (0);
		make_filler(&s, k, i);
		ajust_array(&s);
	}
	return (0);
}
