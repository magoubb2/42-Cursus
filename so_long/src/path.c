/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:42:10 by margueriteb       #+#    #+#             */
/*   Updated: 2024/05/06 14:50:51 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Get the player's starting position.
void player_pos(t_data *data, int x, int y)
{
    // Loop over each of the rows of the floodfill map untile the end.
    while (data->floodfill_map[y])
    {
        // Loop over each of the colums of the floodfill map untile the end.
        while (data->floodfill_map[y][x])
        {
            // Check if the current position is the player position.
            if (data->floodfill_map[y][x] == 'P')
            {
                // Store the position inside of the player_pos_x
                data->player_pos_x = x;
                // Store the position inside of the player_pos_y
                data->player_pos_y = y;
                return ;
            }
            // Move to the next colum.
            x++;
        }
        x = 0;
        // Move to the next row.
        y++;
    }
}

// Function that will check if there is a possible way of exiting the game
// and collecting all of the collectibles.
void floodfill(int x, int y, t_data *data, int c)
{
    if (data->floodfill_map[x][y] == '1' || data->floodfill_map[x][y] == 'V')
        return ;
    data->floodfill_map[x][y] = 'V';
    floodfill(x - 1, y, data, c); // Up
    floodfill(x + 1, y, data, c); // Down
    floodfill(x, y - 1, data, c); // Left
    floodfill(x, y + 1, data, c); // Rigth
}