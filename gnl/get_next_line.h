/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 13:39:46 by lbisscho       #+#    #+#                */
/*   Updated: 2019/12/27 12:37:34 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(const char *s1);
char	*gnl_strndup(char *str, size_t end);

#endif
