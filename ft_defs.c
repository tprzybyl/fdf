/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   defines.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 19:19:56 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 16:15:06 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			defrota(t_param *param, int keycode)
{
	if (keycode == 78 && param->sft != 10)
		param->sft += 1;
	if (keycode == 69 && param->sft != 1)
		param->sft -= 1;
	if (keycode == 126 && param->vy != param->zoom / 2)
		param->vy += 1;
	if (keycode == 125 && param->vy != -(param->zoom / 2))
		param->vy -= 1;
}

void			defzoom(t_param *param, int keycode, int x, int y)
{
	int xtmp;
	int ytmp;

	xtmp = (x - param->anchorx) / param->zoom;
	ytmp = (y - param->anchory) / (param->zoom / 2);
	if (keycode == 4 && param->zoom < 100)
	{
		param->vy = 0;
		param->zoom += 4;
		param->anchorx = x - param->zoom * xtmp;
		param->anchory = y - param->zoom / 2 * ytmp;
	}
	if (keycode == 5 && param->zoom > 2)
	{
		param->vy = 0;
		param->zoom -= 4;
		param->anchorx = x - param->zoom * xtmp;
		param->anchory = y - param->zoom / 2 * ytmp;
	}
}

void			defanchor(t_param *param, int keycode)
{
	if (keycode == 0)
		param->anchorx += 20 + param->zoom / 3;
	if (keycode == 13)
		param->anchory += 10 + param->zoom / 4;
	if (keycode == 2)
		param->anchorx -= 20 + param->zoom / 3;
	if (keycode == 1)
		param->anchory -= 10 + param->zoom / 4;
}

void			defvector(t_param *param)
{
	param->vecx = param->zoom;
	param->vecy = param->zoom / 2 + param->vy;
}

void			resetvalues(t_param *param)
{
	int x;
	int y;

	y = 0;
	while (y < param->wid)
	{
		x = 0;
		while (x < param->len)
		{
			if (param->values[y][x] != param->svalues[y][x])
				param->values[y][x] = param->svalues[y][x];
			x++;
		}
		y++;
	}
	param->brushsize = 3;
	param->biome = 0;
	param->sft = 1;
	param->vy = 0;
	param->anchory = 540;
	param->anchorx = 200;
	param->zoom = 66;
}
