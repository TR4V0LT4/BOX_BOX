/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:16:04 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/18 13:29:48 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *save, int i)
{
	char	*line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_saving(char *save)
{
	int		i;
	int		j;
	char	*s;

	if (!save)
	{
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i) + 1);
	if (!s)
		return (NULL);
	if (save[i] == '\n')
		i++;
	j = 0;
	while (save[i])
	{
		s[j++] = save[i++];
	}
	s[j] = '\0';
	free(save);
	return (s);
}

char	*read_and_save(int fd, char *save)
{
	int		byt;
	char	*buff;

	byt = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n') && byt != 0)
	{
		byt = read(fd, buff, BUFFER_SIZE);
		if (byt < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[byt] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	if (byt == 0 && save[0] == '\0')
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	char static	*save;

	i = 0;
	save = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = ft_get_line(save, i);
	save = ft_saving(save);
	return (line);
}
