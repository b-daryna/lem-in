/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:34:28 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 12:43:23 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_path(t_data *data)
{
	int *rev_path;
	int i;
	int j;
	int r;

	i = 0;
	r = data->index_end;
	if (!(rev_path = (int*)malloc(sizeof(int) * data->room)))
		return ;
	while (r != data->index_start)
	{
		rev_path[i] = r;
		i++;
		r = data->prior[r];
	}
	rev_path[i] = data->index_start;
	if (!(data->path = (int *)malloc(sizeof(int) * (i + 1))))
		return ;
	data->path_length = i + 1;
	j = 0;
	while (i >= 0)
		data->path[j++] = rev_path[i--];
	data->path[j] = 0;
	free(rev_path);
}

void	go(int current, int from, t_data *data, t_room *room)
{
	char	**links;
	int		a;
	int		i;

	a = 0;
	if (data->visited[current] != 0)
		return ;
	data->visited[current] = 1;
	if (from >= 0)
		data->prior[current] = from;
	if (current == data->index_end)
		return ;
	links = ft_strsplit(room[current].link, ' ');
	i = -1;
	while (links[++i])
	{
		compare_link_name(data, &a, room, links[i]);
		free(links[i]);
		go(a, current, data, room);
	}
	free(links);
}

void	compare_link_name(t_data *data, int *a, t_room *room, char *link)
{
	int j;

	j = -1;
	while (++j < data->room)
	{
		if (ft_strcmp(room[j].name, link) == 0)
			*a = j;
	}
}

void	move_ants(t_data *data, t_room *room, t_ant *ant)
{
	t_helper	ints;
	int			k;

	ints.i = data->path_length - 2;
	ints.j = 0;
	k = 0;
	while (k < data->ant_amount)
	{
		if (ft_strcmp(ant[k].room, room[data->path[ints.i + 1]].name) == 0)
			ints.j++;
		k++;
	}
	move_helper(ints, room, data, ant);
	ft_printf("\n");
	if (room[data->index_end].ants < data->ant_amount)
		move_ants(data, room, ant);
}

void	move_helper(t_helper ints, t_room *room, t_data *data, t_ant *ant)
{
	while (ints.i >= 0)
	{
		if (room[data->path[ints.i]].ants)
		{
			room[data->path[ints.i + 1]].ant = ant[ints.j].number;
			ant[ints.j].room = room[data->path[ints.i + 1]].name;
			ant[ints.j].number = ints.j + 1;
			ft_printf("L%d-%s ", ant[ints.j].number, ant[ints.j].room);
			room[data->path[ints.i + 1]].ants++;
			room[data->path[ints.i]].ants--;
			ints.j++;
		}
		ints.i--;
	}
}
