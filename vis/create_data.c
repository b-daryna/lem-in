/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:16:37 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 17:33:43 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	ft_create_rooms(t_param *data)
{
	char	*room;
	int		start;
	int		end;
	int		i;

	room = ft_strnew(0);
	start = 0;
	end = 0;
	i = -1;
	while (data->arr[++i])
	{
		if (line_is_digit(data->arr[i]))
			data->ant_amount = ft_atoi(data->arr[i]);
		else if (!ft_strcmp(data->arr[i], "##start"))
			start++;
		else if (!ft_strcmp(data->arr[i], "##end"))
			end++;
		else if (cretae_room_helper(data, i, &start, &end))
		{
			room = ft_join(&room, data->arr[i]);
			room = ft_join(&room, "\n");
		}
	}
	data->rooms = ft_strsplit(room, '\n');
	free(room);
}

int		cretae_room_helper(t_param *data, int i, int *start, int *end)
{
	if (ft_strchr(data->arr[i], ' ') && data->arr[i][0] != '#'
			&& data->arr[i][0] != 'L')
	{
		if (*start > 0)
		{
			data->start_room = ft_strdup(data->arr[i]);
			*start = 0;
		}
		if (*end > 0)
		{
			data->end_room = ft_strdup(data->arr[i]);
			*end = 0;
		}
		return (1);
	}
	return (0);
}

void	ft_create_links(t_param *data)
{
	char	*link;
	int		i;

	i = 0;
	link = ft_strnew(0);
	while (data->arr[i])
	{
		if (ft_strchr(data->arr[i], '-') && data->arr[i][0] != '#'
				&& data->arr[i][0] != 'L')
		{
			link = ft_join(&link, data->arr[i]);
			link = ft_join(&link, "\n");
		}
		i++;
	}
	data->links = ft_strsplit(link, '\n');
	free(link);
}

void	ft_create_commands(t_param *data, int cnt)
{
	int		i;
	char	*command;

	i = 0;
	command = ft_strnew(0);
	while (data->arr[i])
	{
		if (data->arr[i][0] == 'L')
		{
			command = ft_join(&command, data->arr[i]);
			command = ft_join(&command, ",");
			cnt++;
		}
		i++;
	}
	data->commands = ft_strsplit(command, ',');
	i = 0;
	while (data->commands[i])
	{
		data->moves++;
		i++;
	}
	free(command);
}

void	create_pxl(t_pixel *pxl, t_param *data, int i)
{
	while (data->rooms[i])
	{
		pxl[i].ants = 0;
		pxl[i].name = get_name(data, i);
		pxl[i].x = ft_atoi(data->rooms[i] + ft_strlen(pxl[i].name));
		pxl[i].y = ft_atoi(data->rooms[i] + ft_strlen(pxl[i].name) +
				ft_intsize(pxl[i].x) + 1);
		pxl[i].start = 0;
		pxl[i].end = 0;
		if (!ft_strcmp(data->start_room, data->rooms[i]))
		{
			pxl[i].start = 1;
			pxl[i].ants = data->ant_amount;
		}
		else if (!ft_strcmp(data->end_room, data->rooms[i]))
			pxl[i].end = 1;
		get_links(&pxl[i], data);
		i++;
	}
}
