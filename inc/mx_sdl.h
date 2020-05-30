/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <oouklich@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:09:59 by oouklich          #+#    #+#             */
/*   Updated: 2020/05/29 13:22:59 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MX_SDL_H
# define MX_SDL_H

# include <SDL.h>
# include <SDL_mixer.h>

enum					e_mx_error_codes
{
	MX_ERROR_init_code,
	MX_ERROR_wrong_type_code,
	MX_ERROR_load_fail_code,
	MX_ERROR_volume_code
};

enum					e_mx_error_returns
{
	MX_ERROR_init = -1,
	MX_ERROR_wrong_type = -2,
	MX_ERROR_load_fail = -3,
	MX_ERROR_volume = -4
};

enum					e_mx_type
{
	MX_MUSIC = 1, MX_EFFECT = 0
};

union					u_mx_sound
{
	Mix_Music			*m;
	Mix_Chunk			*e;
};

typedef struct			s_mx_sound
{
	union u_mx_sound	sound;
	enum e_mx_type		type;
}						t_mx_sound;

typedef	struct			s_mx_playlist
{
	t_mx_sound			*list;
	int					length;
}						t_mx_playlist;

int						mx_init(void);
int						mx_quit(void);
t_mx_playlist					*mx_get_playlist(void);
int						mx_push_music(const char *path, enum e_mx_type mx);
int						mx_volume(int id, int volume);
void						*mx_realloc(void **ptr, size_t old, size_t len);
void					mx_play(int id, int loops);
void					mx_stop(int id);
void					mx_pause_music();
void					mx_resume_music();
int						mx_error(enum e_mx_error_codes code,
		enum e_mx_error_returns ret);

#endif
