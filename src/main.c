/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 12:55:56 by oouklich          #+#    #+#             */
/*   Updated: 2020/05/29 14:14:23 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

static int	print_usage(char *prog) {
	printf("usage:  %s [server_IP_address]\n", prog);
	printf("	check server_info.txt file for ip address value\n");
	return (1);
}

static void	init(t_game *game) {
	initScore(game);
	initGraphics(game);
#ifdef __APPLE__
	initSounds(game);
#endif
	initNetworking(game);
}

static void	shifumi(t_game *game) {
	displayFrame(game);
	mlx_key_hook(game->win, keyHandler, game);
	mlx_mouse_hook(game->win, mousePos, game);
	mlx_hook(game->win, 17, (1L << 17), closeGame, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, mouseMove, 0);
	mlx_loop(game->mlx);
}

static void	quit(t_game *game) {
	closeGame(game);
}

int		main(int argc, char **argv) {
	t_game	game;

	if (argc != 2 && print_usage(argv[0]))
		return (EXIT_FAILURE);
	game.server_address = argv[1];
	
	init(&game);

	shifumi(&game);

	quit(&game);

	return (EXIT_SUCCESS);
}
