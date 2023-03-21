/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:14:22 by aurso             #+#    #+#             */
/*   Updated: 2023/03/15 00:14:35 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_utto *p)
{
	int	next;

	next = p->posx_p + 1;
	if (p->map[p->posy_p][next] == 'E' && p->cont_c == 0)
		ft_win(p);
	if (p->map[p->posy_p][next] != '1' && p->map[p->posy_p][next] != 'E')
	{
		p->posx_p++;
		ft_moves(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img.floor,
			(p->posx_p - 1) * SIZE, p->posy_p * SIZE);
		mlx_put_image_to_window(p->mlx, p->win, p->img.pg,
			p->posx_p * SIZE, p->posy_p * SIZE);
		if (p->map[p->posy_p][p->posx_p] == 'C')
		{
			p->map[p->posy_p][p->posx_p] = '0';
			p->cont_c--;
		}
	}
}

void	ft_move_left(t_utto *p)
{
	int	next;

	next = p->posx_p - 1;
	if (p->map[p->posy_p][next] == 'E' && p->cont_c == 0)
		ft_win(p);
	if (p->map[p->posy_p][next] != '1' && p->map[p->posy_p][next] != 'E')
	{
		p->posx_p--;
		ft_moves(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img.floor,
			(p->posx_p + 1) * SIZE, p->posy_p * SIZE);
		mlx_put_image_to_window(p->mlx, p->win, p->img.pg,
			p->posx_p * SIZE, p->posy_p * SIZE);
		if (p->map[p->posy_p][p->posx_p] == 'C')
		{
			p->map[p->posy_p][p->posx_p] = '0';
			p->cont_c--;
		}
	}
}

void	ft_move_down(t_utto *p)
{
	int	next;

	next = p->posy_p - 1;
	if (p->map[next][p->posx_p] == 'E' && p->cont_c == 0)
		ft_win(p);
	if (p->map[next][p->posx_p] != '1' && p->map[next][p->posx_p] != 'E')
	{
		p->posy_p--;
		ft_moves(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img.floor,
			p->posx_p * SIZE, (p->posy_p + 1) * SIZE);
		mlx_put_image_to_window(p->mlx, p->win, p->img.pg,
			p->posx_p * SIZE, p->posy_p * SIZE);
		if (p->map[p->posy_p][p->posx_p] == 'C')
		{
			p->map[p->posy_p][p->posx_p] = '0';
			p->cont_c--;
		}
	}
}

void	ft_move_up(t_utto *p)
{
	int	next;

	next = p->posy_p + 1;
	if (p->map[next][p->posx_p] == 'E' && p->cont_c == 0)
		ft_win(p);
	if (p->map[next][p->posx_p] != '1' && p->map[next][p->posx_p] != 'E')
	{
		p->posy_p++;
		ft_moves(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img.floor,
			p->posx_p * SIZE, (p->posy_p - 1) * SIZE);
		mlx_put_image_to_window(p->mlx, p->win, p->img.pg,
			p->posx_p * SIZE, p->posy_p * SIZE);
		if (p->map[p->posy_p][p->posx_p] == 'C')
		{
			p->map[p->posy_p][p->posx_p] = '0';
			p->cont_c--;
		}
	}
}

int	ft_key_hook(int key, t_utto *p)
{
	if (key == 65307)
		ft_close(p);
	if (p->check_loop == 0)
	{
		if (key == 100 || key == 65363)
			ft_move_right(p);
		else if (key == 97 || key == 65361)
			ft_move_left(p);
		else if (key == 119 || key == 65362)
			ft_move_down(p);
		else if (key == 115 || key == 65364)
			ft_move_up(p);
	}
	return (0);
}
