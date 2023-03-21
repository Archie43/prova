/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:56:02 by aurso             #+#    #+#             */
/*   Updated: 2023/03/14 23:56:07 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_joinfree(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	ft_fre(buffer);
	return (temp);
}

char	*ft_fre(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

int	ft_free_mat(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		ft_fre(matrix[y]);
		y++;
	}
	free(matrix);
	return (0);
}

int	ft_close(t_utto *p)
{
	mlx_destroy_image(p->mlx, p->img.floor);
	mlx_destroy_image(p->mlx, p->img.wall);
	mlx_destroy_image(p->mlx, p->img.pg);
	mlx_destroy_image(p->mlx, p->img.coll);
	mlx_destroy_image(p->mlx, p->img.exit);
	mlx_clear_window(p->mlx, p->win);
	mlx_destroy_window(p->mlx, p->win);
	mlx_destroy_display(p->mlx);
	ft_free_mat(p->map);
	ft_fre(p->mapline);
	ft_fre(p->mlx);
	exit(0);
}
