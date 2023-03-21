/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:02:17 by aurso             #+#    #+#             */
/*   Updated: 2023/03/05 22:08:33 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_el(char *temp, t_utto *p)
{
	int	i;
	int	cont_e;
	int	cont_p;

	i = -1;
	cont_e = 0;
	cont_p = 0;
	p->cont_c = 0;
	while (temp[++i])
		if (temp[i] == 'E')
			cont_e++;
	while (--i >= 0)
		if (temp[i] == 'P')
			cont_p++;
	while (temp[++i])
		if (temp[i] == 'C')
			p->cont_c++;
	if (cont_e != 1 || cont_p != 1 || p->cont_c == 0)
	{
		ft_error(8);
		return (1);
	}
	if (ft_check_pos(p))
		return (1);
	return (0);
}

int	ft_check_edges(t_utto *p)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (p->map[0][++i])
		if (p->map[0][i] != '1')
			check = 1;
	while (--i >= 0)
		if (p->map[p->ylen - 1][i] != '1')
			check = 1;
	while (++i < p->ylen)
		if (p->map[i][0] != '1')
			check = 1;
	while (--i >= 0)
		if (p->map[i][p->xlen - 1] != '1')
			check = 1;
	if (check == 1)
	{
		ft_error(7);
		return (1);
	}
	return (0);
}

int	ft_check_len(char *temp, t_utto *p)
{
	int	i;
	int	len;

	i = 0;
	p->map = ft_split(temp, '\n');
	len = (int)ft_strlen(p->map[0]);
	while (p->map[++i])
	{
		if ((int)ft_strlen(p->map[i]) != len)
		{
			ft_error(5);
			return (1);
		}
	}
	if (i == len)
	{
		ft_error(6);
		return (1);
	}
	p->ylen = i;
	p->xlen = len;
	if (ft_check_edges(p))
		return (1);
	return (0);
}

int	ft_check_string(char *temp, t_utto *p)
{
	char	*set;
	int		i;
	int		j;
	int		num;

	set = "01CEP\n";
	i = -1;
	while (temp[++i])
	{
		j = -1;
		num = 0;
		while (set[++j])
			if (temp[i] == set[j])
				num = 1;
		if (num == 0)
		{
			ft_fre(p->mapline);
			ft_error(4);
		}
	}
	if (ft_check_len(temp, p))
		return (1);
	if (ft_check_el(temp, p))
		return (1);
	return (0);
}

int	ft_check_map(char *path, t_utto *p)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		ft_error(3);
		return (1);
	}
	p->mapline = get_next_line(fd);
	line = get_next_line(fd);
	while (1)
	{
		p->mapline = ft_joinfree(p->mapline, line);
		free(line);
		line = get_next_line(fd);
		if (line == 0)
			break ;
	}
	close(fd);
	free(line);
	if (ft_check_string(p->mapline, p))
		return (1);
	return (0);
}
