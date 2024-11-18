// #include "cub3d.h"


// // Function to fill the entire image with a color (clear the screen)
// void put_color(t_data *data, uint32_t color)
// {
//     int i, j;
//     for (i = 0; i < WIDTH; i++)
//     {
//         for (j = 0; j < HEIGHT; j++)
//         {
//             *(uint32_t *)(data->img->pixels + (j * WIDTH + i) * sizeof(uint32_t)) = color;
//         }
//     }
// }

// // Function to draw a filled rectangle (player)
// // void mlx_rectangle(t_data *data, int color)
// // {
// //     int i, j;

// //     // Loop through the pixels in the rectangle's area
// //     for (i = data->player_x; i < data->player_x + PLAYER_SIZE; i++)
// //     {
// //         for (j = data->player_y; j < data->player_y + PLAYER_SIZE; j++)
// //         {
// //             if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT)
// //             {
// //                 *(uint32_t *)(data->img->pixels + (j * WIDTH + i) * sizeof(uint32_t)) = color;
// //             }
// //         }
// //     }
// // }
// void draw_player(mlx_image_t *img, int x, int y, int size, uint32_t color) {
//     for (int i = -size / 2; i < size / 2; i++) {
//         for (int j = -size / 2; j < size / 2; j++) {
//             mlx_put_pixel(img, x + i, y + j, color);
//         }
//     }
// }

// // Key press event handler
// // void key_hook(mlx_key_data_t keydata, void *param)
// // {
// //     t_data *data = (t_data *)param;

// //     // Exit on ESC key
// //     if (keydata.key == MLX_KEY_ESCAPE)
// //     {
// //         mlx_close_window(data->mlx);
// //         printf("Exiting...\n");
// //     }

// //     // Move player based on arrow keys
// //     if (keydata.key == MLX_KEY_LEFT)
// //         data->player_x -= 10;
// //     if (keydata.key == MLX_KEY_RIGHT)
// //         data->player_x += 10;
// //     if (keydata.key == MLX_KEY_UP)
// //         data->player_y -= 10;
// //     if (keydata.key == MLX_KEY_DOWN)
// //         data->player_y += 10;

// //     // Clear the screen with a grey color
// //     put_color(data, 0x808080); // Grey background

// //     // Draw the player rectangle (red square)
// //     mlx_rectangle(data, 0xFF0000); // Red color for the player

// //     // Display the updated image to the window
// //     mlx_image_to_window(data->mlx, data->img, 0, 0);
// // }
// void key_hook(mlx_key_data_t keydata, void* param)
//  {
//     t_data *data = (t_data *)param;

//     // Move player based on key pressed (WASD keys)
//     if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT) 
//     {
//         if (keydata.key == MLX_KEY_W && data->player_y - MOVE_STEP >= 0)
//             data->player_y -= MOVE_STEP;
//         else if (keydata.key == MLX_KEY_S && data->player_y + MOVE_STEP < HEIGHT)
//             data->player_y += MOVE_STEP;
//         else if (keydata.key == MLX_KEY_A && data->player_x - MOVE_STEP >= 0)
//             data->player_x -= MOVE_STEP;
//         else if (keydata.key == MLX_KEY_D && data->player_x + MOVE_STEP < WIDTH)
//             data->player_x += MOVE_STEP;

//         // Clear the background and redraw the player at new position
//         put_color(data, 0x808080);
//         draw_player(data->img, data->player_x, data->player_y, PLAYER_SIZE, PLAYER_COLOR);
//     }
// }

// int main()
// {
//     t_data data;

//     // Initialize mlx42
//     data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", 0);
//     if (!data.mlx)
//         return (EXIT_FAILURE);

//     // Create the image for the window
//     data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
//     if (!data.img)
//         return (EXIT_FAILURE);

//     // Initialize player position at the center of the screen
//     data.player_x = WIDTH / 2 - PLAYER_SIZE / 2;
//     data.player_y = HEIGHT / 2 - PLAYER_SIZE / 2;

//     // Set a grey background
//     put_color(&data, 0x808080); // Grey color for background

//     // Draw the player rectangle (red square) at the starting position
//     draw_player(data.img,data.player_x, data.player_y, PLAYER_SIZE, PLAYER_COLOR); // Red color for the player

//     // Display the background and player in the window
//     mlx_image_to_window(data.mlx, data.img, 0, 0);

//     // Register the key press event handler
//     mlx_key_hook(data.mlx, key_hook, &data);

//     // Start the event loop
//     mlx_loop(data.mlx);

//     return (EXIT_SUCCESS);
// }

