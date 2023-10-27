/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:11:13 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/27 19:29:30 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
================================================================================
						typedefs, defines, includes & enums
================================================================================
*/

# include <stdbool.h>
# include <stdint.h>
# include <stddef.h>

typedef uint32_t	t_color;

# define COLOR_BG 0x0F0F0F
# define COLOR_GRID 0x1B1B1B
# define COLOR_FLOOR 0x0F0F0F
# define COLOR_WALL 0xFF00FF
# define COLOR_LOOT 0xFFFF00
# define COLOR_PLAYER 0xFF0000
# define COLOR_EXIT_OFF 0x306030
# define COLOR_EXIT_ON 0x00FF00
# define COLOR_ENEMY 0x000000

/* Config
================================================================================
*/
# define CONF_WINDOW_WIDTH 1600
# define CONF_GAME_WIDTH 1440
# define CONF_WINDOW_HEIGHT 912
# define CONF_WINDOW_TITLE "so_long"
# define CONF_FPS 60
# define CONF_TILE_SIZE 48
# define CONF_ARENA_SIZE 1e8

/* map
================================================================================
*/
# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_LOOT 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'
# define MAP_ENEMY 'M'

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
	int		objectives;
	int		collectibles;
	int		x_offset;
	int		y_offset;
}	t_map;

/* parse
================================================================================
*/
// size (in KB) of the buffer to store file content
# define PARSE_FILE_SIZE 3000

// number of bytes read by read()
# define PARSE_READ_SIZE 8192

typedef struct s_stream {
	int		fd;
	int		rd;
	char	*ptr;
	char	*buf[PARSE_READ_SIZE];
	bool	read_success;
}	t_stream;

typedef struct s_map_comp {
	int	wall;
	int	collectible;
	int	player;
	int	exit;
}	t_map_comp;

/* maths
================================================================================
*/

# ifndef M_PI
#  define M_PI 3.14159265359
# endif

typedef struct s_pixel {
	int		x;
	int		y;
	t_color	color;
}	t_pixel;

typedef struct s_triangle {
	t_pixel	p1;
	t_pixel	p2;
	t_pixel	p3;
}	t_triangle;

typedef struct s_rect {
	int		x;
	int		y;
	int		width;
	int		height;
}	t_rect;

typedef struct s_circle {
	int	x;
	int	y;
	int	radius;
}	t_circle;

/* graphics
================================================================================
*/
typedef struct s_mlx_image {
	void	*ptr;
	t_color	*raster;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_mlx_image;

typedef struct s_graphics
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_image	*front_buffer;
	t_mlx_image	*back_buffer;
}	t_graphics;

typedef struct s_dda {
	int		delta_x;
	int		delta_y;
	int		side_length;
	float	x_inc;
	float	y_inc;
	float	current_x;
	float	current_y;
	int		i;
}	t_dda;

/* timer
================================================================================
*/
typedef struct s_timer {
	long	time_start;
}	t_timer;

/* player
================================================================================
*/
enum {
	PLAYER_IDLE,
	PLAYER_MOVE,
	PLAYER_JUMP,
	PLAYER_DEAD
};

typedef struct s_player
{
	int	state;
	int	mvts;
	int	collected;
	int	pos_x;
	int	pos_y;
}	t_player;

/* data
================================================================================
*/
typedef struct s_data {
	void		*arena;
	t_map		*map;
	t_graphics	*grph;
	t_timer		*timer;
	t_player	*player;
	bool		unlocked;
}	t_data;

/*
================================================================================
								functions
================================================================================
*/

/* maths
================================================================================
*/
int			absi(int x);

/* parse
================================================================================
*/
bool		parse_map_dimensions(t_map *map);
bool		parse_map_walls(t_map *map);
bool		parse_map_components(t_map *map);
bool		parse(t_map *map, const char *filename);

/* graphics
================================================================================
*/
bool		graphics_init(t_data *data);
void		graphics_terminate(t_graphics *grph);
void		graphics_clear(t_graphics *grph, t_color color);
void		graphics_present(t_graphics *grph);
void		graphics_draw_pixel(t_graphics *grph, int x, int y, t_color color);
void		graphics_draw_rect(t_graphics *grph, t_rect rect, \
				t_color color, int border_size);
void		graphics_draw_line(t_graphics *grph, t_pixel p0, t_pixel p1);
void		graphics_draw_triangle(t_graphics *grph, t_triangle t);
void		graphics_draw_circle(t_graphics *grph, t_circle c, t_color color);
/* timer
================================================================================
*/
void		timer_init(t_timer *timer);
void		timer_delay(int ms);

/* inputs
================================================================================
*/
void		inputs_bind(t_data *data);

/* timer
================================================================================
*/
int			timer_get_ticks(t_timer *timer);

/* load
================================================================================
*/
bool		load(t_data *data, const char *map_filename);

/* render
================================================================================
*/
void		render(t_data *data);

/* utils
================================================================================
*/
void		*malloc_log(size_t size, char *file, int line);
void		*calloc_log(size_t nmemb, size_t size, char *file, int line);
bool		in_charset(char c, const char *charset);

#endif