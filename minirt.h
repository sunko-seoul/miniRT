/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:14:11 by sunko             #+#    #+#             */
/*   Updated: 2023/12/08 00:11:13 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_parm
{
	t_mlx_data	mlx_data;
}	t_parm;

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_color3
{
	double	r;
	double	g;
	double	b;
}	t_color3;

/* mlx.c  */
void		init_mlx(t_mlx_data *mlx_data);
int			destroy_window(t_mlx_data *mlx_data);
int			handle_key_press(int keycode, t_parm *parm);

/* utils_constructor.c */
t_vec3		gen_vec3(const double x, const double y, const double z);
t_point3	gen_point3(const double x, const double y, const double z);
t_color3	gen_color3(const double r, const double g, const double b);
void		set_vet(t_vec3 *vec, const double x, const double y, const double z);
void		set_color(t_color3 *color, const double r, const double g, const double v);

/* utils_operator.c */
double		get_vec_length2(const t_vec3 vec);
double		get_vec_length(const t_vec3 vec);
t_vec3		get_vec_plus(t_vec3 vec, const t_vec3 vec2);
t_vec3		get_vec_plus_point
	(t_vec3 vec, const double x, const double y, const double z);
t_vec3		get_vec_minus(t_vec3 vec, const t_vec3 vec2);

/* utils_operator2.c */
t_vec3		get_vec_minus_point
	(t_vec3 vec, const double x, const double y, const double z);
t_vec3		get_vec_mul_t(t_vec3 vec, const double t);
t_vec3		get_vec_mul(t_vec3 vec, const t_vec3 vec2);
t_vec3		get_vec_divide(t_vec3 vec, double t);
double		get_vec_dot(t_vec3 vec, t_vec3 vec2);

/* utils_operator3.c */
t_vec3		get_vec_cross(t_vec3 vec, t_vec3 vec2);
t_vec3		get_unit_vec(t_vec3 vec);

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

/* utils_ray.c */
t_ray		gen_ray(t_point3 orig, t_vec3 dir);
t_point3	get_ray_at(t_ray *ray, const double t);

typedef struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	double		focal_len;
	t_point3	left_bottom;
}	t_camera;

typedef struct s_screen
{
	double	width;
	double	height;
	double	aspect;
}	t_screen;

/* utils_camera.c */
t_camera	gen_camera(t_screen *screen, t_point3 orig);
t_screen	get_screen(void);
