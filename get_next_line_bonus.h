/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:01:36 by anblanco          #+#    #+#             */
/*   Updated: 2024/05/02 14:42:30 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_free(char **str);
char	*get_next_line(int fd);
char	*concat_morsel(int fd, char *historic_buffer);
char	*get_lines(char *historic_buffer, int size);
char	*update_historic(char *historic_buffer);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int source, size_t len);
char	*ft_strdup(char *s1);

#endif