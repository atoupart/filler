/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 14:38:36 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/18 14:38:38 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(char *s)
{
	int		len;

	len = 0;
	if (s)
	{
		if (s[0] == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
		{
			len += 2;
			s += 2;
			while (*s && (ft_isdigit(*s) || ft_strchr("abcdefABCDEF", (int)*s)))
			{
				len++;
				s++;
			}
		}
	}
	return (len);
}
