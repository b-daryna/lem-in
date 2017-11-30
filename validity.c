/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:35:16 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 15:35:44 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		no_start_end(t_data *data)
{
	int i;
	int flag_start;
	int flag_end;

	i = 0;
	flag_start = 0;
	flag_end = 0;
	while (data->arr[i])
	{
		if (ft_strcmp(data->arr[i], "##start") == 0)
			flag_start++;
		if (ft_strcmp(data->arr[i], "##end") == 0)
			flag_end++;
		i++;
	}
	if (flag_start != 1 || flag_end != 1)
		return (0);
	return (1);
}

int		no_room_after_start_end(t_data *data)
{
	int i;

	i = 0;
	while (data->arr[i])
	{
		if (ft_strcmp(data->arr[i], "##start") == 0)
		{
			i++;
			if (!ft_strchr(data->arr[i], ' ') || data->arr[i][0] == '#')
				return (0);
		}
		if (ft_strcmp(data->arr[i], "##end") == 0)
		{
			i++;
			if (!ft_strchr(data->arr[i], ' ') || data->arr[i][0] == '#')
				return (0);
		}
		i++;
	}
	return (1);
}

int		room_name_repeat(t_data *data, int num)
{
	int		i;
	int		cnt;
	int		res;
	char	*tmp;

	i = 0;
	cnt = 0;
	res = 1;
	tmp = data->room_arr[num];
	while (data->room_arr[i])
	{
		if (ft_strcmp(data->room_arr[i], tmp) == 0)
			cnt++;
		i++;
	}
	if (cnt > 1)
		return (0);
	else if (data->room_arr[++num])
		res = room_name_repeat(data, num);
	return (res);
}

int		no_links_start_end(t_data *data)
{
	int		i;
	int		cnt_start;
	int		cnt_end;

	i = 0;
	cnt_start = 0;
	cnt_end = 0;
	data->start = ft_strsplit(data->arr[data->start_id], ' ');
	data->end = ft_strsplit(data->arr[data->end_id], ' ');
	while (data->link_arr[i])
	{
		if (ft_strstr(data->link_arr[i], data->start[0]))
			cnt_start++;
		if (ft_strstr(data->link_arr[i], data->end[0]))
			cnt_end++;
		i++;
	}
	if (cnt_start == 0 || cnt_end == 0)
		return (0);
	return (1);
}
