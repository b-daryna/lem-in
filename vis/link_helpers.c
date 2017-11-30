/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:34:05 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 10:34:13 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	get_links(t_pixel *pxl, t_param *data)
{
	int		i;
	char	*tmp;
	char	*substr;

	i = 0;
	pxl->link = ft_strnew(0);
	while (data->links[i])
	{
		tmp = ft_strstr(data->links[i], pxl->name);
		if (tmp)
		{
			substr = ft_strstr(data->links[i], "-") + 1;
			if (ft_strchr(tmp, '-'))
				pxl->link = ft_join(&pxl->link, substr);
			else
				add_to_link(pxl, data, i);
			pxl->link = ft_join(&pxl->link, " ");
		}
		i++;
	}
}

void	add_to_link(t_pixel *pxl, t_param *data, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (data->links[i][j] != '-')
		j++;
	tmp = ft_strnew(j + 1);
	tmp = ft_strncpy(tmp, data->links[i], j);
	pxl->link = ft_join(&pxl->link, tmp);
	free(tmp);
}
