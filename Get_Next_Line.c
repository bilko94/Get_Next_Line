/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:48:57 by solivari          #+#    #+#             */
/*   Updated: 2019/06/26 16:35:05 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get_Next_Line.h"

static int		ft_nextline(char **str, char **line, int fd, int ret)
	//takes the str and returns the Line//
{
	char	*tmp;
	int		length;

	length = 0;
	while (str[fd][length] != '\n' && str[fd][length] != '\0')
		length++;
	//get the length of the line//
	if (str[fd][length] == '\n')
	{
		*line = ft_strsub(str[fd], 0, length);
		// setting the line equal to everything before the first '\n'//
		// allocate memory for the tmp and pass into it the str[fd] of
		// the first line//
		tmp = ft_strdup(str[fd] + (length + 1));
		//then free the str and replace with the temp//
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][length] == '\0')
	{
		//if this check goes through this will be the final part of the program//
		//check to make sure the read completed, if it is equal to the buff_size it
		//read what it was supposed to and needs to continue//
		//set the line equal to the contents of the static str and
		// delete the string as we will no longer be using it//
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str[200];
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if ((line == NULL) || (fd < 0) || (ret = read(fd, NULL, 0) < 0))
		return (-1);
	//protection to make sure we don't read past the EOF//
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		//allocate a '\0' at the end the read (ret = +1 after the total read value),
		//this will act as the EOF character//
		//check to see if there is memory//
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		//insert the read into the str[fd], whilst allocating enough space
		//this will write of the 
		//existing '\0' of the first string//
		//after free'ing the str[fd] memory re allocate the with the tmp value//
		//check for a '\n' and if found break and check ret values//
		temp = ft_strjoin(str[fd], buffer);
		free (str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	if (ret < 0)
		return (-1);
	else if ((ret == 0 && str[fd] == NULL) || str[fd][0] == '\0')
		return (0);
	return (ft_nextline(str, line, fd, ret));
}
