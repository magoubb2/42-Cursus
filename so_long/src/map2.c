/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:22:48 by margueriteb       #+#    #+#             */
/*   Updated: 2024/05/10 12:08:10 by margueriteb      ###   ########.fr       */
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