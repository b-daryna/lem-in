/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:17:48 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 17:28:46 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_draw(t_param data, t_pixel *pxl)
{
	ft_count_image_size(pxl, &data, 0);
	data.wd = data.max_x - data.min_x;
	data.ht = data.max_y - data.min_y;
	data.step = (WDTH - (WDTH - data.wd) / 2) / data.rooms_num;
	if (data.ht > data.wd)
		data.step = (HGHT - (HGHT - data.ht) / 2) / data.rooms_num;
	if ((data.max_y - data.min_y) * data.step > HGHT)
		data.step /= 1.8;
	if ((data.max_x - data.min_x) * data.step > WDTH)
		data.step /= 1.8;
	data.start_x = (WDTH - (data.max_x + data.min_x) * data.step) / 2;
	data.start_y = (HGHT - (data.max_y + data.min_y) * data.step) / 2;
	draw_links(data, pxl);
	draw_everything(data, pxl);
}

void	draw_everything(t_param data, t_pixel *pxl)
{
	int		n;
	int		x;
	int		y;
	char	*ant_amount;

	n = 0;
	while (n < data.rooms_num)
	{
		x = pxl[n].x * data.step + data.start_x;
		y = pxl[n].y * data.step + data.start_y;
		ft_create_color(pxl, n);
		ant_amount = ft_itoa(pxl[n].ants);
		draw_rooms(pxl[n], data, x, y);
		if (pxl[n].start)
			mlx_string_put(data.mlx, data.win, x - 20, y - 45, 0xf0ff00,
					"start");
		if (pxl[n].end)
			mlx_string_put(data.mlx, data.win, x - 15, y - 45, 0xFF0000, "end");
		mlx_string_put(data.mlx, data.win, x - 5, y - 10, 0x000000, ant_amount);
		mlx_string_put(data.mlx, data.win, x - 8, y + 20, 0x878787,
				pxl[n].name);
		n++;
		free(ant_amount);
	}
}

void	draw_rooms(t_pixel pxl, t_param data, int x, int y)
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;

	start_y = y - 20;
	end_y = y + 20;
	while (start_y < end_y)
	{
		start_x = x - 20;
		end_x = x + 20;
		while (start_x - end_x)
		{
			mlx_pixel_put(data.mlx, data.win, start_x, start_y, pxl.color);
			start_x++;
		}
		start_y++;
	}
}
