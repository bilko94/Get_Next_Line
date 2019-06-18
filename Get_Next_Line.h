/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 09:54:11 by solivari          #+#    #+#             */
/*   Updated: 2019/06/17 14:36:35 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 1

#include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif