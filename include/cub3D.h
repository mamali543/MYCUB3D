#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "../mylibft/libft.h"
# include <sys/errno.h>
# include <stdbool.h>
# include <limits.h>
# include "keys.h"
# define TILE_SIZE 64
# define PI 3.14159265
# define TURN_SPEED 0.04
# define WALK_SPEED 10
# define TRUE 1
# define FALSE 0
# define EPSILON 1
# define TEX_HEIGHT 64
# define TEX_WIDTH 64

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
}				t_rgb;

typedef struct s_player
{
	float	x;
	float	y;
	float	radius;
	int		tdirec;
	int		wd;
	float	ra;
	int		mspeed;
	float	rspeed;
	int		fov;
	float	nor;
	float	dir_angle;
}				t_player;

typedef struct s_g_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tile_size;
}				t_img;

typedef struct s_tex
{
	void	*ptr;
	int		*buf;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		dist_ftop;
	int		color;
}				t_tex;

typedef struct s_bmp
{
	unsigned char	header[54];
	unsigned char	zero[3];
	int				size;
	int				padding;
	int				fd;
	int				color;
}				t_bmp;

typedef struct s_ray
{
	int		up;
	int		down;
	int		left;
	int		right;
	float	x_inter;
	float	y_inter;
	float	xstep;
	float	ystep;
	int		horz_hit;
	float	x_hit_horz;
	float	y_hit_horz;
	float	next_horz_x;
	float	next_horz_y;
	int		vert_hit;
	float	x_hit_vert;
	float	y_hit_vert;
	float	next_vert_x;
	float	next_vert_y;
	float	check_x;
	float	check_y;
	float	horz_distance;
	float	vert_distance;
	int		content;
}				t_ray;

typedef struct s_sprite
{
	int		order;
	float	distance;
	double	coord_x;
	double	coord_y;
	void	*g_img_ptr;
	int		*get_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		color;
}				t_sprite;

typedef struct s_cub
{
	t_sprite	*sprite;	
}				t_cub;

typedef struct s_rays
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		up;
	int		down;
	int		left;
	int		right;
	int		was_hit_vert;
}				t_rays;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_data
{
	float		nbr_sprite;
	int			maplwidth;
	int			mapheight;
	int			xR;
	int			yR;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		**map;
	int			ret;
	int			var;
	char		p;
	int			maprow;
	int			mapcol;
	t_mlx		mlx;
	t_tex		g_so;
	t_tex		g_no;
	t_tex		g_ea;
	t_tex		g_we;
	t_tex		g_s;
	t_sprite	g_s_data[100000];
	t_img		g_img;
	t_player	player;
	t_ray		ray;
	t_rays		*g_rays;
	t_cub		*g_cub;
	t_rgb		f;
	t_rgb		c;
}				t_data;

t_data				g_info;

void	ft_puterror(char *error, char	**str);
void	ft_readfile(char **argv, int i);
void	ft_checkargs(int argc, char **argv);
int		ft_checksa(char *argv);
void	ft_checkeof(char *argv);
void	ft_checkan(int argc);
void	bmp(void);
void	ft_draw_sprites(void);
void	ft_checkline(char *line);
int		ft_lineisdigit(char **str);
void	ft_getpaths(char *line);
void	ft_getcolors(char *line);
void	ft_getspath(char *line, char **str, int j);
char	**getMap(char *line);
char	**ft_realloc(char **s, char *p, int i, int len);
int		tablen(char **s);
void	ft_checkmap(char **s, int i, int j);
void	ft_initf(void);
float	distance1(float x1, float y1, float x2, float y2);
void	render_spt(int x, int y, int sp_size, int k);
void	ft_sprite(int i);
void	ft_sort_sprites(void);
int		key_release_hook(int keycode);
int		key_press_hook(int keycode);
void	game_init(void);
void	mlx_struct_init(void);
void	draw_player(int x0, int y0, int radius);
void	put_pixel(int x, int y, int color);
int		has_wall_at(float x, float y);
void	cast_vert(float ray_angle);
void	cast_horz(float ray_angle);
void	store_rays(int strip_id, float ray_angle);
void	init_rays(void);
int		has_wall_at_s(float x, float y);
void	schline(int i, char *line, int j);
void	ft_inits(void);
void	ft_initplayer(void);
float	normalize_angle(float angle);
void	render3d(int i, float ray, float correctwdis, float disproplane);
int		quit(void);
int		keypressed(int key);
int		keyreleased(int key);
void	draw_square(int width, int height, int x, int y);
void	draw_map(void);
float	distance(float x1, float y1, float x2, float y2);
void	plombier(int strip_id, float ray_angle);
void	init_texture(void);
void	init_texture2(void);
void	free_str_array(char **str);
void	clean_up(void);

#endif
