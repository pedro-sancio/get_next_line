/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psancio- <psancio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:59:31 by psancio-          #+#    #+#             */
/*   Updated: 2025/05/22 10:15:45 by psancio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = ft_strjoin(line, buffer);
	while (!ft_strchr(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || buffer[0] == '\0')
		{
			free(line);
			shift(buffer);
			return (NULL);
		}
		if (!bytes_read)
			break ;
		if (bytes_read < BUFFER_SIZE)
			buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	shift(buffer);
	return (line);
}
// #include <fcntl.h>   // open
// #include <unistd.h>  // close
// #include <stdio.h>   // printf
// int main(void)
// // {
// //     int fd = open("teste.txt", O_RDONLY);
// //     char *linha;

// // 	while ((linha = get_next_line(fd)))
// //     {
// //         printf("%s", linha);
// //         free(linha);
// //     }

// //     close(fd);
// //     return 0;
// // }
