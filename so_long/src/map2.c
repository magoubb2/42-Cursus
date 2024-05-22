/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:22:48 by margueriteb       #+#    #+#             */
/*   Updated: 2024/05/22 15:18:01 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int get_row_number(char **map)
{
    // Get the number of row on the double array of the map.
    int i;
    int row_nb;

    i = 0;
    row_nb = 0;
    while (map[i])
    {
        row_nb++;
        i++;
    }
    return (row_nb);
}

// Check each side wall of the map.
void side_wall_validity(t_data *data)
{
    // Counter for the colums.
    int x;
    // Counter for the rows
    int y;

    // The number of colums.
    data->colum_number = ft_strlen(data->map[0]);
    // The number of rows.
    data->row_number = get_row_number(data->map);
    y = 0;
    // Loop until y is no longer less than row_number.
    while (y < data->row_number)
    {
        x = 0;
        // Loop until x is no longer less than colum_number
        while (x < data->colum_number)
        {
            // check if the first row only contains '1'.
            // Then check if the last row only contains '1'.
            if (data->map[0][x] != '1' || data->map[data->row_number - 1][x] != '1')
                printf("error\n");
            // Check if the first colum only contains '1'.
            // Then check if the last colum only contains '1'.
            if (data->map[y][0] != '1' || data->map[y][data->colum_number - 1] != '1')
                printf("error\n");
            x++;
        }
        y++;
    }
    
}

static void player_moves(int next_ppx, int next_ppy, t_data *data)
{
    // 1). Check if the next position the player is trying to move to is not a wall.
    if (data->map[data->player_pos_x + next_ppx][data->player_pos_y + next_ppy] != '1')
    {
        // 2). Check if all the collectibles have been collected and if they have and the
        //     next player's position is is the exit, handle the condition that win the game.
        if (data->collectibles_number == 0 && data->map[data->player_pos_x + next_ppx][data->player_pos_y + next_ppy] == 'E' \
            && data->map[data->player_pos_x][data->player_pos_y] == 'P')
            {
                ft_printf("You've won!\n");
                exit(0);            
            }
        // 3). If player has not collected all of the collectible but the next position is
        //     is the exit the flag is set to one.
        if (data->map[data->player_pos_x + next_ppx][data->player_pos_y + next_ppy] == 'E' && data->collectibles_number != 0)
            data->exit_win_flag = 1;
        // 4). if collectible is encountered, decrement the collectible count. And update map
        //     by replacing collectible with floor.
        if (data->map[data->player_pos_x + next_ppx][data->player_pos_y + next_ppy] == 'C')
        {
            data->collectibles_number--;
        }
        data->map[data->player_pos_x][data->player_pos_y] = '0';
        // 5). Check that the player has steped on the exit before but could not leave and
        //     check that the current next move is not into an exit cell.
        if ((data->exit_win_flag == 1) && (data->map[data->player_pos_x + next_ppx][data->player_pos_y + next_ppy] != 'E'))
        {
            // If the condition are true leave the current position as an exit cell.
            data->map[data->player_pos_x][data->player_pos_y] = 'E';
            // And reset the flag indicating that we are no longer on the exit cell.
            data->exit_win_flag = 0;
        }
        // 1). Set the player position.
        data->map[data->player_pos_x + next_ppx][data->player_pos_y + next_ppy] = 'P';
        // 2). update the player's current position.
        data->player_pos_x = data->player_pos_x + next_ppx;
        data->player_pos_y = data->player_pos_y + next_ppy;
    }
}

int key_movement(int keytouch, t_data *data)
{
    if (keytouch == 13)
    {
        player_moves(-1, 0, data);
        put_img_to_window(data);
    }
    else if (keytouch == 2)
    {
        player_moves(0, 1, data);
        put_img_to_window(data);
    }
    else if (keytouch == 1)
    {
        player_moves(1, 0, data);
        put_img_to_window(data);
    }
    else if (keytouch == 0)
    {
        player_moves(0, -1, data);
        put_img_to_window(data);
    }
    return (0);
}