// // void	put_color(t_data *data)
// // {
// // 	int i =0;
// // 	int j = 0;
// // 	while(i < WIDTH)
// // 	{
// // 		j = 0;
// // 		while(j < HEIGHT)
// // 		{
// // 			*(uint32_t *)(data->img->pixels + (j * WIDTH + i) * sizeof(uint32_t)) = 0x808080;
// // 			// mlx_put_pixel(data->img, i , j,0x00FF0000);
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // }
// // void	mlx_rectangle(t_data *data, int color)
// // {
// // 	int i = data->player_x;
// // 	int j = data->player_y;
// // 	while(i < PLAYER_SIZE + data->player_x)
// // 	{
// // 		j = data->player_y;
// // 		while(j < PLAYER_SIZE + data->player_y)
// // 		{
// // 			if (i >= 0 && i < PLAYER_SIZE  && j >= 0 && j < PLAYER_SIZE)
// //             {
// //                 // Set the pixel color at (i, j) to the specified color
// //                 *(uint32_t *)(data->img->pixels + (j * WIDTH + i) * sizeof(uint32_t)) = color;
// //             }
// // 			j++;
// // 		}
// // 		i++;
// // 	}
// // }
// // void key_hook(mlx_key_data_t keydata, void *param)
// // {
// //     t_data *data = (t_data *)param;

// //     // Exit on ESC key
// //     if (keydata.key == MLX_KEY_ESCAPE)
	
// // 	{
// //         mlx_close_window(data->mlx);
// // 		printf("sssssss\n");                                                    
// // 	}
// //     // Move player based on arrow keys
// //     if (keydata.key == MLX_KEY_LEFT)
// //         data->player_x -= 10;
// //     if (keydata.key == MLX_KEY_RIGHT)
// //         data->player_x += 10;
// //     if (keydata.key == MLX_KEY_UP)
// //         data->player_y -= 10;
// //     if (keydata.key == MLX_KEY_DOWN)
// //         data->player_y += 10;

// //     // Clear the screen (fill with grey)
// // 	sput_color(data);
// //     mlx_rectangle(data, 0xFF0000);
// //     mlx_image_to_window(data->mlx, data->img, 0, 0);

// //     return ;
// // }

// // int main()
// // {
// // 	t_data data;
// // 	data.mlx = mlx_init(WIDTH, HEIGHT,  "cub3d",  0);
// // 	data.img = mlx_new_image(data.mlx,  WIDTH, HEIGHT);
// // 	data.player_x = WIDTH / 2 - 25;
// //     data.player_y = HEIGHT / 2 - 25;
// // 	put_color(&data);
// // 	mlx_rectangle(&data,  0xFF0000);
// // 	mlx_image_to_window(data.mlx, data.img, 0, 0);
// //     mlx_loop(data.mlx);
// // 	mlx_key_hook(data.mlx, key_hook, &data);
// //     return (EXIT_SUCCESS);
// // }
#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

// void init(void)
// {
// 	int x, y, radius, turndirection, walkdirection;
// 	turndirection = 0;
// 	walkdirection = 0;
// 	double rotationangle = M_PI_2;
// 	double move_speed = 3.0;
// 	double rotation_speed = 3 * (M_PI / 180);
// }

// int map[16][16] = 
// {
//         {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//         {1,0,0,0,1,0,0,1,0,0,0,0,0,1},
//         {1,0,0,0,1,0,0,1,0,0,0,0,0,1},
//         {1,0,W,0,1,0,0,1},
//         {1,0,0,0,0,0,0,1},
//         {1,0,1,1,1,0,0,1},
//         {1,0,0,0,0,0,0,1},
//         {1,1,1,1,1,1,1,1}
// };
int map[16][16] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 2, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
// Function to fill the background with a gray color
void fill_background(mlx_image_t *img, uint32_t color) 
{
    for (int y = 0; y < HEIGHT; y++) 
    {
        for (int x = 0; x < WIDTH; x++) 
        {
            mlx_put_pixel(img, x, y, color);
        }
    }
}
void draw_map(mlx_image_t *img) 
{
    for (int row = 0; row < (HEIGHT ) / TILE_SIZE; row++) 
	{
        for (int col = 0; col < (WIDTH / 2) / TILE_SIZE; col++) 
		{
            uint32_t tile_color = GRAY;
            if (map[row][col] == 1) 
			{
                tile_color = 0x00FF00;  // Green for walls
            }
            // Draw a tile (just a rectangle)
            for (int i = 0; i < TILE_SIZE; i++) 
			{
                for (int j = 0; j < TILE_SIZE; j++) 
				{
                    mlx_put_pixel(img, col * TILE_SIZE + i, row * TILE_SIZE + j, tile_color);
                }
            }
        }
    }
}

