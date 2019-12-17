/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_entryfile.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 19:01:57 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:26:25 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_wid(char *str, t_param *param, int i)
{
	int			tmp;

	tmp = 0;
	param->wid = 1;
	while (str[i])
	{
		while (ft_isblank(str[i]))
			i++;
		if (!ft_isblank(str[i]) && str[i] != '\n' && str[i])
			tmp += 1;
		while (!ft_isblank(str[i]) && str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n' || !str[i])
		{
			if ((tmp = tmp - param->len) != 0)
				error_func(2);
			i++;
			param->wid += 1;
		}
	}
}

static void	ft_makevalues(t_param *param)
{
	int x;

	param->max = 0;
	param->min = 0;
	if (!(param->svalues = malloc(sizeof(int*) * param->wid)))
		error_func(-1);
	if (!(param->values = malloc(sizeof(int*) * param->wid)))
		error_func(-1);
	x = 0;
	while (x < param->wid)
	{
		if (!(param->svalues[x] = malloc(sizeof(int) * param->len)))
			error_func(-1);
		if (!(param->values[x] = malloc(sizeof(int) * param->len)))
			error_func(-1);
		x++;
	}
}

static void	ft_setvalues(char *str, t_param *param, int y)
{
	int			i;
	int			j;
	int			x;
	char		*tmp;

	i = 0;
	j = 0;
	x = -1;
	while (++x < param->len)
	{
		while (ft_isblank(str[i]))
			i++;
		if (!ft_isblank(str[i]) && str[i])
			j = 0;
		while (!ft_isblank(str[i + j]) && str[i + j])
			j++;
		if (!(tmp = ft_strsub(str, i, j)))
			error_func(-1);
		param->values[y][x] = ft_atoi(tmp);
		param->svalues[y][x] = ft_atoi(tmp);
		param->min = (ft_atoi(tmp) < param->min) ? ft_atoi(tmp) : param->min;
		param->max = (ft_atoi(tmp) > param->max) ? ft_atoi(tmp) : param->max;
		ft_strdel(&tmp);
		i += j;
	}
}

static void	ft_scan(char *str, t_param *param)
{
	int			i;
	int			j;
	int			y;
	char		*line;

	y = 0;
	i = 0;
	while (str[i])
	{
		j = i;
		if (str[j])
			j++;
		while (str[j] != '\n' && str[j])
			j++;
		if (!(line = ft_strsub(str, i, j - i)))
			error_func(-1);
		ft_setvalues(line, param, y);
		ft_strdel(&line);
		if (!str[j])
			break ;
		i = j + 1;
		y++;
	}
}

void		ft_getwidlen(t_param *param, int fd, int i)
{
	char	*str;

	param->len = 0;
	if (!(str = ft_strdup("")))
		error_func(-1);
	if (!ft_strgetfrom(fd, &str))
		error_func(-3);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		while (ft_isblank(str[i]))
			i++;
		if (!ft_isblank(str[i]) && str[i] != '\n' && str[i])
			param->len += 1;
		while (!ft_isblank(str[i]) && str[i] != '\n' && str[i])
			i++;
	}
	if (!param->len)
		error_func(3);
	ft_wid(str, param, i + 1);
	if (param->wid < 2)
		error_func(3);
	ft_makevalues(param);
	ft_scan(str, param);
	ft_strdel(&str);
}
