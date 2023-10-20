/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:11:13 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/20 13:34:30 by liguyon          ###   ########.fr       */
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

/* Config
================================================================================
*/
# define CONF_WINDOW_WIDTH 1600
# define CONF_WINDOW_HEIGHT 900
# define CONF_WINDOW_TITLE "fdf"
# define CONF_FPS 60
# define CONF_TILE_SIZE 64
# define CONF_COLOR_BG 0x26232B
# define CONF_ARENA_SIZE 1e8

/* map
================================================================================
*/
# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_LOOT 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
	int		objectives;
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

typedef struct s_rect {
	int		x;
	int		y;
	int		width;
	int		height;
}	t_rect;

/* timer
================================================================================
*/

typedef struct s_timer {
	long	time_start;
}	t_timer;

/* sprite
================================================================================
*/

# define ATLAS_TILES 4
# define ATLAS_COUNT 6

typedef struct s_atlas {
	int	*raster;
	int	tile_size;
	int	width;
	int	height;
}	t_atlas;

typedef struct s_sprite {
	t_atlas	*atlas;
	int		atlas_x;
	int		atlas_y;
	int		atlas_w;
	int		atlas_h;
	int		scale;
}	t_sprite;

/* entity (rigid body)
================================================================================
*/

enum {
	TYPE_PLAYER,
	TYPE_ENNEMY,
	TYPE_LOOT
};

enum {
	STATE_STANDING,
	STATE_WALKING,
	STATE_FIGHTING,
	STATE_DIYING,
};

typedef struct s_entity {
	int		type;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		state;
	int		state_anim;
}	t_entity;

/* data
================================================================================
*/
typedef struct s_data {
	void		*arena;
	t_map		*map;
	t_graphics	*grph;
	t_timer		*timer;
	t_entity	*player;
	t_atlas		**atlases;
	int			mvts;
}	t_data;

/*
================================================================================
								functions
================================================================================
*/

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
void		graphics_draw_rect(t_graphics *grph, t_rect rect, t_color color);

/* timer
================================================================================
*/

void		timer_init(t_timer *timer);
void		timer_delay(int ms);
/* inputs
================================================================================
*/
void		inputs_bind(t_data *data);

/* sprite
================================================================================
*/
t_atlas		*atlas_load(t_data *data, char *filename);
void		sprite_render(t_data *data, t_sprite *sprite, int x, int y);
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