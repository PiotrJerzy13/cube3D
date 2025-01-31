/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:src/cube3d.h
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:39:08 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/01/19 13:10:18 by pwojnaro         ###   ########.fr       */
=======
/*   By: kkaratsi <kkaratsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:58:20 by piotrwojnar       #+#    #+#             */
/*   Updated: 2025/01/30 16:51:31 by kkaratsi         ###   ########.fr       */
>>>>>>> 65ac913c6d78f2c2c50a27b7732a73cd95b0ef02:src/Cube3d.h
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
<<<<<<< HEAD:src/cube3d.h
# define CUBE3D_H
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h> 
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define INITIAL_MEM_CAPACITY 10
=======
#define CUBE3D_H
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h> 
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "libft/libft.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#define	WINDOW_WIDTH 1200
#define	WINDOW_HEIGHT 1000
#define INITIAL_MEM_CAPACITY 10
#define FOV 3.14159 / 3

typedef struct s_ray
{
	float side_dist_x;
	float side_dist_y;
	float delta_dist_x;
	float delta_dist_y;
	int map_x;
	int map_y;
	int step_x;
	int step_y;
	int side;
}	t_ray;
>>>>>>> 65ac913c6d78f2c2c50a27b7732a73cd95b0ef02:src/Cube3d.h

typedef struct s_memory
{
	void	**allocated_pointers;
	size_t	count;
	size_t	capacity;
}	t_memory;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_texture;

typedef struct s_color
{
	int	floor[3];
	int	ceiling[3];
	int	wall[3];
}	t_color;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
	float		angle;
}	t_player;

typedef struct s_config t_config;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		fd;
	char	*path;
	int		current_row;
	int		player_n;
	int		wall_n;
	mlx_t	*mlx;
	t_list	*list;
	t_config	*config;
}	t_map;

typedef struct s_resources
{
	mlx_texture_t	**textures;
	int				texture_count;
	mlx_image_t		**images;
	int				image_count;
}	t_resources;

typedef struct s_config
{
	t_texture	textures;
	t_color		colors;
	t_map		map;
	t_player	player;
	t_memory	*memory;
	t_resources	resources;
	bool		use_textures;
}	t_config;

typedef struct s_position
{
	int	row;
	int	col;
}	t_position;

void	ft_error(int code);
void	parse_texture(char *line, t_texture *textures, t_memory *mem);
void	parse_color(char *line, int color[3]);
void	process_line(t_map *map, t_memory *mem, char *line);
void	validate_file_extension(t_map *map);
void	validate_map(t_map *map);
void	validate_map_boundary(t_map *map);
void	validate_textures_and_colors(t_config *config);
void	initialize_player(t_config *config, t_map *map);
bool	validate_args_and_load_map(int argc, char **argv, t_config *config,
			t_memory *mem);
void	mem_free_all(t_memory *mem);
void	*mem_alloc(t_memory *mem, size_t size);
bool	mem_init(t_memory *mem);
void	ft_clean(t_map *map, t_memory *mem, t_resources *res);
void	parse_line(char *line, t_config *config, t_memory *mem,
			bool *is_parsing_map);
void	parse_cub_file(t_config *config, t_memory *mem, char *file_path);

void	initialize_config(t_config *config);
void	initialize_player(t_config *config, t_map *map);
void	initialize_game(t_config *config, t_map *map);
void	cleanup_textures(t_resources *res, mlx_t *mlx);
int		put_on_list(char *line, t_list **list, t_memory *mem);
void	list_to_array(t_map *map, t_memory *mem);
void	cleanup_resources(t_resources *res, mlx_t *mlx);
int		has_valid_extension(const char *path, const char *extension);
char	*ft_strdup_cub(const char *src, t_memory *mem);
void	initialize_config(t_config *config);
void	initialize_player(t_config *config, t_map *map);
void	initialize_game(t_config *config, t_map *map);
void	cleanup_textures(t_resources *res, mlx_t *mlx);
int		put_on_list(char *line, t_list **list, t_memory *mem);

<<<<<<< HEAD:src/cube3d.h
#endif
=======
/* -------------------   kkaratsi functions  ---------------------*/

void	draw_vertical_line(mlx_image_t *img, int x, int drawStart, int drawEnd, uint32_t color);
void	calculate_draw_parameters(int window_height, float perpWallDist, int *lineHeight, int *drawStart, int *drawEnd);
bool	cast_ray(float start_x, float start_y, float angle, int h, int *lineHeight, int *drawStart, int *drawEnd, t_map *map, t_config *config);
void	render_scene(mlx_t *mlx, t_map *map, t_config *config, int window_height);
// void	clear_image(t_config *config, uint32_t color);
void	clear_image(mlx_image_t *img, uint32_t color);
// void	player_move_handler(mlx_key_data_t keydata, t_config *config);
void player_move_handler(mlx_key_data_t keydata, void *param);

#endif
>>>>>>> 65ac913c6d78f2c2c50a27b7732a73cd95b0ef02:src/Cube3d.h
