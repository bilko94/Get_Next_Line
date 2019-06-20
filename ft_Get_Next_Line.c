/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:48:57 by solivari          #+#    #+#             */
/*   Updated: 2019/06/16 10:48:57 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Get_Next_Line.h"

int		ft_nextline(char **str, char **line, int fd, int ret)  //takes the str and returns the Line//
{
    char    *tmp;
    int     length;

    length = 0;
    while (str[fd][length] != '\n' || str[fd][length] != '\0')  //get the length of the line//
        length++;
    if (str[fd][length] == '\n')
    {
        *line = ft_strsub (str[fd], 0, length);     // setting the line equal to everything before the first '\n'//
        tmp = ft_strdub (str[fd], (length + 1));    // allocate memory for the tmp and pass into it the str[fd] of the first line//
        free (str[fd]);                             // then free the str and replace with the temp//
        str[fd] = tmp;
        if (str[fd][0] == '\0')
            ft_strdel(&str[fd]);
    }
    else if (str[fd][length] == '\0')           //if this check goes through this will be the final part of the program//
    {
        if (ret == BUFF_SIZE)                   //check to make sure the read completed, if it is equal to the buff_size it
            return (get_next_line(fd, line));   //read what it was supposed to and needs to continue//
        *line = ft_strdub(str[fd]);             //set the line equal to the contents of the static str and
        ft_strdel(&str[fd]);                    // delete the string as we will no longer be using it//
    }
    return (1);
}

int     ft_get_next_line(const int fd, char **line)
{
    static char     *str[200];
    char			buffer[BUFF_SIZE + 1];
    char			*temp;
    int				ret;

    if (**line == NULL || fd < 0 || (ret = read(fd, buffer, BUFF_SIZE) < 0))
        return (-1);
    while (ret = read(fd, buffer, BUFF_SIZE) > 0)
    {
        buffer[ret] = '\0';          //allocate a '\0' at the end the read (ret = 1 after the total read value), this will act as the EOF character//
        if (str[fd] == NULL)            //check to see if there is memory//
            str[fd] = ft_strnew(1);
        temp = ft_strjoin (str[fd], buffer);       //insert the read into the str[fd], whilst allocating enough space this will write of the 
        free (str[fd]);                            //existing '\0' of the first string//
        str[fd] = temp;                             //after free'ing the str[fd] memory re allocate the with the tmp value//
        if (strchr (buffer, '\n'))              //check for a '\n' and if found break and check ret values//
            break;
    }
	if (ret < 0)
        return (-1);
    else if ((ret == 0 && str[fd] == NULL) || str[fd][0] == '\0')
        return (0);
    return (ft_nextline(str, line, fd, ret));
}