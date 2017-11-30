/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:22:48 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 10:23:01 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_create_win(t_pixel *pxl, t_param data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WDTH, HGHT, "visual");
	ft_draw(data, pxl);
	pxl->ptr = data;
	mlx_key_hook(data.win, my_key_func, pxl);
	mlx_loop(data.mlx);
}

void	ft_create_color(t_pixel *pxl, int n)
{
	pxl[n].color = 0xFFFFFF;
	if (pxl[n].ants > 0)
		pxl[n].color = 0xff8d00;
	if (pxl[n].start)
		pxl[n].color = 0xf0ff00;
	else if (pxl[n].end)
		pxl[n].color = 0xFF0000;
}

void	ft_count_image_size(t_pixel *pxl, t_param *data, int i)
{
	data->min_x = pxl[0].x;
	data->max_x = pxl[data->rooms_num - 1].x;
	data->min_y = pxl[0].y;
	data->max_y = pxl[data->rooms_num - 1].y;
	while (i < data->rooms_num)
	{
		if (pxl[i].x < data->min_x)
			data->min_x = pxl[i].x;
		if (pxl[i].x > data->max_x)
			data->max_x = pxl[i].x;
		if (pxl[i].y < data->min_y)
			data->min_y = pxl[i].y;
		if (pxl[i].y > data->max_y)
			data->max_y = pxl[i].y;
		i++;
	}
}
