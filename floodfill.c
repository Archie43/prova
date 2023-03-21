/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:53:26 by aurso             #+#    #+#             */
/*   Updated: 2023/03/09 16:53:29 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fill(t_utto *p, int posx, int posy, int *check_ec)
{
	if (posx < 0 || posx > p->xlen || posy > p->ylen || posy < 0
		|| p->temp[posy][posx] == '1')
		return ;
	if (p->temp[posy][posx] == 'E')
		check_ec[0] = 1;
	if (p->temp[posy][posx] == 'C')
		check_ec[1] -= 1;
	p->temp[posy][posx] = '1';
	if (check_ec[1] == 0 && check_ec[0] == 1)
		return ;
	ft_fill(p, posx + 1, posy, check_ec);
	ft_fill(p, posx - 1, posy, check_ec);
	ft_fill(p, posx, posy + 1, check_ec);
	ft_fill(p, posx, posy - 1, check_ec);
}

int	ft_floodfill(t_utto *p)
{
	int	posx;
	int	posy;
	int	check_ec[2];

	posx = p->posx_p;
	posy = p->posy_p;
	check_ec[0] = 0;
	check_ec[1] = p->cont_c;
	p->temp = ft_split(p->mapline, '\n');
	ft_fill(p, posx, posy, check_ec);
	ft_free_mat(p->temp);
	if (check_ec[0] == 1 && check_ec[1] == 0)
		return (0);
	ft_error(9);
	return (1);
}

static void	ft_find_pos(t_utto *p, char c, int y, int x)
{
	if (c == 'P')
	{
		p->posx_p = x;
		p->posy_p = y;
	}
	else if (c == 'E')
	{
		p->posx_e = x;
		p->posy_e = y;
	}
}

int	ft_check_pos(t_utto *p)
{
	int	y;
	int	x;

	y = -1;
	while (p->map[++y])
	{
		x = -1;
		while (p->map[y][++x])
			ft_find_pos(p, p->map[y][x], y, x);
	}
	if (ft_floodfill(p))
		return (1);
	return (0);
}

void	ft_error(int tipo)
{
	if (tipo == 1)
		write(1, "Error, insert map", 17);
	else if (tipo == 2)
		write(1, "Error, too many arguments", 25);
	else if (tipo == 3)
	{
		write(1, "Error, invalid map path", 23);
		exit (0);
	}
	else if (tipo == 4)
	{
		write(1, "Error, invalid char in map", 26);
		exit (0);
	}
	else if (tipo == 5)
		write(1, "Error, different size of lines", 29);
	else if (tipo == 6)
		write(1, "Error, square map", 17);
	else if (tipo == 7)
		write(1, "Error, missing edges", 20);
	else if (tipo == 8)
		write(1, "Error, wrong number of P/E/C", 28);
	else if (tipo == 9)
		write(1, "Error, impossible to reach some C/E", 35);
}
