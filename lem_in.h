/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:28:27 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 15:35:04 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct	s_data
{
	int		index;
	int		index_start;
	int		index_end;
	int		start_id;
	int		end_id;
	int		ant_amount;
	int		room;
	int		l_i;
	int		l_j;
	char	*one;
	char	*two;
	char	*str;
	char	*rooms;
	char	*links;
	char	**room_arr;
	char	**link_arr;
	char	**arr;
	int		*path;
	int		path_length;
	int		*visited;
	int		*prior;
	int		flag;
	char	**start;
	char	**end;
}				t_data;

typedef struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		start;
	int		end;
	int		ants;
	int		ant;
	char	*link;
}				t_room;

typedef struct	s_ant
{
	int		number;
	char	*room;
}				t_ant;

typedef struct	s_helper
{
	int		i;
	int		j;
}				t_helper;

char			*ft_join(char **dst, char *src);
int				read_file(char *line, t_data *data);
int				check_line_validity(char *line, t_data *data);
int				check_room(char *line, t_data *data);
int				check_link(char *line, t_data *data, int j);
void			create_links(t_data *data, char *tmp1, char *tmp2);

int				invalid_input(int argc, char **arg);
int				call_error();
int				make_data(t_data *data);
int				no_start_end(t_data *data);
int				no_room_after_start_end(t_data *data);
int				room_name_repeat(t_data *data, int num);
int				no_links_start_end(t_data *data);

int				line_is_digit(char *line);
void			ft_count_ants(t_data *data, char *line, t_ant *ant);
void			ft_count_rooms(t_data *data);

void			start(t_data *data, t_room *room, t_ant *ant);
void			create_room_array(t_room *room, t_data *data, int i, int j);
void			get_start_end(t_room *room, t_data *data, int i, int j);
void			get_links(t_room *room, t_data *data);
void			add_to_link(t_room *room, t_data *data, int i);
void			create_ant_array(t_ant *ant, t_data *data, int i);

void			go(int current, int from, t_data *data, t_room *room);
void			compare_link_name(t_data *data, int *a, t_room *r, char *l);
void			get_path(t_data *data);

void			output(t_data *data);
void			move_ants(t_data *data, t_room *room, t_ant *ant);
void			move_helper(t_helper ints, t_room *r, t_data *dat, t_ant *ant);

#endif
