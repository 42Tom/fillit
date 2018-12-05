/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:15 by trabut            #+#    #+#             */
/*   Updated: 2018/12/05 13:55:19 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetNextLine/get_next_line.h"
#include "GetNextLine/libft/libft.a"

char	**test_read(int fd)
{
	char	**tab;
	int		i;
	int		ret;

	i = 0;
	while (i <= 4 && ret)
		get_next_line(fd, &tab[i++]);
	if (i == 5)
		return (0);
	while (i >= 0)
	{
		if (ft_strlen(tab[i--]) != 4)
			return (0);
	}
	return (tab);
}

int		test_tetri(char **tab)
{
	int k;
	int i;
	int j;
	int l;

	l = 0;
	j = 0;
	k = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i++] == '#')
			{
				l++;
				if (tab[j][i + 1] != '#' || tab[j + 1][i] != '#' ||
					tab[j - 1][i])
					k++;
			}
		}
		j++;
	}
	if (k == l == 4)
		return (1);
}
