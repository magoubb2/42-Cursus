/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:35:31 by margueriteb       #+#    #+#             */
/*   Updated: 2024/05/22 14:01:56 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Transform the xpm file to image.
void    xpm_to_image(t_data *data)
{
    int     x;
    int     y;
    char    *value;

    // Transform the floor xmp file.
    value = "sprites/blue.xpm";
    data->img_floor = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
    // Transform the the wall xpm file.
    value = "sprites/wall.xpm";
    data->img_wall = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
    // Transform the collectible xpm file.
    value = "sprites/collectibles.xpm";
    data->img_collectible = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
    // Transform the player xpm file.
    value = "sprites/player.xpm";
    data->img_player = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
    // Transform the exit xpm file.
    value = "sprites/door.xpm";
    data->img_exit = mlx_xpm_file_to_image(data->mlx, value, &x, &y);
}

// Assigne image to character in the map.
static void    add_img_to_window(t_data *data, char tile, int x, int y)
{
    // If the character in the map is a '1' put the wall image.
    if (tile == '1')
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_wall, x, y);
    // If the character in the map is a '0' put the floor image.
    if (tile == '0')
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_floor, x, y);
    // If the character in the map is a 'P' put the player image.
    if (tile == 'P')
    {
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_floor, x, y);
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_player, x, y);
    }
    // If the character in the map is a 'E' put the exit image.
    if (tile == 'E')
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_exit, x, y);
    // If the character in the map is a 'C' put the collectibles image.
    if (tile == 'C')
    {
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_floor, x, y);
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_collectible, x, y);
    }
}

void    put_img_to_window(t_data *data)
{
    int x;
    int y;
    y = -1;
    // Start at the first row.
    while(++y < data->row_number)
    {
        x = -1;
        // And move in the colums and add the image at the current 
        // position before changing row.
        while(++x < data->colum_number)
        {
            // Add the image to the window on the current position.
            add_img_to_window(data, data->map[y][x], x * 32, y * 32);
        }
    }
}
