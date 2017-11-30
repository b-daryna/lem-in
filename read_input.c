/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:34:22 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 19:26:07 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_file(char *line, t_data *data)
{
	data->str = ft_join(&data->str, line);
	data->str = ft_join(&data->str, "\n");
	if (ft_strlen(line) == 0 || line[0] == 'L')
		return (0);
	if (ft_strcmp(line, "##start") == 0)
		data->start_id = data->index + 1;
	else if (ft_strcmp(line, "##end") == 0)
		data->end_id = data->index + 1;
	else if (line_is_digit(line) && line[0] == '0')
		return (0);
	else if (line_is_digit(line))
		data->ant_amount = ft_atoi(line);
	else if (line[0] == '#')
		;
	else
	{
		data->index++;
		return (check_line_validity(line, data));
	}
	data->index++;
	return (1);
}

int		check_line_validity(char *line, t_data *data)
{
	int i;
	int links;
	int rooms;

	i = 0;
	links = 0;
	rooms = 0;
	if (!ft_strchr(line, ' ') && !ft_strchr(line, '-'))
		return (0);
	while (line[i])
	{
		if (line[i] == ' ')
			rooms++;
		else if (line[i] == '-')
			links++;
		i++;
	}
	if (links > 0 && rooms > 0)
		return (0);
	if ((links == 0 && rooms != 2) || (rooms == 0 && links != 1))
		return (0);
	if ((rooms == 2 && check_room(line, data) == 0) ||
			(links == 1 && check_link(line, data, 0) == 0))
		return (0);
	return (1);
}

int		check_room(char *line, t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	if (data->flag)
		return (0);
	while (line[i] != ' ')
		i++;
	tmp = ft_strnew(i + 1);
	ft_strncpy(tmp, line, i + 1);
	data->rooms = ft_join(&data->rooms, tmp);
	free(tmp);
	i++;
	while (line[i] != ' ')
	{
		if (!ft_isdigit(line[i++]))
			return (0);
	}
	i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i++]))
			return (0);
	}
	return (1);
}

int		check_link(char *line, t_data *data, int j)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	data->flag = 1;
	while (line[i] != '-')
		i++;
	tmp1 = ft_strnew(i);
	ft_strncpy(tmp1, line, i);
	tmp2 = ft_strnew(ft_strlen(line) - i - 1);
	while (line[++i])
		tmp2[j++] = line[i];
	tmp2[i] = '\0';
	create_links(data, tmp1, tmp2);
	if (data->one && (int)ft_strlen(tmp1) == data->l_i
			&& data->two && (int)ft_strlen(tmp2) == data->l_j)
	{
		free(tmp1);
		free(tmp2);
		return (1);
	}
	free(tmp1);
	free(tmp2);
	return (0);
}

void	create_links(t_data *data, char *tmp1, char *tmp2)
{
	data->l_i = 0;
	data->l_j = 0;
	data->links = ft_join(&data->links, tmp1);
	data->links = ft_join(&data->links, "-");
	data->links = ft_join(&data->links, tmp2);
	data->links = ft_join(&data->links, ",");
	data->one = ft_strstr(data->rooms, tmp1);
	data->two = ft_strstr(data->rooms, tmp2);
	if (data->one)
	{
		while (data->one[data->l_i] != ' ')
			data->l_i++;
	}
	if (data->two)
	{
		while (data->two[data->l_j] != ' ')
			data->l_j++;
	}
}
