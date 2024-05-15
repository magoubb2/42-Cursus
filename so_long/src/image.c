/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:35:31 by margueriteb       #+#    #+#             */
/*   Updated: 2024/05/15 16:24:45 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void    xpm_to_image(t_data *data)
{
    int     x;
    int     y;
    char    *value;

    value = "sprites/blue.xpm";
    data->img_floor = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
    value = "sprites/forest_green.xpm";
    data->img_wall = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
    value = "sprites/teddy_bear.xpm";
    data->img_collectible = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
}

static void    add_img_to_window(t_data *data, char tile, int x, int y)
{
    if (tile == '1')
    {
        if (!data->img_wall)
            printf("problem\n");
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_wall, x, y);
    }
    if (tile == '0')
    {
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_floor, x, y);
    }
    if (tile == 'C')
    {
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_collectible, x, y);
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_floor, x, y);
    }
}

void    put_img_to_window(t_data *data)
{
    int x;
    int y;

    y = -1;
    while(++y < data->row_number)
    {
        x = -1;
        while(++x < data->colum_number)
        {
            add_img_to_window(data, data->map[x][y], x * 100, y * 100);
            
        }
    }
}
