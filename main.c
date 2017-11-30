/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:33:19 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 15:37:22 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_data(t_data *data)
{
	data->index = 0;
	data->flag = 0;
	data->index_start = 0;
	data->index_end = 0;
	data->start_id = 0;
	data->ant_amount = 0;
	data->end_id = 0;
	data->room = 0;
	data->path_length = 0;
	data->str = ft_strnew(0);
	data->rooms = ft_strnew(0);
	data->links = ft_strnew(0);
}

int		make_data(t_data *data)
{
	data->arr = ft_strsplit(data->str, '\n');
	if (!line_is_digit(data->arr[0]))
		return (0);
	if (!no_start_end(data))
		return (0);
	if (!no_room_after_start_end(data))
		return (0);
	data->room_arr = ft_strsplit(data->rooms, ' ');
	if (!room_name_repeat(data, 0))
		return (0);
	data->link_arr = ft_strsplit(data->links, ',');
	if (!no_links_start_end(data))
		return (0);
	ft_count_rooms(data);
	return (1);
}

void	start(t_data *data, t_room *room, t_ant *ant)
{
	create_room_array(room, data, 0, 0);
	create_ant_array(ant, data, 0);
	go(data->index_start, -1, data, room);
	get_path(data);
	output(data);
	move_ants(data, room, ant);
}

int		main(int argc, char **arg)
{
	t_data	data;
	t_room	*room;
	t_ant	*ant;
	char	*line;

	if (invalid_input(argc, arg))
		return (call_error());
	set_data(&data);
	while (get_next_line(0, &line))
	{
		if (read_file(line, &data) == 0)
			return (call_error());
		free(line);
	}
	if (!make_data(&data))
		return (call_error());
	if (!(room = (t_room*)malloc(sizeof(t_room) * data.room)))
		return (0);
	if (!(ant = (t_ant*)malloc(sizeof(t_ant) * data.ant_amount)))
		return (0);
	if (!(data.visited = (int*)malloc(sizeof(int) * data.room)) ||
			!(data.prior = (int*)malloc(sizeof(int) * data.room)))
		return (0);
	start(&data, room, ant);
	return (0);
}