void draw_player(mlx_image_t *img, int x, int y, int size, uint32_t color, float angle) 
{
    float rad = angle * M_PI / 180.0; // Convert angle to radians
    float cos_a = cos(rad);
    float sin_a = sin(rad);

    for (int i = -size / 2; i < size / 2; i++) {
        for (int j = -size / 2; j < size / 2; j++) {
            int rotated_x = x + (i * cos_a - j * sin_a);
            int rotated_y = y + (i * sin_a + j * cos_a);
            mlx_put_pixel(img, rotated_x, rotated_y, color);
        }
    }

    int line_length = size * 2; // Length of the line

    for (int i = 0; i < line_length; i++) {
        int rotated_x = x + (size / 2 + i) * cos_a;
        int rotated_y = y + (size / 2 + i) * sin_a;
        mlx_put_pixel(img, rotated_x, rotated_y, color); // Draw each pixel of the line
    }
}
// Function to draw a player (as a small square) at a specific position
// void draw_player(mlx_image_t *img, int x, int y, int size, uint32_t color) 
// {
//     // for (int i = -size / 2; i < size / 2; i++) {
//     //     for (int j = -size / 2; j < size / 2; j++) {
//     //         mlx_put_pixel(img, x + i, y + j, color);
//     //     }
//     // }
// 	// printf("ercercer\n");
// 	for (int i = -size / 2; i < size / 2; i++) {
//         for (int j = -size / 2; j < size / 2; j++) {
//             mlx_put_pixel(img, x + i, y + j, color);
//         }
//     }


	
// int line_length = size * 2; // Length of the line

// for (int i = 0; i < line_length; i++) {
//     mlx_put_pixel(img, x + size / 2  + i, y , color); // Draw each pixel of the line
// }
// }
void find_player_position(t_data *data) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (map[i][j] == 2) { // Assuming '2' is used to mark the player's position
                data->player_x = j * TILE_SIZE + TILE_SIZE / 2;
                data->player_y = i * TILE_SIZE + TILE_SIZE / 2;
                return;
            }
        }
    }
}

// Function to handle player movement
void key_hook(void* param) 
{
    t_data *data = (t_data*)param;
    int map_col = 0;
    int map_row = 0;

    bool can_move;
    int new_x = data->player_x;
    int new_y = data->player_y;
    int i, j;

    // Escape key handling
    if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
        	mlx_close_window(data->mlx);          
    // Handle key presses for movement
        // if (mlx_is_key_down(data->mlx, MLX_KEY_W)){
		// 	float rad = data->angle * M_PI / 180.0; // Convert angle to radians
        // new_x += MOVE_STEP * cos(rad);
        // new_y -= MOVE_STEP * sin(rad);
		// }
		// else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		// 	data->angle += 5;
		// else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		// 	data->angle -= 5;
        // else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
        //     new_y += MOVE_STEP;
        // else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
        //     new_x -= MOVE_STEP;
        // else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
        //     new_x += MOVE_STEP;
        float rad;
		if (mlx_is_key_down(data->mlx, MLX_KEY_W)) {
        rad = data->angle * M_PI / 180.0; // Convert angle to radians
    	float cos_a = cos(rad);
    	float sin_a = sin(rad);
        
        // Move player forward in the direction of the current angle
        new_x += cos_a * 2;  // Add for X-axis
        new_y += sin_a * 2;  // Subtract for Y-axis since screen Y-axis increases downward
    }
    else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)) {
        data->angle += 5;
		// if (data->angle > 2 * PI)
        //     data->angle -= 2 * PI;  // Rotate clockwise (increase angle)
        // if (data->angle >= 360) data->angle -= 360;  // Normalize angle
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)) {
		// if (data->angle < 0)
        //     data->angle += 360;
        data->angle -= 5; 
        // if (data->angle < 0)
        //     data->angle += 2 * PI; // Rotate counterclockwise (decrease angle)
        // if (data->angle < 0) data->angle += 360;  // Normalize angle
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_S)) {
        // Move player backward (opposite of forward)
		rad = data->angle * M_PI / 180.0 ;
        new_x -= MOVE_STEP * cos(rad );  // Move backward along X-axis
        new_y -= MOVE_STEP * sin(rad );  // Move backward along Y-axis
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_A)) {

		// if(data->angle >= 45 && data->angle <= 135)
		// 	rad = (data->angle + 45) * M_PI / 180.0 ;
		// else
		rad = (data->angle - 45) * M_PI / 180.0 ;

		// float strafe_angle = rad - M_PI / 2;
        // Strafing left (no rotatin, just move sideways)
        new_x += MOVE_STEP * cos(rad) ;  // Move left in the X direction
		printf("angle = %f\n", rad);
		// printf("angle = %f\n", M_PI / 4);

    	new_y -= MOVE_STEP * cos(rad) ; 
    }
    if (mlx_is_key_down(data->mlx, MLX_KEY_D)) {
        // Strafing right (no rotation, just move sideways)
        
    }
        can_move = true;

        // Check if the new position is within the bounds of the map
        i = 0;
        while(i < PLAYER_SIZE) 
        {
            j = 0;
            while(j < PLAYER_SIZE) 
            {
                map_row = (new_y - 5 + i) / TILE_SIZE;
                map_col = (new_x - 5 + j) / TILE_SIZE;

                // Ensure map indices are within valid bounds
                if (map_row >= 0 && map_row < 16 && map_col >= 0 && map_col < 16) 
                {
                    // Check if there is a wall at the new position
                    if (map[map_row][map_col] == 1) 
                    {
                        can_move = false;
                        break;
                    }
                }
                j++;
            }
            i++;
        }

        // If movement is possible, update the player's position
        if(can_move) {
            data->player_x = new_x;
            data->player_y = new_y;
        }

        // Update the image only if valid
		fill_background(data->img, GRAY);
		draw_map(data->img);
		draw_player(data->img, data->player_x, data->player_y, PLAYER_SIZE, YELLOWW, data->angle);
}

