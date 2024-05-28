/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:30:25 by marbaron          #+#    #+#             */
/*   Updated: 2024/05/28 12:00:31 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data
{
    char    **map;
    char    **floodfill_map;
    char    *orignial_map;
    int     row_number;
    int     colum_number;
    int     collectibles_number;
    int     player_pos_x;
    int     player_pos_y;
    int     exit_flag;
    int     exit_win_flag;
    void    *mlx;
    void    *mlx_window;
    void    *img_floor;
    void    *img_player;
    void    *img_collectible;
    void    *img_wall;
    void    *img_exit;
}   t_data;

void    map_validity(char *map, t_data *data);
int     get_row_number(char **map);
void    side_wall_validity(t_data *data);
void    path_validity(t_data *data);
void    put_img_to_window(t_data *data);
void    xpm_to_image(t_data *data);
int     key_movement(int keycode, t_data *data);
void    win(t_data *data);
int     closed(t_data *data);


#endif