/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_biomes.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 20:39:57 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 19:45:57 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	biomemarshell(t_param *p)
{
	p->tab[0]->x = 224;
	p->tab[0]->y = 210;
	p->tab[0]->z = 15;
	p->tab[1]->x = 224;
	p->tab[1]->y = 74;
	p->tab[1]->z = 15;
	p->tab[2]->x = 20;
	p->tab[2]->y = 5;
	p->tab[2]->z = 2;
	p->tab[3]->x = 85;
	p->tab[3]->y = 10;
	p->tab[3]->z = 17;
	p->tab[4]->x = 139;
	p->tab[4]->y = 17;
	p->tab[4]->z = 16;
	p->tab[5]->x = 171;
	p->tab[5]->y = 74;
	p->tab[5]->z = 21;
	p->tab[6]->x = 220;
	p->tab[6]->y = 113;
	p->tab[6]->z = 23;
}

static void	biomegglap(t_param *p)
{
	p->tab[0]->x = 50;
	p->tab[0]->y = 50;
	p->tab[0]->z = 200;
	p->tab[1]->x = 181;
	p->tab[1]->y = 217;
	p->tab[1]->z = 251;
	p->tab[2]->x = 243;
	p->tab[2]->y = 244;
	p->tab[2]->z = 238;
	p->tab[3]->x = 212;
	p->tab[3]->y = 239;
	p->tab[3]->z = 196;
	p->tab[4]->x = 172;
	p->tab[4]->y = 212;
	p->tab[4]->z = 144;
	p->tab[5]->x = 200;
	p->tab[5]->y = 200;
	p->tab[5]->z = 200;
	p->tab[6]->x = 240;
	p->tab[6]->y = 240;
	p->tab[6]->z = 240;
}

static void	biomenormal(t_param *p)
{
	p->tab[0]->x = 24;
	p->tab[0]->y = 24;
	p->tab[0]->z = 75;
	p->tab[1]->x = 8;
	p->tab[1]->y = 117;
	p->tab[1]->z = 153;
	p->tab[2]->x = 204;
	p->tab[2]->y = 255;
	p->tab[2]->z = 51;
	p->tab[3]->x = 32;
	p->tab[3]->y = 153;
	p->tab[3]->z = 0;
	p->tab[4]->x = 128;
	p->tab[4]->y = 64;
	p->tab[4]->z = 0;
	p->tab[5]->x = 132;
	p->tab[5]->y = 114;
	p->tab[5]->z = 98;
	p->tab[6]->x = 240;
	p->tab[6]->y = 240;
	p->tab[6]->z = 240;
}

static void	biomedesert(t_param *p)
{
	p->tab[0]->x = 24;
	p->tab[0]->y = 28;
	p->tab[0]->z = 75;
	p->tab[1]->x = 1;
	p->tab[1]->y = 172;
	p->tab[1]->z = 210;
	p->tab[2]->x = 255;
	p->tab[2]->y = 206;
	p->tab[2]->z = 154;
	p->tab[3]->x = 251;
	p->tab[3]->y = 182;
	p->tab[3]->z = 82;
	p->tab[4]->x = 138;
	p->tab[4]->y = 63;
	p->tab[4]->z = 31;
	p->tab[5]->x = 86;
	p->tab[5]->y = 58;
	p->tab[5]->z = 44;
	p->tab[6]->x = 57;
	p->tab[6]->y = 34;
	p->tab[6]->z = 20;
}

void		biome_pick(t_param *param)
{
	if (param->biome == 1)
		biomenormal(param);
	if (param->biome == 2)
		biomegglap(param);
	if (param->biome == 3)
		biomemarshell(param);
	if (param->biome == 4)
		biomedesert(param);
	if (param->biome == 5)
		biomesnow(param);
	if (param->biome == 9)
		biomemartin(param);
	if (!param->neg)
	{
		param->tab[0]->x = param->tab[1]->x;
		param->tab[0]->y = param->tab[1]->y;
		param->tab[0]->z = param->tab[1]->z;
	}
}
