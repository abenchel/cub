/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenchel <abenchel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:25:42 by wait-bab          #+#    #+#             */
/*   Updated: 2024/11/16 08:42:26 by abenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./MLX42/include/MLX42/MLX42.h"
// # include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

# define WIDTH 1024
# define HEIGHT 512
# define PI 3.1415926535
# define P1 PI/2
# define P2 3*PI/2
# define DR 0.0174533
#define GRAY 0x808080
#define YELLOWW 0xFFFF00  // Gray color (128, 128, 128 in RGB)
#define PLAYER_COLOR 0xFF0000  // Red color for the player
#define PLAYER_SIZE 10
#define MOVE_STEP  1
#define TILE_SIZE 32 
typedef struct s_data
{
	mlx_t *mlx;
	mlx_image_t *img;
	int player_x;
    int player_y;
	double angle;
}t_data;


// void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color);
// int draw_plyr(mlx_image_t *img, int x, int y, float angle);

#endif