int main() {
    // Initialize MLX42 and create a window
	t_data *data = malloc(sizeof(t_data ));
	memset(data, 0, sizeof(t_data));
		data->angle = 0;
	if(!data)
	{
		printf("Error\n");
		return (1);
	}
	// data = NULL;
	data->player_x = 0;
	data->player_y = 0;

    data->mlx = mlx_init(WIDTH, HEIGHT, "Gray Window with Player", true);
    if (!data->mlx) {
        fprintf(stderr, "Error initializing MLX42\n");
        return EXIT_FAILURE;
    }
    // Create an image to draw on
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img) {
        fprintf(stderr, "Error creating image\n");
        mlx_terminate(data->mlx);
        return EXIT_FAILURE;
    }
   if(mlx_image_to_window(data->mlx, data->img,0 ,0) < 0)
    {
        mlx_delete_image(data->mlx, data->img);
        mlx_terminate(data->mlx);
        free(data);
        return (1);
    }

    // Call find_player_position to set initial player coordinates
    find_player_position(data);
    // fill_background(data->img, GRAY);
    // draw_map(data->img);
    
    // Fill background and draw player
    // fill_background(data->img, GRAY);
    // draw_map(data->img);  // Ensure map is properly initialized
    // draw_player(data->img, data->player_x, data->player_y, 10, PLAYER_COLOR);

    // Put the image onto the window
    // mlx_image_to_window(data->mlx, data->img, 0, 0);

            
    // Set the key_hook callback to handle key events
	printf("crcvrtv\n");
    mlx_loop_hook(data->mlx, key_hook, data);
    // mlx_key_hook(data->mlx, key_hook, &data);
    // Start the event loop
	// exit(0);
    mlx_loop(data->mlx);


    return EXIT_SUCCESS;
}

// int main() {
//     // Initialize MLX42 and create a window
//     mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Gray Window with Player", true);
//     if (!mlx) {
//         fprintf(stderr, "Error initializing MLX42\n");
//         return EXIT_FAILURE;
//     }

//     // Create an image to draw on
//     mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
//     if (!img) {
//         fprintf(stderr, "Error creating image\n");
//         mlx_terminate(mlx);
//         return EXIT_FAILURE;
//     }

//     // Initialize player position at the center

//     t_data data;
	
// 	data.img = img;
//     // Fill background and draw player
// 	find_player_position(&data);
//     fill_background(img, GRAY);
// 	draw_map(data.img);
//     draw_player(img, data.player_x, data.player_y, 10, PLAYER_COLOR);

//     // Put the image onto the window
//     mlx_image_to_window(mlx, img, 0, 0);
//     mlx_key_hook(mlx, key_hook, &data);

//     // Start the event loop
//     mlx_loop(mlx);

//     // Cleanup
//     mlx_delete_image(mlx, img);
//     mlx_terminate(mlx);
//     return EXIT_SUCCESS;
// }