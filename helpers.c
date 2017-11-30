/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:27:54 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 11:28:06 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
