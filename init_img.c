/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:44:17 by aurso             #+#    #+#             */
/*   Updated: 2023/03/13 22:02:54 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_utto *p, char c)
{
	if (c == '1')
		mlx_put_image_to_window(p->mlx, p->win, p->img.wall,
			p->mapx * SIZE, p->mapy * SIZE);
	else if (c == '0')
		mlx_put_image_to_window(p->mlx, p->win, p->img.floor,
			p->mapx * SIZE, p->mapy * SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(p->mlx, p->win, p->img.pg,
			p->mapx * SIZE, p->mapy * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->win, p->img.exit,
			p->mapx * SIZE, p->mapy * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->win, p->img.coll,
			p->mapx * SIZE, p->mapy * SIZE);
}

void	ft_checkset(t_utto *p)
{
	p->mapy = 0;
	while (p->mapy < p->ylen)
	{
		p->mapx = 0;
		while (p->mapx < p->xlen)
		{
			ft_put_img(p, p->map[p->mapy][p->mapx]);
			p->mapx++;
		}
		p->mapy++;
	}
}

void	ft_init_img(t_utto *p)
{
	static int	wh = 5;

	p->img.wall = mlx_xpm_file_to_image(p->mlx, "img/wall.xpm", &wh, &wh);
	p->img.floor = mlx_xpm_file_to_image(p->mlx, "img/flor.xpm", &wh, &wh);
	p->img.pg = mlx_xpm_file_to_image(p->mlx, "img/dino.xpm", &wh, &wh);
	p->img.coll = mlx_xpm_file_to_image(p->mlx, "img/ginger.xpm", &wh, &wh);
	p->img.exit = mlx_xpm_file_to_image(p->mlx, "img/exit.xpm", &wh, &wh);
	ft_checkset(p);
}
