/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:42:10 by margueriteb       #+#    #+#             */
/*   Updated: 2024/05/23 11:29:49 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// 1). Count the number of collectables in the the map.
// 2). Find the starting position of the player. 
// 3). Then do floodfill on a backup map so it doesn't change the map.

// Get the player's starting position.
static void player_pos(t_data *data, int x, int y)
{
    // Loop over each of the rows of the floodfill map untile the end.
    while (data->floodfill_map[x])
    {
        // Loop over each of the colums of the floodfill map untile the end.
        while (data->floodfill_map[x][y])
        {
            // Check if the current position is the player position.
            if (data->floodfill_map[x][y] == 'P')
            {
                // Store the position inside of the player_pos_x
                data->player_pos_x = x;
                // Store the position inside of the player_pos_y
                data->player_pos_y = y;
                return ;
            }
            // Move to the next colum.
            y++;
        }
        y = 0;
        // Move to the next row.
        x++;
    }
}

// Function that will check if there is a possible way of exiting the game
// and collecting all of the collectibles.
static void floodfill(int x, int y, t_data *data, int *collectible)
{
    // Check if the current position is a '1; or a 'V' if it is skip it.
    if (data->floodfill_map[x][y] == '1' || data->floodfill_map[x][y] == 'V' || x < 0 || y < 0)
        return ;
    // Check if the current position is a 'C' if it is decrement the number of
    // collectibles.
    if (data->floodfill_map[x][y] == 'C')
        (*collectible)--;
    // If the current position is an 'E' the exit_flag is evaluated to one to
    // indicate that we have passed the exit.
    if (data->floodfill_map[x][y] == 'E')
        data->exit_flag = 1;
    // Them change the current position character for a 'V' for validated.
    data->floodfill_map[x][y] = 'V';
    floodfill(x - 1, y, data, collectible); // Up
    floodfill(x + 1, y, data, collectible); // Down
    floodfill(x, y - 1, data, collectible); // Left
    floodfill(x, y + 1, data, collectible); // Rigth
}

void path_validity(t_data *data)
{
    int x;
    int y;
    int collectible;

    x = 0;
    y = 0;
    // Assigne the amount of collectible calculated int the nb_character_validity
    // function.
    collectible = data->collectibles_number;
    // Get the player_pos_x and player_pos_y for the floodfill function.
    player_pos(data, x, y);
    // Execute the floodfill algo to know if there is a possible path.
    floodfill(data->player_pos_x, data->player_pos_y, data, &collectible);
    if (collectible != 0 || data->exit_flag != 1)
    {
        printf("error_1");
        exit(0);
    }
}