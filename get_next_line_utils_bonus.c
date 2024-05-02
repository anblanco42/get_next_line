/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anblanco <anblanco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:10:12 by anblanco          #+#    #+#             */
/*   Updated: 2024/05/02 14:39:38 by anblanco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size1;
	int		size2;
	int		i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size1 + size2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (++i < size1)
		str[i] = s1[i];
	i = -1;
	while (++i < size2)
		str[i + size1] = s2[i];
	str[i + size1] = '\0';
	return (ft_free(&s1), str);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int source, size_t len)
{
	size_t			i;
	unsigned int	len_s;
	char			*str;

	if (len == 0)
		return (NULL);
	len_s = (unsigned int)ft_strlen(s);
	if (source >= len_s)
		return (ft_strdup(""));
	if (source + len > len_s)
		len = len_s - source;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i + source];
	str[i] = '\0';
	return (str);
}
