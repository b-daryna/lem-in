/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:23:53 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 14:28:53 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	set_data(t_param *data)
{
	data->ant_amount = 0;
	data->moves = 0;
	data->command = 0;
	data->rooms_num = 0;
	data->links_num = 0;
	data->start = 0;
	data->end = 0;
}

int		main(int argc, char **argv)
{
	t_param	data;
	char	*line;
	char	*str;

	set_data(&data);
	str = ft_strnew(0);
	if (argc != 1 || !argv[0])
		return (0);
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "ERROR"))
			return (error());
		str = ft_join(&str, line);
		str = ft_join(&str, "\n");
		check_room_and_links(&data, line);
		free(line);
	}
	create_data(&data, str);
	return (0);
}

void	check_room_and_links(t_param *data, char *line)
{
	if (ft_strchr(line, ' ') && line[0] != '#' && line[0] != 'L')
		data->rooms_num++;
	if (ft_strchr(line, '-') && line[0] != '#' && line[0] != 'L')
		data->links_num++;
}

void	create_data(t_param *data, char *str)
{
	t_pixel	*pxl;

	data->arr = ft_strsplit(str, '\n');
	ft_create_rooms(data);
	ft_create_links(data);
	ft_create_commands(data, 0);
	if (!(pxl = (t_pixel*)malloc(sizeof(t_pixel) * data->rooms_num)))
		return ;
	create_pxl(pxl, data, 0);
	get_start_end_index(pxl, data);
	ft_create_win(pxl, *data);
}

int		error(void)
{
	ft_printf("ERROR\n");
	return (0);
}
