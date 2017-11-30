/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:19:50 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 16:45:13 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_links(t_param data, t_pixel *pxl)
{
	int		n;
	int		link_amount;
	int		index;
	char	**links;
	int		i;

	n = 0;
	while (n < data.rooms_num)
	{
		links = ft_strsplit(pxl[n].link, ' ');
		link_amount = get_linked_num(links) - 1;
		while (link_amount >= 0)
		{
			index = get_linked_room(links[link_amount], data, pxl);
			ft_connect_x(data, pxl[n], pxl[index]);
			ft_connect_y(data, pxl[n], pxl[index]);
			link_amount--;
		}
		n++;
		i = 0;
		while (links[i])
			free(links[i++]);
		free(links);
	}
}

int		get_linked_num(char **links)
{
	int	i;

	i = 0;
	while (links[i])
		i++;
	return (i);
}

int		get_linked_room(char *room_name, t_param data, t_pixel *pxl)
{
	int i;

	i = 0;
	while (data.rooms[i])
	{
		if (!ft_strcmp(pxl[i].name, room_name))
			return (i);
		i++;
	}
	return (-1);
}

void	ft_connect_x(t_param data, t_pixel pxl, t_pixel next)
{
	int x;
	int y;

	next.x = next.x * data.step + data.start_x;
	next.y = next.y * data.step + data.start_y;
	pxl.x = pxl.x * data.step + data.start_x;
	pxl.y = pxl.y * data.step + data.start_y;
	data.x1 = pxl.x < next.x ? pxl.x : next.x;
	data.y1 = pxl.x < next.x ? pxl.y : next.y;
	data.x2 = pxl.x > next.x ? pxl.x : next.x;
	data.y2 = pxl.x > next.x ? pxl.y : next.y;
	x = data.x1;
	while (x < data.x2)
	{
		y = (x - data.x1) * (data.y2 - data.y1) / (data.x2 - data.x1) + data.y1;
		mlx_pixel_put(data.mlx, data.win, x, y, 0xbfbfbf);
		x++;
	}
}

void	ft_connect_y(t_param data, t_pixel pxl, t_pixel next)
{
	int x;
	int y;

	next.x = next.x * data.step + data.start_x;
	next.y = next.y * data.step + data.start_y;
	pxl.x = pxl.x * data.step + data.start_x;
	pxl.y = pxl.y * data.step + data.start_y;
	data.y3 = pxl.y < next.y ? pxl.y : next.y;
	data.x3 = pxl.y < next.y ? pxl.x : next.x;
	data.y4 = pxl.y > next.y ? pxl.y : next.y;
	data.x4 = pxl.y > next.y ? pxl.x : next.x;
	y = data.y3;
	while (y < data.y4)
	{
		x = (y - data.y3) * (data.x4 - data.x3) / (data.y4 - data.y3) + data.x3;
		mlx_pixel_put(data.mlx, data.win, x, y, 0xbfbfbf);
		y++;
	}
}
