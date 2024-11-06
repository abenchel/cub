/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenchel <abenchel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:25:42 by wait-bab          #+#    #+#             */
/*   Updated: 2024/10/31 16:08:29 by abenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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


void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color);
// int draw_plyr(mlx_image_t *img, int x, int y, float angle);

#endif
