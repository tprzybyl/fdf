/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gradient.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:04:03 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 20:32:34 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

void			get_gradcolor(t_param *param, int start, int end, int current)
{
	double perc;

	perc = percent(param->tab[start]->k, param->tab[end]->k, current);
	param->r = (char)get_light(param->tab[start]->x, param->tab[end]->x, perc);
	param->g = (char)get_light(param->tab[start]->y, param->tab[end]->y, perc);
	param->b = (char)get_light(param->tab[start]->z, param->tab[end]->z, perc);
}
