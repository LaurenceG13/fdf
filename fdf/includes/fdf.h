/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 22:24:33 by lagirard          #+#    #+#             */
/*   Updated: 2017/08/11 00:07:02 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE_BIS 999999

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	int			x_a;
	int			x_b;
	int			y_a;
	int			y_b;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			e;
	int			e2;
	int			x_win;
	int			y_win;
	int			color;
	char		*color_name;
	int			**tab;
	char		**map;
	int			nb_lines;
	int			nb_columns;
	int			*dest;
	int			scale;
	int			dim_l;
	int			dim_c;
	int			x;
	int			y;
	int			x2;
	int			y2;
	int			perspective;
	int			*str_img;
	int			bpp;
	int			s_l;
	int			endian;
	int			min_z;
	int			max_z;
	int			z2;
	int			z_a;
	int			z_b;
	int			x_slide;
	int			y_slide;
	int			deep;
	int			putimg;
	int			zoom;
	int			high;
	int			key;
	int			nbcol_first;
}				t_param;

int				main(int argc, char **argv);
int				ft_keycode(int keycode, void *s);
int				ft_colors(t_param *s);
int				ft_draw_segment(t_param *s);
int				ft_split(char *str, t_param *s);
int				ft_count_lines(char *str, t_param *s);
void			ft_print_tab_int(t_param *s);
void			ft_size_win(t_param *s);
void			ft_free_map(char **map);
void			ft_free_tab(t_param *s);
void			ft_trace_touching_points(t_param *s);
void			ft_size_win(t_param *s);
void			ft_color_altitude(t_param *s);
void			ft_proj_a(t_param *s);
void			ft_proj_b(t_param *s);
int				**ft_memalloc_tab_int(int size);
int				*ft_memalloc_str_int(int size);
int				ft_count_columns(char *line);
int				ft_isvalid(char *line);
int				*ft_convert(t_param *s);

#endif
