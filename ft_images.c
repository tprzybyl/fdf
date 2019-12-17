/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_images.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 18:50:18 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 12:33:49 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			assign_biome(t_param *param, double w)
{
	double i;

	if (param->biome == 0)
		return ;
	param->tab[0]->k = param->min;
	param->tab[1]->k = 0;
	i = 1.0;
	while (i / w < 1.0)
		i += 1.0;
	param->tab[2]->k = (int)i;
	while (i / w < 7.0)
		i += 1.0;
	param->tab[3]->k = (int)i;
	while (i / w < 30.0)
		i += 1.0;
	param->tab[4]->k = (int)i;
	while (i / w < 40.0)
		i += 1.0;
	param->tab[5]->k = (int)i;
	param->tab[6]->k = param->max;
	if (param->biome)
		biome_pick(param);
}

static void		ft_border(t_param *param)
{
	int i;

	param->brushsize = 3;
	param->neg = 0;
	param->grad = 0;
	i = 0;
	while (i < 864000)
	{
		if (i % 800 == 0)
		{
			param->sborder[i] = (char)200;
			param->sborder[i + 1] = (char)200;
			param->sborder[i + 2] = (char)200;
			param->sborder[i + 3] = (char)0;
		}
		else
		{
			param->sborder[i] = (char)50;
			param->sborder[i + 1] = (char)50;
			param->sborder[i + 2] = (char)50;
			param->sborder[i + 3] = (char)0;
		}
		i += 4;
	}
	mlx_put_image_to_window(param, param->winpt, param->border, 1720, 0);
}

void			ft_images(t_param *param)
{
	int i;

	i = 0;
	if (!(param->tab = malloc(sizeof(t_pos*) * 7)))
		error_func(-1);
	while (i < 7)
	{
		if (!(param->tab[i] = malloc(sizeof(t_pos))))
			error_func(-1);
		i++;
	}
	param->sft = 1;
	param->biome = 0;
	param->vy = 0;
	param->anchory = 540;
	param->anchorx = 860 - 66 * param->len;
	param->zoom = 66;
	param->border = mlx_new_image(param->mlxpt, 200, 1080);
	param->sborder = mlx_get_data_addr(param->border, &param->bpp,
			&param->s_l, &param->endian);
	param->imgpt = mlx_new_image(param->mlxpt, 1720, 1080);
	param->simgpt = mlx_get_data_addr(param->imgpt, &param->bpp, &param->s_l,
			&param->endian);
	assign_biomestrings(param);
	ft_border(param);
}

void			fill_pixel(t_param *param, int x, int y)
{
	int i;

	if (0 > x || x >= 1720 || 0 > y || y >= 1080)
		return ;
	i = (4 * 1720 * y) + (x * 4);
	param->simgpt[i] = param->b;
	param->simgpt[i + 1] = param->g;
	param->simgpt[i + 2] = param->r;
	param->simgpt[i + 3] = (char)0;
}
