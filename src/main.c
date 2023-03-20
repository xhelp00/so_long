// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "../include/so_long.h"

//static mlx_image_t* img;

/* static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
} */



int	main(int ac, char **av)
{
//	mlx_t*	mlx;
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_arguments(ac, av, game); //init game at first - add structs for player etc, malloc and ending/free functions

	game->map = get_map(game->map_arg, game); //consider changing type
	game->h = (game->map.h) * 32;
	game->w = (game->map.w) * 32;
	check_path(game, game->map_arg);
	//load_game(game); tbd
	game->grid = game->map.grid;
	if (!(game->mlx = mlx_init(game->w, game->h, "So Long!", true)))
		return(EXIT_FAILURE);
	init_idle_texture(game); //must go only after mlx_init otherwise SIGSEGV
	init_tile_textures(game);

	draw_tiles(game);
	// Try to load the file
	//xpm_t* xpm = mlx_load_xpm42("./sprites/player/tile000.xpm42");
	//if (!xpm)
	//	error();

	//img = mlx_new_image(game->mlx, 128, 128);
	
	// Convert texture to a displayable image
	//img = mlx_texture_to_image(game->mlx, &xpm->texture);
	//if (!img)
	//	error();
	
//	default white square - setting each pixel to 255
//	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	
	//ft_memset((game)->img->pixels, 255, game->w * game->h * 4);
	//mlx_image_to_window((game)->mlx, (game)->img, 0, 0);

	mlx_image_to_window(game->mlx, game->idle->idle, 32, 32);
	//idle_animation(game); segfaults here
	mlx_loop_hook(game->mlx, idle_animation, game);
	mlx_loop_hook(game->mlx, hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}

