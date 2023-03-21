/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:33:26 by aurso             #+#    #+#             */
/*   Updated: 2023/03/05 22:02:08 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moves(t_utto *p)
{
	p->cont_m++;
	ft_printf("Moves: %d\n", p->cont_m);
}

void	ft_win(t_utto *p)
{
	mlx_put_image_to_window(p->mlx, p->win, p->img.floor,
		p->posx_p * SIZE, p->posy_p * SIZE);
	mlx_put_image_to_window(p->mlx, p->win, p->img.pg,
		p->posx_e * SIZE, p->posy_e * SIZE);
	ft_printf("You won!");
	p->check_loop = 1;
	ft_close(p);
}

void	ft_start(t_utto *p)
{
	p->check_loop = 0;
	p->cont_m = 0;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->xlen * SIZE, p->ylen * SIZE, "so_long");
	ft_init_img(p);
	mlx_hook(p->win, 2, 1L << 0, &ft_key_hook, p);
	mlx_hook(p->win, 17, 0, ft_close, p);
	mlx_loop(p->mlx);
}

int	main(int ac, char **av)
{
	t_utto	p;

	if (ac < 2)
		ft_error(1);
	else if (ac > 2)
		ft_error(2);
	else
	{
		if (ft_check_map(av[1], &p))
		{
			ft_free_mat(p.map);
			ft_fre(p.mapline);
			return (0);
		}
		ft_start(&p);
	}
	return (0);
}
