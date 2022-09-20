/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:44:54 by gusalves          #+#    #+#             */
/*   Updated: 2021/12/07 00:55:18 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*line_adjustment(char **backup_buffer)
{
	size_t	i;
	char	*str;
	char	*aux;

	i = 0;
	while ((*backup_buffer)[i] != '\n' && (*backup_buffer)[i] != '\0')
		i++;
	if ((*backup_buffer)[i] == '\n')
		i++;
	aux = *backup_buffer;
	str = ft_substr((*backup_buffer), 0, i);
	*backup_buffer = ft_strdup(&(*backup_buffer)[i]);
	free(aux);
	return (str);
}

int	get_line(int fd, char **buffer, char **backup_buffer)
{
	int		bytes_read;
	char	*aux;

	bytes_read = 1;
	while (bytes_read && !ft_strchr(*backup_buffer, '\n'))
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		(*buffer)[bytes_read] = '\0';
		aux = *backup_buffer;
		*backup_buffer = ft_strjoin(aux, *buffer);
		free(aux);
	}
	return (bytes_read);
}

char	*line_reader(int fd, char **buffer)
{
	static char	*backup_buffer;
	char		*tmp;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (!backup_buffer)
		backup_buffer = ft_strdup("");
	bytes_read = get_line(fd, buffer, &backup_buffer);
	if (bytes_read <= 0 && !*backup_buffer)
	{
		free_ptr(&backup_buffer);
		return (NULL);
	}
	if (ft_strchr(backup_buffer, '\n'))
		return (line_adjustment(&backup_buffer));
	tmp = ft_strdup(backup_buffer);
	free_ptr(&backup_buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = line_reader(fd, &buffer);
	free_ptr(&buffer);
	return (line);
}
