/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:31:47 by oouklich          #+#    #+#             */
/*   Updated: 2020/05/29 19:58:48 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include <mx_sdl.h>
# include <libft.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h> /* close */
# include <netdb.h> /* gethostbyname */

# if defined(__APPLE__)
#  include <key_macos.h>
# else
#  include <key_linux.h>
# endif

# define MAX(x, y) (x > y ? x : y)

# define WIN_WIDTH 1024
# define WIN_HEIGHT 679
# define GAME_TITLE "Shi Fu Mi"

# define MotionNotify 6
# define PointerMotionMask (1L<<6)


# define PORT 1977
# define PORT_STR "1977"
# define BUF_SIZE 50
# define LECTURE 0
# define ECRITURE 1

# define ON_SELECT 0
# define ON_WIN 1
# define ON_LOSE 2

# define FRAME_START 0
# define FRAME_PLAY 1

enum			e_select
{
	S_NONE = 0,
	S_ROCK = 1,
	S_PAPER = 2,
	S_SCISSORS = 3
};

enum			e_result
{
	R_EQ = 0,
	R_WIN = 1,
	R_LOSE = 2
};

typedef	struct		s_image
{
	void		*img;
	int		*data;
	int		w;
	int		h;
}			t_image;

typedef	struct		s_component
{
	t_image		*img;
	int		x;
	int		y;
}			t_component;

typedef struct s_components t_components;
struct	s_components
{
	t_component	*component;
	t_components	*next;
};

typedef struct		s_frame
{
	t_image		*bg;
	t_components	*components;
}			t_frame;

typedef struct		s_scene
{
	t_component	bg;
	t_component	logo;
	t_component	rights;
	t_component	random;
	t_component	solo;
	t_component	quit;
	t_component	my_empty;
	t_component	my_rock[3];
	t_component	my_paper[3];
	t_component	my_scissors[3];
	t_component	adv_empty;
	t_component	adv_rock[3];
	t_component	adv_paper[3];
	t_component	adv_scissors[3];
}			t_scene;

typedef struct		s_game
{
	void		*win;
	void		*img;
	void		*mlx;
	int		*pixels;
	int		bpp;
	int		size_line;
	int		endian;
	int		sock;
	int		fd[2];
	char		*server_address;
	t_scene		scene;
	int		frame;
	int		is_selecting;
	int		is_ready;
	int		is_end;
	int		my_score;
	int		adv_score;
	int		bg_music;
	int		click_effect;
}			t_game;

void	closesocket(int *s);
int	closeGame(t_game *g);
void	exitStatus(const char *err, char *perr);


int	mousePos(int button, int x, int y, t_game *g);
int	mouseMove(int x, int y, t_game *g);
int	keyHandler(int key, t_game *g);

void	initScore(t_game *g);
void	initGraphics(t_game *g);
void	initSounds(t_game *g);
void	initNetworking(t_game *g);

void	socketManager(t_game *g);

t_image	*new_image(void *mlx, char *filename);

t_component new_component(t_image *image, int x, int y);
t_components *add_component(t_components *list, t_component *element);

void	load_components(t_game *g);

void	displayFrame(t_game *g);
void	displayComponent(t_game *g, t_component *component);
void	displayResult(t_game *g, int rslt, int adv);

void	reset(t_game *g);

#endif
