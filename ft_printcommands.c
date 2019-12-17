/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printcommands.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 19:35:12 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:52:29 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		assign_biomestrings(t_param *p)
{
	p->sbio[0] = ft_strdup("None");
	p->sbio[1] = ft_strdup("Normal");
	p->sbio[2] = ft_strdup("Google-ish");
	p->sbio[3] = ft_strdup("Lava/Hell");
	p->sbio[4] = ft_strdup("Desert");
	p->sbio[5] = ft_strdup("Snowy");
	p->sbio[6] = ft_strdup("N/A");
	p->sbio[7] = ft_strdup("N/A");
	p->sbio[8] = ft_strdup("N/A");
	p->sbio[9] = ft_strdup("Martin's");
}

static void	ft_printcommands_bis(t_param *p)
{
	(p->grad) ? mlx_string_put(p->mlxpt, p->winpt, 1850, 575, 0xFFCC00, "ON")
		: mlx_string_put(p->mlxpt, p->winpt, 1850, 575, 0xFFCC00, "OFF");
	mlx_string_put(p->mlxpt, p->winpt, 1730, 650, 0xFFFFFF, "Numpad *  =");
	mlx_string_put(p->mlxpt, p->winpt,
			1725, 675, 0xFFCCAA, "Neg gradient :");
	(p->neg) ? mlx_string_put(p->mlxpt, p->winpt, 1875, 675, 0xFFCC00, "ON")
		: mlx_string_put(p->mlxpt, p->winpt, 1875, 675, 0xFFCC00, "OFF");
	mlx_string_put(p->mlxpt, p->winpt,
			1730, 750, 0xFFFFFF, "Left/Right click =");
	mlx_string_put(p->mlxpt, p->winpt, 1735, 775, 0xFFCCAA, "Elevate / Dig");
	mlx_string_put(p->mlxpt, p->winpt, 1730, 850, 0xFFFFFF, "Shift / Ctrl  =");
	mlx_string_put(p->mlxpt, p->winpt,
			1725, 875, 0xFFCCAA, "Increase/Decrease");
	mlx_string_put(p->mlxpt, p->winpt,
			1725, 900, 0xFFCCAA, "brushsize :");
	mlx_string_put(p->mlxpt, p->winpt, 1860, 900, 0xFFCC00,
			ft_itoa(p->brushsize));
}

void		ft_printcommands(t_param *p)
{
	mlx_string_put(p->mlxpt, p->winpt, 1732, 10, 0xFFFFFF, "Keybinding list :");
	mlx_string_put(p->mlxpt, p->winpt,
			1730, 100, 0xFFFFFF, "WASD = Movement");
	mlx_string_put(p->mlxpt, p->winpt,
			1730, 150, 0xFFFFFF, "Arrow Up/Down =");
	mlx_string_put(p->mlxpt, p->winpt,
			1725, 175, 0xFFCCAA, "Z Axis rotation");
	mlx_string_put(p->mlxpt, p->winpt, 1880, 175, 0xFFCC00, ft_itoa(p->vy));
	mlx_string_put(p->mlxpt, p->winpt, 1730, 250, 0xFFFFFF, "Wheel scroll =");
	mlx_string_put(p->mlxpt, p->winpt, 1725, 275, 0xFFCCAA, "Zoom at cursor");
	mlx_string_put(p->mlxpt, p->winpt, 1870, 275, 0xFFCC00, ft_itoa(p->zoom));
	mlx_string_put(p->mlxpt, p->winpt, 1730, 350, 0xFFFFFF, "Numpad - / + =");
	mlx_string_put(p->mlxpt, p->winpt,
			1725, 375, 0xFFCCAA, "Altitude divisor");
	mlx_string_put(p->mlxpt, p->winpt, 1890, 375, 0xFFCC00, ft_itoa(p->sft));
	mlx_string_put(p->mlxpt, p->winpt,
			1730, 450, 0xFFFFFF, "Numpad [0 - 9] =");
	mlx_string_put(p->mlxpt, p->winpt,
			1725, 475, 0xFFCCAA, "Biome :");
	mlx_string_put(p->mlxpt, p->winpt, 1800, 475, 0xFFCC00, p->sbio[p->biome]);
	mlx_string_put(p->mlxpt, p->winpt, 1730, 550, 0xFFFFFF, "Numpad .  =");
	mlx_string_put(p->mlxpt, p->winpt,
			1725, 575, 0xFFCCAA, "Gradiant :");
	ft_printcommands_bis(p);
}
