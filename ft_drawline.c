/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_drawline.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 17:50:39 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 12:37:20 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		select_color(t_param *param, t_pos *src)
{
	int i;
	int x;

	if (!param->biome)
	{
		param->r = (char)255;
		param->g = (char)255;
		param->b = (char)255;
		return ;
	}
	i = 0;
	while (src->z > param->tab[i]->k)
		i++;
	x = (!(i)) ? 1 : i;
	if (param->grad)
		get_gradcolor(param, x - 1, i, src->z);
	else
	{
		param->r = (char)(param->tab[x]->x);
		param->g = (char)(param->tab[x]->y);
		param->b = (char)(param->tab[x]->z);
	}
}

static void	ft_firstcase(t_pos *src, t_param *param)
{
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;

	xinc = (param->dx > 0) ? 1 : -1;
	yinc = (param->dy > 0) ? 1 : -1;
	param->dx = ft_abs(param->dx);
	param->dy = ft_abs(param->dy);
	cumul = param->dx / 2;
	i = 1;
	while (i <= param->dx)
	{
		src->x += xinc;
		cumul += param->dy;
		if (cumul >= param->dx)
		{
			cumul -= param->dx;
			src->y += yinc;
		}
		fill_pixel(param, src->x, src->y);
		i++;
	}
}

static void	ft_secondcase(t_pos *src, t_param *param)
{
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;

	xinc = (param->dx > 0) ? 1 : -1;
	yinc = (param->dy > 0) ? 1 : -1;
	param->dx = ft_abs(param->dx);
	param->dy = ft_abs(param->dy);
	cumul = param->dy / 2;
	i = 1;
	while (i <= param->dy)
	{
		src->y += yinc;
		cumul += param->dx;
		if (cumul >= param->dy)
		{
			cumul -= param->dy;
			src->x += xinc;
		}
		fill_pixel(param, src->x, src->y);
		i++;
	}
}

void		ft_drawline(t_pos *src, t_pos *dst, t_param *param)
{
	t_pos	ssrc;

	ssrc.x = src->x;
	ssrc.y = src->y;
	param->dx = dst->x - src->x;
	param->dy = dst->y - src->y;
	(dst->z > src->z) ? select_color(param, dst) : select_color(param, src);
	fill_pixel(param, src->x, src->y);
	(ft_abs(param->dx) > ft_abs(param->dy)) ? ft_firstcase(src, param) :
		ft_secondcase(src, param);
	src->x = ssrc.x;
	src->y = ssrc.y;
}
