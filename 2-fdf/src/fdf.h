/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:11:49 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 17:08:29 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* Color */
# include <stdint.h>
# include <stdlib.h>

typedef uint32_t	t_color;

# define COLOR_BG 0x000000
# define COLOR_WHITE 0xffffff
# define COLOR_BLACK 0x000000
# define COLOR_RED 0xff0000
# define COLOR_GREEN 0x00ff00
# define COLOR_BLUE 0x0000ff
# define COLOR_YELLOW 0xffff00
# define COLOR_CYAN 0x00ffff
# define COLOR_MAGENTA 0xff00ff

/* Core */
typedef struct s_conf {
	int		window_width;
	int		window_height;
	char	*window_title;
	int		fps;
}	t_conf;

typedef struct s_mlx_image {
	void	*ptr;
	t_color	*raster;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_mlx_image;

typedef struct s_graphics {
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_image	*front_buffer;
	t_mlx_image	*back_buffer;
}	t_graphics;

/* Timer */
typedef struct s_timer {
	long	time_start;
}	t_timer;

/* Maths */
typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec4 {
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

typedef struct s_mat4 {
	float	m[4][4];
}	t_mat4;

enum {proj_iso, proj_ortho};

/* Geometry */
typedef struct s_line {
	int		x0;
	int		y0;
	t_color	c0;
	int		x1;
	int		y1;
	t_color	c1;
}	t_line;

typedef struct s_bla {
	float	dx;
	float	sx;
	float	dy;
	float	sy;
	float	error;
}	t_bla;

/* Mesh */
typedef struct s_mesh {
	int		width;
	int		height;
	t_vec3	**vertices;
	t_vec3	scale;
	t_vec3	rotation;
	t_vec3	translation;
}	t_mesh;

/* Parse */
// size (in KB) of the buffer to store file content
# define PARSE_FILE_SIZE 5000

// number of bytes read by read()
# define PARSE_READ_SIZE 8192

enum {word_outside, word_inside};

typedef struct s_stream {
	int		fd;
	int		rd;
	char	*ptr;
	char	*buf[PARSE_READ_SIZE];
	int		ret;
}	t_stream;

typedef struct s_data {
	t_conf		*conf;
	t_graphics	*grph;
	t_timer		*timer;
	t_mesh		*mesh;
	t_mat4		transform;
}	t_data;

/*
================================================================================
	functions
================================================================================
*/

/* Utils */
void	*calloc_log(size_t nmemb, size_t size);

/* Timer */
void	timer_delay(int ms);
int		timer_get_ticks(t_timer *timer);
int		timer_init(t_data *data);
void	timer_destroy(t_data *data);

/* Core */
int		conf_init(t_data *data);
void	conf_destroy(t_data *data);
int		graphics_init(t_data *data);
void	graphics_destroy(t_data *data);
void	graphics_clear(t_data *data, t_color color);
void	graphics_present(t_data *data);
void	render(t_data *data);
int		run(t_data *data);
void	terminate(t_data *data);

/* Inputs */
void	inputs_bind(t_data *data);

/* Color */
t_color	color_apply_intensity(t_color col, float k);

/* Maths */
float	absf(float x);
float	radf(float angle);
t_vec3	vec3_add(t_vec3 v, t_vec3 w);
t_vec3	vec3_sub(t_vec3 v, t_vec3 w);
t_vec3	vec3_scale(t_vec3 v, float scalar);
float	vec3_magnitude(t_vec3 v);
void	vec3_normalize(t_vec3 *v);
t_vec4	vec4_create_from_vec3(t_vec3 v);
t_mat4	mat4_create_identity(void);
t_mat4	mat4_mul(t_mat4 a, t_mat4 b);
t_vec4	mat4_mul_vec4(t_mat4 m, t_vec4 v);
t_mat4	mat4_create_scale(t_vec3 scale);
t_mat4	mat4_create_rotation_x(float angle);
t_mat4	mat4_create_rotation_y(float angle);
t_mat4	mat4_create_rotation_z(float angle);
t_mat4	mat4_create_translation(t_vec3 translation);
t_mat4	mat4_create_projection(int proj);


/* Draw */
void	draw_pixel(t_data *data, int x, int y, t_color c);
void	draw_line(t_data *data, t_line line);

/* Mesh */
int		mesh_init(t_data *data, const char *filename);
int		mesh_vertices_alloc(t_mesh *mesh);
void	mesh_destroy(t_data *data);

/* Parse */
int		parse(t_mesh *mesh, const char *filename);

#endif