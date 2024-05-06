/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:30:25 by marbaron          #+#    #+#             */
/*   Updated: 2024/05/06 12:21:15 by margueriteb      ###   ########.fr       */
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
}   t_data;

void    map_validity(char *map, t_data *data);
int     get_row_number(char **map);
void    side_wall_validity(t_data *data);

#endif