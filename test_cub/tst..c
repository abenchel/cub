#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#define GRAY 0x808080  // Gray color (128, 128, 128 in RGB)
#define PLAYER_COLOR 0xFF0000  // Red color for the player
#define PLAYER_SIZE 20
#define MOVE_STEP  10



typedef struct {
    mlx_image_t *img;  // MLX42 image
    int player_x;
    int player_y;
} t_vars;

// Function to fill the background with a gray color
void fill_background(mlx_image_t *img, uint32_t color) 
{
    for (int y = 0; y < img->height; y++) 
    {
        for (int x = 0; x < img->width; x++) 
        {
            mlx_put_pixel(img, x, y, color);
        }
    }
}

// Function to draw a player (as a small square) at a specific position
void draw_player(mlx_image_t *img, int x, int y, int size, uint32_t color) {
    for (int i = -size / 2; i < size / 2; i++) {
        for (int j = -size / 2; j < size / 2; j++) {
            mlx_put_pixel(img, x + i, y + j, color);
        }
    }
}
void key_hook(mlx_key_data_t keydata, void* param)
 {
    t_vars *vars = (t_vars*)param;

    // Move player based on key pressed (WASD keys)
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) 
    {
        if (keydata.key == MLX_KEY_W && vars->player_y - MOVE_STEP >= 0)
            vars->player_y -= MOVE_STEP;
        else if (keydata.key == MLX_KEY_S && vars->player_y + MOVE_STEP < HEIGHT)
            vars->player_y += MOVE_STEP;
        else if (keydata.key == MLX_KEY_A && vars->player_x - MOVE_STEP >= 0)
            vars->player_x -= MOVE_STEP;
        else if (keydata.key == MLX_KEY_D && vars->player_x + MOVE_STEP < WIDTH)
            vars->player_x += MOVE_STEP;
        
        // Clear the background and redraw the player at new position
        fill_background(vars->img, GRAY);
        draw_player(vars->img, vars->player_x, vars->player_y, PLAYER_SIZE, PLAYER_COLOR);
    }
 }
int main() {
    // Initialize MLX42 and create a window
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Gray Window with Player", true);
    if (!mlx) {
        fprintf(stderr, "Error initializing MLX42\n");
        return EXIT_FAILURE;
    }

    // Create an image to draw on
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img) {
        fprintf(stderr, "Error creating image\n");
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

    // Initialize player position at the center

    t_vars vars = {
        .img = img,
        .player_x = WIDTH / 2,
        .player_y = HEIGHT / 2,
    };
    // Fill background and draw player
    fill_background(img, GRAY);
    draw_player(img, vars.player_x, vars.player_y, 20, PLAYER_COLOR);

    // Put the image onto the window
    mlx_image_to_window(mlx, img, 0, 0);
    mlx_key_hook(mlx, key_hook, &vars);

    // Start the event loop
    mlx_loop(mlx);

    // Cleanup
    mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
