/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:26:38 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 11:27:01 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_links(t_room *room, t_data *data)
{
	int		i;
	char	*tmp;
	char	*substr;

	i = 0;
	room->link = ft_strnew(0);
	while (data->link_arr[i])
	{
		tmp = ft_strstr(data->link_arr[i], room->name);
		if (tmp)
		{
			substr = ft_strstr(data->link_arr[i], "-") + 1;
			if (ft_strchr(tmp, '-'))
				room->link = ft_join(&room->link, substr);
			else
				add_to_link(room, data, i);
			room->link = ft_join(&room->link, " ");
		}
		i++;
	}
}

void	add_to_link(t_room *room, t_data *data, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (data->link_arr[i][j] != '-')
		j++;
	tmp = ft_strnew(j + 1);
	tmp = ft_strncpy(tmp, data->link_arr[i], j);
	room->link = ft_join(&room->link, tmp);
	free(tmp);
}
