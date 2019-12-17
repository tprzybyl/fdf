/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rendering.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 19:36:39 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 12:34:21 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_clearimg(t_param *param)
{
	int i;

	i = 0;
	while (i < 7430400)
	{
		if (i)
			param->simgpt[i] = (char)0;
		if (i + 1)
			param->simgpt[i + 1] = (char)0;
		if (i + 2)
			param->simgpt[i + 2] = (char)0;
		if (i + 3)
			param->simgpt[i + 3] = (char)0;
		i += 4;
	}
}

static char		horizontalline(t_param *p, t_pos *s, t_pos *e)
{
	t_pos	h;

	if (e->x + 1 >= p->len)
		return (0);
	h.z = p->values[e->y][e->x + 1];
	h.x = p->anchorx + ((e->x + 1) * p->vecx);
	h.y = (p->anchory - ((e->x + 1) * p->vecy) -
			p->values[e->y][e->x + 1] * (p->vecy - 2 * p->vy)
			/ (p->sft * p->sft));
	if (s->x > 1720)
		if (h.x > 1720)
			return (1);
	if (s->y > 1080)
		if (h.y > 1080)
			return (0);
	if (s->y < 0)
		if (h.x < 0)
			return (0);
	if (s->x < 0)
	{
		if (h.x < 0)
			return (0);
	}
	ft_drawline(s, &h, p);
	return (0);
}

static char		verticalline(t_param *p, t_pos *s, t_pos *e)
{
	t_pos	v;

	if (e->y + 1 >= p->wid)
		return (0);
	v.z = p->values[e->y + 1][e->x];
	v.x = (p->anchorx + p->vecx) + ((e->x) * p->vecx);
	v.y = ((p->anchory + p->vecy) - (e->x * p->vecy) -
			p->values[e->y + 1][e->x] * (p->vecy - 2 * p->vy)
			/ (p->sft * p->sft));
	if (s->x > 1720)
		if (v.x > 1720)
			return (1);
	if (s->y > 1080)
		if (v.y > 1080)
			return (0);
	if (s->y < 0)
		if (v.x < 0)
			return (0);
	if (s->x < 0)
	{
		if (v.x < 0)
			return (0);
	}
	ft_drawline(s, &v, p);
	return (0);
}

static void		ft_gridprint(t_param *p)
{
	t_pos	e;
	t_pos	s;

	e.y = 0;
	while (e.y < p->wid)
	{
		e.k = 0;
		e.x = 0;
		while (e.x < p->len)
		{
			s.z = p->values[e.y][e.x];
			s.x = p->anchorx + (e.x * p->vecx);
			s.y = (p->anchory - (e.x * p->vecy) - p->values[e.y][e.x] *
					(p->vecy - 2 * p->vy)
					/ (p->sft * p->sft));
			e.k += horizontalline(p, &s, &e);
			e.k += verticalline(p, &s, &e);
			if (e.k == 2)
				break ;
			e.x++;
		}
		p->anchorx += p->vecx;
		p->anchory += p->vecy;
		e.y++;
	}
}

void			ft_render(t_param *param)
{
	double			w;
	t_pos			save;

	ft_clearimg(param);
	w = param->max / 100.0;
	assign_biome(param, w);
	defvector(param);
	save.x = param->anchorx;
	save.y = param->anchory;
	ft_gridprint(param);
	param->anchorx = save.x;
	param->anchory = save.y;
	mlx_put_image_to_window(param, param->winpt, param->border, 1720, 0);
	ft_printcommands(param);
	mlx_put_image_to_window(param, param->winpt, param->imgpt, 0, 0);
}
