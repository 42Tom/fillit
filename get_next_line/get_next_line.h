/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:27:06 by lbonnete          #+#    #+#             */
/*   Updated: 2018/12/07 11:36:32 by lbonnete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/types.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"

# define MALLCHECK(x) if(!(x))return (-1);

int		get_next_line(const int fd, char **line);

#endif
