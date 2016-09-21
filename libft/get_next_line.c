/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:27:21 by atoupart          #+#    #+#             */
/*   Updated: 2016/05/04 18:54:20 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			thanks_norm(char **str, int fd, char **line)
{
	char		*ptr;
	int			len;

	len = 0;
	len = ft_strchr(str[fd], '\n') - str[fd];
	*line = ft_strsub(str[fd], 0, len);
	ptr = str[fd];
	str[fd] = ft_strdup(ft_strchr(str[fd], '\n') + 1);
	ft_strdel(&ptr);
}

static void		join_stk(char **str, char *stk, int ret)
{
	char *ptr;

	stk[ret] = '\0';
	ptr = *str;
	*str = ft_strjoin(*str, stk);
	ft_strdel(&ptr);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str[256];
	char		*stk;
	int			ret;

	ret = 0;
	if (fd < 0 || BUFF_SIZE <= 0 || !line || !(stk = ft_strnew(BUFF_SIZE)))
		return (-1);
	str[fd] = !str[fd] ? ft_strnew(0) : str[fd];
	while (!(ft_strchr(str[fd], '\n')) && (ret = read(fd, stk, BUFF_SIZE)) > 0)
		join_stk(&str[fd], stk, ret);
	ft_strdel(&stk);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !(ft_strchr(str[fd], '\n')))
	{
		*line = str[fd];
		str[fd] = NULL;
		return (((*line)[0] == '\0') ? 0 : 1);
	}
	thanks_norm(&str[fd], fd, line);
	return (1);
}
