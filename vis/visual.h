/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:34:33 by dbessmer          #+#    #+#             */
/*   Updated: 2017/11/24 14:27:43 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WDTH 1200
# define HGHT 1000

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	double	wd;
	double	ht;
	double	start_x;
	double	start_y;
	double	step;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		x3;
	int		x4;
	int		y3;
	int		y4;
	int		start;
	int		end;
	int		command;
	int		moves;
	int		rooms_num;
	int		links_num;
	int		ant_amount;
	char	**rooms;
	char	**links;
	char	*start_room;
	char	*end_room;
	char	**arr;
	char	**commands;
}				t_param;

typedef struct	s_pixel
{
	int		color;
	char	*name;
	int		x;
	int		y;
	int		start;
	int		end;
	int		ants;
	char	*link;
	t_param ptr;
}				t_pixel;

void			set_data(t_param *data);
void			check_room_and_links(t_param *data, char *line);
void			create_data(t_param *data, char *str);
void			ft_create_rooms(t_param *data);
int				cretae_room_helper(t_param *data, int i, int *start, int *end);
void			ft_create_links(t_param *data);
void			ft_create_commands(t_param *data, int cnt);

void			create_pxl(t_pixel *pxl, t_param *data, int i);
void			get_start_end_index(t_pixel *pxl, t_param *data);
void			ft_create_win(t_pixel *pxl, t_param data);
void			ft_create_color(t_pixel *pxl, int n);
void			ft_count_image_size(t_pixel *pxl, t_param *data, int i);

char			*get_name(t_param *data, int num);
void			get_links(t_pixel *pxl, t_param *data);
void			add_to_link(t_pixel *pxl, t_param *data, int i);
char			*ft_join(char **dst, char *src);
int				line_is_digit(char *line);

void			ft_draw(t_param data, t_pixel *pxl);
void			draw_everything(t_param data, t_pixel *pxl);
void			draw_rooms(t_pixel pxl, t_param data, int x, int y);
void			draw_links(t_param data, t_pixel *pxl);
int				get_linked_num(char **links);
int				get_linked_room(char *room_name, t_param data, t_pixel *pxl);
void			ft_connect_x(t_param ptr, t_pixel pxl, t_pixel next);
void			ft_connect_y(t_param ptr, t_pixel pxl, t_pixel next);

int				my_key_func(int keycode, t_pixel *pxl);
void			move_ants(t_param data, t_pixel *pxl);
void			message(t_pixel *pxl);
void			start_again(t_param data, t_pixel *pxl);

int				error(void);
#endif
