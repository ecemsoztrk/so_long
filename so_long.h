/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecozturk <ecozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:36:25 by ecozturk          #+#    #+#             */
/*   Updated: 2023/04/12 15:35:13 by ecozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define B_XPM "./textures/background.xpm"
# define W_XPM "./textures/wall.xpm"
# define D_XPM "./textures/door.xpm"
# define C_XPM "./textures/coin.xpm"
# define P_XPM "./textures/player.xpm"

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_list
{
	int		row;
	int		column;
	char	*map;
	char	**split;
	char	**linesplit;
	void	**image;
	void	*window;
	void	*mlx;
	void	*background;
	int		image_x;
	int		image_y;
	int		player;
	int		exit_x;
	int		exit_y;
	int		map_x;
	int		map_y;
	int		step;
	int		exit;
	int		coin;
	int		score;

}			t_list;

char		**ft_split(char const *s, char c);
void		map_reader(t_list *data, char *str);
void		wall_control(t_list *data);
int			control(t_list *data, char *av);
void		other_character_control(t_list *data);
void		space_line(t_list *data);
void		cpe_control(t_list *data);
void		map_right(t_list *data);
void		player_location(t_list *data);
void		exit_location(t_list *data);
void		line(t_list *data, int y, int x);
void		coin_reach(t_list *data);
void		exit_reach(t_list *data);
char		*ft_itoa(int nbr);
int			check_ber(char *checking);
int			exit_func(void);
void		window(t_list *data);
int			keycode(int key, t_list *data);
void		background(t_list *data);
void		backgorund2(t_list *data, int i, int j);
void		step_by_step(t_list *data);
void		step_plus(t_list *data);
void		up(t_list *data);
void		right(t_list *data);
void		left(t_list *data);
void		down(t_list *data);
int			step_escape(t_list *data);

#endif