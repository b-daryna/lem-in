/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:22:13 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 17:29:27 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

char	*ft_join(char **dst, char *src)
{
	char	*str;
	size_t	len;

	len = ft_strlen(*dst) + ft_strlen(src);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strcpy(str, *dst);
	ft_strcat(str, src);
	free(*dst);
	*dst = str;
	return (*dst);
}

int		line_is_digit(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i++]))
			return (0);
	}
	return (1);
}

void	get_start_end_index(t_pixel *pxl, t_param *data)
{
	int i;

	i = 0;
	while (i < data->rooms_num)
	{
		if (pxl[i].start)
			data->start = i;
		else if (pxl[i].end)
			data->end = i;
		i++;
	}
}

char	*get_name(t_param *data, int num)
{
	char	*str;
	char	**tmp;
	int		i;

	i = 0;
	str = ft_strnew(0);
	tmp = ft_strsplit(data->rooms[num], ' ');
	str = ft_join(&str, tmp[0]);
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	return (str);
}
