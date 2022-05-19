/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:20:29 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/19 16:16:48 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stddef.h>
# include "./minilibx/mlx.h"
# include "./printf/ft_printf.h"

# define BUFFER_SIZE 42

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W	13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0

typedef struct s_data
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*player;
	void	*exit;
	void	*backgnd;
	void	*coins;
	int		coin_count;
	char	**map;
	int		steps;
	int		width;
	void	*ptr;
	int		length;
	int		col;
	int		row;
	int		num_p;
	int		num_e;
	int		num_c;
}	t_data;

size_t			ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
char			*get_next_line(int fd);
char			*next_line(char *save);
char			*get_line(char *save);
char			*read_line(int fd, char *save);
char			**ft_split(char *s, char c);
t_data			*init_data(void);
void			print_map(t_data *map);
void			read_map(char *map, t_data *data);
char			*mapcheck(t_data *data);
char			*ft_strdup(char *s1);
void			print_img(t_data *data);
int				keys(int keycode, t_data *data);
void			move_left(t_data *data);
void			load_img(t_data *data);
char			*get_player(char **map, t_data *data, char c);
void			move_right(t_data *data);
void			move_down(t_data *data);
void			move_up(t_data *data);
int				exit_game(t_data *data);
int				check_coins(t_data *data);
int				count_coins(t_data *data);
void			print_player(t_data *data);
void			check_wall(t_data *data);
void			checks(t_data *data);
int				end_game(t_data *data);
void			error_check(t_data *data, char c);
void			check_wall(t_data *data);
void			check_must(t_data *data);
void			count_steps(t_data *data);
void			check_args(int argc, char **argv);
void			put_img(char c, t_data *data, int col, int row);

#endif