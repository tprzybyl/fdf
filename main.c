/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 16:03:29 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 18:01:25 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int keycode, t_param *param)
{
	if (keycode >= 82 && keycode <= 92)
	{
		assign_biome(param, param->max / 100);
		param->biome = (keycode > 89) ? keycode - 83 : keycode - 82;
	}
	if (keycode == 257)
		param->brushsize += 3;
	if (keycode == 256 && param->brushsize != 3)
		param->brushsize -= 3;
	if (keycode == 67)
		param->neg = (!param->neg) ? 1 : 0;
	if (keycode == 65)
		param->grad = (!param->grad) ? 1 : 0;
	if (keycode == 53 && param)
		exit(EXIT_SUCCESS);
	if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		defanchor(param, keycode);
	if ((keycode >= 123 && keycode <= 126) || keycode == 78 || keycode == 69)
		defrota(param, keycode);
	if (keycode == 36)
		resetvalues(param);
	ft_render(param);
	return (0);
}

static int	mouse_press(int button, int x, int y, t_param *param)
{
	if (!param)
		return (0);
	if ((button == 1 || button == 2) && param->vy != -(param->zoom / 2))
		modterrain(button, x, y, param);
	if (button == 4 || button == 5)
		defzoom(param, button, x, y);
	ft_render(param);
	return (0);
}

static int	close_event(t_param *param)
{
	param->vy = 0;
	exit(EXIT_SUCCESS);
	return (0);
}

static int	expose_event(t_param *param)
{
	ft_render(param);
	return (0);
}

int			main(int ac, char **av)
{
	t_param			*param;
	int				fd;

	if (ac != 2)
		error_func(0);
	if (-1 == (fd = open(av[1], O_RDONLY)))
		error_func(-2);
	if (!(param = malloc(sizeof(t_param))))
		error_func(-1);
	ft_getwidlen(param, fd, 0);
	if (close(fd) == -1)
		error_func(-4);
	if (!(param->mlxpt = mlx_init()))
		error_func(1);
	if (!(param->winpt = mlx_new_window(param->mlxpt, 1920, 1080, av[1])))
		error_func(1);
	ft_images(param);
	ft_render(param);
	mlx_hook(param->winpt, 4, 0, mouse_press, param);
	mlx_hook(param->winpt, 2, 0, key_press, param);
	mlx_hook(param->winpt, 17, 0, close_event, param);
	mlx_hook(param->winpt, 12, 0, expose_event, param);
	mlx_loop(param->mlxpt);
	return (0);
}
