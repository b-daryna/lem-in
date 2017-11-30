/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:27:23 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 19:25:01 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_count_rooms(t_data *data)
{
	int i;

	i = 0;
	data->room = 0;
	while (data->room_arr[i++])
		data->room++;
}

void	create_room_array(t_room *room, t_data *data, int i, int j)
{
	while (data->arr[i])
	{
		if (ft_strchr(data->arr[i], ' ') && data->arr[i][0] != '#' &&
				data->arr[i][0] != 'L')
		{
			room[j].ants = 0;
			room[j].ant = 0;
			room[j].name = data->room_arr[j];
			room[j].x = ft_atoi(data->arr[i] + ft_strlen(room[j].name));
			room[j].y = ft_atoi(data->arr[i] + ft_strlen(room[j].name) +
					ft_intsize(room[j].x) + 1);
			room[j].start = 0;
			room[j].end = 0;
			get_start_end(room, data, i, j);
			get_links(&room[j], data);
			j++;
		}
		i++;
	}
}

void	get_start_end(t_room *room, t_data *data, int i, int j)
{
	if (i == data->start_id)
	{
		data->index_start = j;
		room[j].start = 1;
		room[j].ants = data->ant_amount;
	}
	else if (i == data->end_id)
	{
		data->index_end = j;
		room[j].end = 1;
	}
}

void	create_ant_array(t_ant *ant, t_data *data, int i)
{
	while (i < data->ant_amount)
	{
		ant[i].number = i + 1;
		ant[i].room = data->room_arr[data->index_start];
		i++;
	}
}
