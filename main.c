/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:18:43 by solivari          #+#    #+#             */
/*   Updated: 2019/06/26 16:18:46 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;
	int		gnlret;
	int		linecount;

	linecount = 0;
	gnlret = 1;
	fd = open(argv[1], O_RDONLY);
	printf("Argc: %d\n", argc);
	printf("File to open: %s\n", argv[1]);
	line = ft_memalloc(sizeof(char **));
	printf("BUFF_SIZE: %d\n\n\n", BUFF_SIZE);
	while ((gnlret = get_next_line(fd, line)) > 0)
	{
		printf("%s\n", *line);
		linecount++;
	}
	printf("Line count: %d\n", linecount);
	printf("Finished\n\n");
	close(fd);
	while(1);
	return (0);
}
