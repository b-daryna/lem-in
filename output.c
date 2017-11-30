/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:32:58 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 12:34:10 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		invalid_input(int argc, char **arg)
{
	if (argc != 1 || !arg[0])
		return (1);
	return (0);
}

int		call_error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

void	output(t_data *data)
{
	int i;

	i = 0;
	while (data->arr[i])
	{
		ft_printf("%s\n", data->arr[i]);
		i++;
	}
	ft_printf("\n");
}
