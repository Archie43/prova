/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:28:01 by aurso             #+#    #+#             */
/*   Updated: 2023/03/07 16:28:45 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <time.h>

# ifndef SIZE
#  define SIZE 50
# endif

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*pg;
	void	*exit;
	void	*coll;
}	t_img;

typedef struct s_utto
{
	void	*mlx;
	char	**map;
	char	**temp;
	char	*mapline;
	void	*win;
	int		xlen;
	int		ylen;
	int		mapx;
	int		mapy;
	int		cont_c;
	int		posx_p;
	int		posy_p;
	int		posx_e;
	int		posy_e;
	int		cont_m;
	int		check_loop;
	t_img	img;

}	t_utto;

void	ft_start(t_utto *p);
void	ft_win(t_utto *p);
void	ft_moves(t_utto *p);

/*Close*/
void	ft_error(int tipo);
char	*ft_fre(char *str);
int		ft_free_mat(char **matrix);
char	*ft_joinfree(char *buffer, char *buf);
int		ft_close(t_utto *p);

/*Init img*/
void	ft_init_img(t_utto *p);
void	ft_checkset(t_utto *p);
void	ft_put_img(t_utto *p, char c);

/*Check map*/
int		ft_check_map(char *path, t_utto *p);
int		ft_check_string(char *temp, t_utto *p);
int		ft_check_len(char *temp, t_utto *p);
int		ft_check_el(char *temp, t_utto *p);
int		ft_check_edges(t_utto *p);
int		ft_check_pos(t_utto *p);
int		ft_floodfill(t_utto *p);

/*Command*/
int		ft_key_hook(int key, t_utto *p);
void	ft_move_right(t_utto *p);
void	ft_move_left(t_utto *p);
void	ft_move_down(t_utto *p);
void	ft_move_up(t_utto *p);

#endif
