/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_func.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:34:51 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 18:00:10 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	error_func(int code)
{
	if (code == -4)
		perror("Close error");
	if (code == -3)
		perror("Read error");
	if (code == -2)
		perror("Open error");
	if (code == -1)
		perror("Memory allocation error");
	if (code == 0)
		ft_putendl_fd("usage ./fdf source_file", 2);
	if (code == 1)
		perror("minilibx error");
	if (code == 2)
		ft_putendl_fd("Wrong entry file (All lines must be of same size)", 2);
	if (code == 3)
		ft_putendl_fd("Wrong entry file (Must be at least 2 lines)", 2);
	exit(EXIT_FAILURE);
}
