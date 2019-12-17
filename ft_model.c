/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_model.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 18:45:49 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 15:25:22 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_moddown(t_param *param, int ox, int oy)
{
	int x;
	int y;
	int dx;
	int dy;

	y = 0;
	while (y < param->wid)
	{
		x = 0;
		while (x < param->len)
		{
			dx = ft_abs(x - ox);
			dy = ft_abs(y - oy);
			if (dx + dy < param->brushsize)
			{
				if (param->values[y][x] -
						param->brushsize - (dx + dy) <= param->min)
					param->values[y][x] = param->min;
				else
					param->values[y][x] -= param->brushsize - (dx + dy);
			}
			x++;
		}
		y++;
	}
}

static void	ft_modup(t_param *param, int ox, int oy)
{
	int x;
	int y;
	int dx;
	int dy;

	y = 0;
	while (y < param->wid)
	{
		x = 0;
		while (x < param->len)
		{
			dx = ft_abs(x - ox);
			dy = ft_abs(y - oy);
			if (dx + dy < param->brushsize)
			{
				if (param->values[y][x] + param->brushsize -
						(dx + dy) > param->max)
					param->values[y][x] = param->max;
				else
					param->values[y][x] += param->brushsize - (dx + dy);
			}
			x++;
		}
		y++;
	}
}

void		modterrain(int button, int x, int y, t_param *param)
{
	int tx;
	int ty;
	int tmp;
	int vx;
	int vy;

	vx = param->zoom;
	vy = param->zoom / 2 + param->vy;
	tx = 0;
	while (!(tx * vx - vx / 2 + param->anchorx <= x) ||
			!(tx * vx + vx / 2 + param->anchorx > x))
		tx++;
	ty = 0;
	tmp = (!tx % 2) ? vy : 0;
	while (!((param->anchory - tx * vy - vy + tmp) + ty * 2 * vy <= y) ||
			!((param->anchory - tx * vy + vy + tmp) + ty * 2 * vy > y))
		ty++;
	tx -= ty;
	if (tx >= 0 && tx < param->len && ty >= 0 && ty <= param->wid)
	{
		button == 1 ? ft_modup(param, tx, ty) :
			ft_moddown(param, tx, ty);
	}
}
