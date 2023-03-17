// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../include/MLX42/MLX42.h"
#include "../include/so_long.h"
#define WIDTH 640
#define HEIGHT 640

static mlx_image_t* img;

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

int	main(int ac, char **av)
{
	mlx_t*	mlx;
	t_game	game;

	check_arguments(ac, av, &game);
	get_map(game.map_arg);
	game.h = (game.map.h) * 32;
	game.w = (game.map.w - 1) * 32;
	check_path(&game, game.map_arg);

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return(EXIT_FAILURE);

	// Try to load the file
	xpm_t* xpm = mlx_load_xpm42("./sprites/player/tile000.xpm42");
	if (!xpm)
		error();

	img = mlx_new_image(mlx, 128, 128);

	// Convert texture to a displayable image
	img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();

//	default white square - setting each pixel to 255
//	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 320, 320);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}

