/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psancio- <psancio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:59:36 by psancio-          #+#    #+#             */
/*   Updated: 2025/05/22 09:48:58 by psancio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	shift(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fs;
	int		i;
	int		j;

	fs = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fs)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		fs[i] = s1[i];
		i++;
	}
	while (j < BUFFER_SIZE && s2[j] && s2[j] != '\n')
	{
		fs[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		fs[i + j] = s2[j];
	j += (s2[j] == '\n');
	fs[i + j] = '\0';
	return (free(s1), fs);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

int	ft_strchr(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
