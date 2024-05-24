/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:10:49 by margueriteb       #+#    #+#             */
/*   Updated: 2024/05/24 14:52:08 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void    free_map(char **map)
{
    int i;

    i = 0;
    if (map == NULL)
        return ;
    while (map[i])
    {
        free(map[i]);
        map[i] = NULL;
        i++;
    }
    free (map);
    map = NULL;
}

static void clean_img(t_data *data)
{
    if (!data)
        return ;
    if (data->img_wall)
        mlx_destroy_image(data->mlx, data->img_wall);
    if (data->img_floor)
        mlx_destroy_image(data->mlx, data->img_floor);
    if (data->img_collectible)
        mlx_destroy_image(data->mlx, data->img_collectible);
    if (data->img_player)
        mlx_destroy_image(data->mlx, data->img_player);
    if (data->img_exit)
        mlx_destroy_image(data->mlx, data->img_exit);
    data = NULL;
}

void win(t_data *data)
{
    ft_printf("GG you've won!\n");
    free_map(data->map);
    free_map(data->floodfill_map);
    free(data->orignial_map);
    clean_img(data);
    exit(0);
}

int closed(t_data *data)
{
    ft_printf("closed window!\n");
    free_map(data->map);
    free_map(data->floodfill_map);
    free(data->orignial_map);
    clean_img(data);
    exit(0);
}
