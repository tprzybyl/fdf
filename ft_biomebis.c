/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_biomebis.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 19:43:33 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 19:30:05 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	biomesnow(t_param *p)
{
	p->tab[0]->x = 30;
	p->tab[0]->y = 40;
	p->tab[0]->z = 50;
	p->tab[1]->x = 112;
	p->tab[1]->y = 136;
	p->tab[1]->z = 173;
	p->tab[2]->x = 239;
	p->tab[2]->y = 240;
	p->tab[2]->z = 245;
	p->tab[3]->x = 226;
	p->tab[3]->y = 230;
	p->tab[3]->z = 233;
	p->tab[4]->x = 182;
	p->tab[4]->y = 191;
	p->tab[4]->z = 206;
	p->tab[5]->x = 58;
	p->tab[5]->y = 60;
	p->tab[5]->z = 64;
	p->tab[6]->x = 252;
	p->tab[6]->y = 253;
	p->tab[6]->z = 255;
}

void	biomemartin(t_param *p)
{
	p->tab[0]->x = 0;
	p->tab[0]->y = 0;
	p->tab[0]->z = 0;
	p->tab[1]->x = 0;
	p->tab[1]->y = 0;
	p->tab[1]->z = 0;
	p->tab[2]->x = 153;
	p->tab[2]->y = 0;
	p->tab[2]->z = 255;
	p->tab[3]->x = 255;
	p->tab[3]->y = 191;
	p->tab[3]->z = 0;
	p->tab[4]->x = 255;
	p->tab[4]->y = 118;
	p->tab[4]->z = 0;
	p->tab[5]->x = 255;
	p->tab[5]->y = 0;
	p->tab[5]->z = 0;
	p->tab[6]->x = 255;
	p->tab[6]->y = 255;
	p->tab[6]->z = 0;
}
