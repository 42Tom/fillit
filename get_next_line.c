/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:56:45 by lbonnete          #+#    #+#             */
/*   Updated: 2018/12/07 11:42:52 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		read_and_fill(int fd, char **str)
{
	char	buff[BUFF_SIZE + 1];
	char	*tp1;
	char	*tp2;
	int		ret;

	if (!(ret = read(fd, buff, BUFF_SIZE)))
		return (ret);
	else
	{
		buff[ret] = 0;
		MALLCHECK(tp1 = ft_strdup(*str));
		MALLCHECK(tp2 = ft_strdup(buff));
		ft_strdel(str);
		MALLCHECK(*str = ft_strjoin(tp1, tp2));
		ft_strdel(&tp1);
		ft_strdel(&tp2);
	}
	return (ret);
}

static	char	*ft_strclrcpy(char **str)
{
	int		n;
	char	*tmp;
	char	*ret;

	n = 0;
	if (!(tmp = ft_strdup(*str)))
		return (0);
	n = ft_count_letters(tmp, '\n');
	if (!(ret = (char *)malloc(n + 1)))
		return (0);
	ft_strncpy(ret, tmp, n);
	ret[n] = 0;
	ft_strdel(&tmp);
	if (!(tmp = (ft_strdup(*str + n + 1))))
		return (0);
	ft_strdel(str);
	*str = tmp;
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static	char	*str[OPEN_MAX];
	int				ret;

	if (line == 0 || BUFF_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (-1);
	while (!(ft_strchr(str[fd], '\n')))
	{
		if ((ret = read_and_fill(fd, &str[fd])) == -1)
			return (-1);
		if (ret == 0)
		{
			if (str[fd][0] == 0)
				return (0);
			MALLCHECK(*line = ft_strdup(str[fd]));
			str[fd][0] = 0;
			return (1);
		}
	}
	MALLCHECK(*line = ft_strclrcpy(&str[fd]));
	return (1);
}
