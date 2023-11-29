/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:11:49 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 06:34:29 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* Color */
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>

typedef uint32_t	t_color;

# define COLOR_BG 0x1A1A1A
# define COLOR_PROP_BG 0x1F1F1F
# define COLOR_WHITE 0xffffff

/* Core */
enum {proj_iso, proj_ortho};

typedef struct s_conf {
	int		window_width;
	int		window_height;
	char	*window_title;
	int		vp_width;
	int		prop_width;
	int		fps;
	float	sf;
	int		col[9];
	int		proj;
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
	t_mlx_image	*front;
	t_mlx_image	*back;
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
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		error;
	int		e2;
	int		x0_cpy;
}	t_bla;

typedef struct s_rect {
	int	x;
	int	y;
	int	width;
	int	height;
}	t_rect;

/* Mesh */
typedef struct s_mesh {
	int		width;
	int		height;
	t_vec3	**vertices;
	t_vec3	s;
	t_vec3	r;
	t_vec3	t;
	float	z_min;
	float	z_max;
}	t_mesh;

/* Parse */
// size (in KB) of the buffer to store file content
# define PARSE_FILE_SIZE 15000

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

/* Input */
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

enum {palette_1, palette_2, palette_3};

typedef struct s_inputs {
	bool	toggle_r;
	int		last_x_r;
	int		last_y_r;
	bool	toggle_l;
	int		last_x_l;
	int		last_y_l;
}	t_inputs;

/* Data */
typedef struct s_data {
	t_conf		*conf;
	t_graphics	*grph;
	t_timer		*timer;
	t_mesh		*mesh;
	t_mat4		transform;
	t_inputs	*inputs;
	char		**strs;
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
void	conf_load_palette(t_data *data, int palette);
int		graphics_init(t_data *data);
void	graphics_destroy(t_data *data);
void	graphics_clear(t_data *data, t_color color);
void	graphics_present(t_data *data);
void	render(t_data *data);
void	update(t_data *data);
int		run(t_data *data, const char *filename);
void	terminate(t_data *data);

/* Inputs */
int		inputs_init(t_data *data);
void	inputs_destroy(t_data *data);
int		inputs_process_keypress(int keycode, t_data *data);
int		inputs_process_structure(t_data *data);
int		inputs_process_mpress(int keycode, int x, int y, t_data *data);
int		inputs_process_mrelease(int keycode, int x, int y, t_data *data);

/* Color */
t_color	color_distribute_z(t_data *data, float z);
t_color	color_lerp(t_color c0, t_color c1, float param);

/* Maths */
float	absf(float x);
int		absi(int x);
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

/* Draw */
void	draw_pixel(t_data *data, int x, int y, t_color c);
void	draw_line(t_data *data, t_line line);
void	draw_rect(t_data *data, t_rect rect, t_color c);
void	draw_text(t_data *data, int x, int y, char *str);

/* Mesh */
int		mesh_init(t_data *data, const char *filename);
int		mesh_vertices_alloc(t_mesh *mesh);
void	mesh_destroy(t_data *data);
void	mesh_reset_transforms(t_data *data);

/* Parse */
int		parse(t_mesh *mesh, const char *filename);

/* UI */
void	render_ui(t_data *data);
void	render_ui_text(t_data *data);

#endif