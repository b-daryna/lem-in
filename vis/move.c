/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:23:12 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 19:43:48 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include <stdio.h>

int		my_key_func(int keycode, t_pixel *pxl)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 123)
	{
		if (pxl->ptr.command < pxl->ptr.moves)
		{
			mlx_clear_window(pxl->ptr.mlx, pxl->ptr.win);
			move_ants(pxl->ptr, pxl);
			pxl->ptr.command++;
			ft_draw(pxl->ptr, pxl);
		}
		else
			message(pxl);
	}
	if (keycode == 36)
	{
		pxl->ptr.command = 0;
		mlx_clear_window(pxl->ptr.mlx, pxl->ptr.win);
		start_again(pxl->ptr, pxl);
		ft_draw(pxl->ptr, pxl);
	}
	return (0);
}

void	message(t_pixel *pxl)
{
	mlx_string_put(pxl->ptr.mlx, pxl->ptr.win, WDTH / 3 + 80,
			200, 0xFF0000, "ALL ANTS GOT HOME SAFELY");
	mlx_string_put(pxl->ptr.mlx, pxl->ptr.win, WDTH / 2 - 50,
			220, 0xFF0000, "THE END!");
}

void	start_again(t_param data, t_pixel *pxl)
{
	int j;

	j = 0;
	while (data.rooms[j])
	{
		pxl[j].ants = 0;
		j++;
	}
	pxl[data.start].ants = data.ant_amount;
}

void	move_ants(t_param data, t_pixel *pxl)
{
	int		i;
	int		index;
	char	*name;
	char	**instruction;

	i = 0;
	instruction = ft_strsplit(data.commands[data.command], ' ');
	while (data.rooms[i])
	{
		if (!pxl[i].start && !pxl[i].end)
			pxl[i].ants = 0;
		i++;
	}
	i = -1;
	while (instruction[++i])
	{
		name = ft_strchr(instruction[i], '-') + 1;
		index = get_linked_room(name, data, pxl);
		if (pxl[index].ants == 0 || index == data.end)
			pxl[index].ants++;
	}
	if (pxl[data.start].ants > 0)
		pxl[data.start].ants--;
}
