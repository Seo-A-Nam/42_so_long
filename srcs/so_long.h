/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:26:15 by senam             #+#    #+#             */
/*   Updated: 2022/02/11 17:16:22 by namseoa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
*   Header
*/

# include "../mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

/*
*   tile size settings
*/

# define TILES 30

/*
*   Event Key settings
*/

# define X_EVENT_KEYPRESS 2
# define X_EVENT_EXIT 17

# define KEY_W       13
# define KEY_A       0
# define KEY_S       1
# define KEY_D       2

# define KEY_ESC     53
# define KEY_ENTER   36

/*
*   structure containing current game data. (map, coordinate, number of items) 
*/
typedef struct s_param
{
	char	**map;
	int		x;
	int		y;
	int		items;
}		t_param;

/*
*   structure containing variables that indicates the info of image
*       - data : pixel pointer of image    
*   	- bpp : bit_per_pixel
*       - size_l : size of line
*/
typedef struct s_data
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}		t_data;

/*
*   structure containing images of charctor pose.
*/
typedef struct s_pose
{
	t_data	left;
	t_data	right;
	t_data	up;
	t_data	down;
	t_data	stand;
}		t_pose;

/*
*   structure containing status of current phase.
*/
typedef struct s_state
{
	bool	start;
	bool	rules;
	bool	end;
	bool	all_item;
}		t_state;

/*
*   structure containing overall varibales needed to play game.
*       - also conatins mlx graphic pointer and window pointer.
*       - param : current player data (coordinate, map, items)
*       - origin : backuped inital param data.
*		(need this when replaying game at the end phase)
*       - stat : status of game phase.
*       - map_img : initial image of map.
*       - pose : pose image of charactor in 4 direction.
*/
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		steps;
	int		col;
	int		row;
	int		width;
	int		height;
	t_state	stat;
	t_param	param;
	t_param	origin;
	t_data	map_img;
	t_data	tile;
	t_data	opened_exit;
	t_pose	pose;
}		t_vars;

/*
*
*       MAP
*
*/

/*
* ================= CHECK_MAP_UTILS.C ===================
*/
bool	is_map_component(char c);
bool	is_horizon_wall(char *line, int len);
bool	is_vertic_wall(char *line, int len);
void	count_map_component(char c, int *start_point, int *item, int *exit);
bool	is_count_valid(int start_point, int item, int exit);

/*
* ================== CHECK_MAP.C ========================
*/
bool	check_map(char **map, int row);
bool	check_map_line(char *line, int *start_point, int *item, int *exit);
bool	check_rectangular_shape(int col, char *line);
void	init_check_map_vars(int *i, int *start_point, int *item, int *exit);

/*
* ===================== ERROR.C =====================
*/
bool	error_file_format(char *filename);
bool	error_fd(int fd);

/*
* ===================== PARSE_MAP.C =====================
*/
int		count_newline(char *str);
int		get_row_count(char *filename);
void	get_map(char **map, int fd);
char	**parse_map(char *filename);

/*
* ===================== DRAW_MAP.C ======================
*/
void	draw_map(t_vars *game);
void	draw_pixels_of_texture(t_vars *game, char *filename, int row, int col);
void	draw_pixels_of_floor(t_vars *game, int row, int col);

/*
*
*       INIT
*
*/

/*
* =====================  INIT1.C ======================
*/
void	minilibx_init(t_vars *game);
void	map_init(t_vars *game, char *filename);
void	param_init(t_vars *game, t_param *param);

/*
* =====================  INIT2.C ======================
*/
void	image_init(t_vars *game);
void	color_box_init(t_vars *game, t_data *image, int color);
void	pose_image_init(t_vars *game);

/*
* =====================  MAIN.C ======================
*/

void	set_size(t_vars *game, char *filename);
void	get_initial_settings(t_vars *game, t_param *param, t_param *origin);
void	init(t_vars *game, char *filename);
int		start(t_vars *game);

/*
*
*       PLAY GAME
*
*/

/*
* ===================  KEY_HANDLING.C ====================
*/
int		x_key_clicked(void);
void	opening_phase(int keycode, t_vars *game);
void	intro_rules_phase(int keycode, t_vars *game);
void	ending_phase(int keycode, t_vars *game);
int		key_press(int keycode, t_vars *game);

/*
* ======================  MOVE.C =========================
*/
void	move_position(int keycode, t_param *param);
void	move_player(int keycode, t_vars *game, t_param pre);
bool	is_avail_move(t_vars *game, t_param *param, int keycode);

/*
* =====================  DRAW.C ======================
*/
void	open_alldoors(t_vars *game);
void	get_item(t_vars *game, t_param *param);
void	draw_next_step(t_vars *game, t_data img, t_param pre, t_param now);

/*
* ===================== OPENING_ENDING.c ====================
*/
void	display_opening_credit(t_vars *game);
void	display_ending_credit(t_vars *game);
void	display_rule_credit(t_vars *game);

#endif
