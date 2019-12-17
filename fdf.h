/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 11:34:44 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:27:05 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct	s_pos
{
	int			x;
	int			z;
	int			y;
	int			k;
}				t_pos;

typedef struct	s_param
{
	void		*mlxpt;
	void		*winpt;
	void		*border;
	char		*sborder;
	void		*imgpt;
	char		*simgpt;
	char		*sbio[10];
	int			bpp;
	int			s_l;
	int			endian;
	int			len;
	int			wid;
	int			**values;
	int			**svalues;
	int			zoom;
	int			anchory;
	int			anchorx;
	int			neg;
	int			grad;
	int			dx;
	int			dy;
	int			vy;
	int			max;
	int			min;
	int			sft;
	char		r;
	char		g;
	char		b;
	int			vecx;
	int			vecy;
	int			biome;
	int			brushsize;
	t_pos		**tab;
}				t_param;

void			assign_biomestrings(t_param *param);
void			ft_printcommands(t_param *param);
void			modterrain(int button, int x, int y, t_param *param);
void			get_gradcolor(t_param *param, int start, int end, int current);
void			biomemartin(t_param *param);
void			biomesnow(t_param *param);
void			biome_pick(t_param *param);
void			assign_biome(t_param *param, double w);
void			resetvalues(t_param *param);
void			defvector(t_param *param);
void			defrota(t_param *param, int keycode);
void			defzoom(t_param *param, int keycode, int x, int y);
void			defanchor(t_param *param, int keycode);
void			ft_render(t_param *param);
void			ft_images(t_param *param);
void			ft_drawline(t_pos *src, t_pos *dst, t_param *param);
void			ft_getwidlen(t_param *param, int fd, int i);
void			fill_pixel(t_param *param, int x, int y);
void			error_func(int code);

#endif
