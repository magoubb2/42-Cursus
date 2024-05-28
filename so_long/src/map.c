/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:42:23 by marbaron          #+#    #+#             */
/*   Updated: 2024/05/28 12:03:42 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Parsing.
// Check the map's conditon.
	// 1). Check if it only contains -> '1', '0', 'P', 'E', 'C' and "\n".
	// 2). Check if it contains the right amount of each thing's.
	// 3). Check the length of each horizontal line.
	    // a). If any of the line after the first line are not the same
		//	   Length as the first one return an error msg.

static void line_len_validity(char *map)
{
    // Get the length of the first line and compare it to all of the
    // following line.
    int i;
    int first_line_len;
    int following_line_len;

    i = 0;
    first_line_len = 0;
    following_line_len = 0;
    // 1). loop until the counter is the '\n'. To get the len of the
    //     first line.
    while (map[i] != '\n')
    {
        first_line_len++;
        i++;
    }
    i++;
    // 2). Then loop on the map until it reaches the end of the map
    //     array.
    while (map[i] != '\0')
    {
        // 3). Inside of the while loop when the array reaches a new line,
        //     compare the length of the current line with the first one.
        if (map[i] == '\n')
        {
            if (following_line_len != first_line_len)
            {
                // return error msg
                ft_printf("error_4\n");
                exit(0);
            }
            // After reaching the new_line reset the counter for the
            // following line.
            following_line_len = 0;
        }
        else
            following_line_len++;
        i++;
    }
}

static void nb_character_validity(char *map, t_data *data)
{
    // If the number of 'P' is not 1, if the number of 'E' is not 1 and
    // if the number of C is less than 1 return an error msg.
    int p_nb;
    int e_nb;
    int c_nb;
    int i;

    p_nb = 0;
    e_nb = 0;
    c_nb = 0;
    i = 0;
    (void) data;
    while (map[i])
    {
        if (map[i] == 'P')
            p_nb++;
        if (map[i] == 'E')
            e_nb++;
        if (map[i] == 'C')
            c_nb++;
        i++;
    }
    if (p_nb != 1 || e_nb != 1 || c_nb < 1)
    {
        ft_printf("error_5\n");
        exit(0);
    }
    data->collectibles_number = c_nb;
    data->exit_flag = 0;
    data->exit_win_flag = 0;
}

static void character_validity(char *map)
{
    // If the characters in the map are not: 1, 0, P, E, C or \n
    // return an error msg.
    int i;

    i = 0;
    while (map[i])
    {
        if (map[i] != '1' && map[i] != '0' && map[i] != 'C' \
            && map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
        {
            ft_printf("error_6\n");
            exit (0);
        }
        i++;
            
    }
}

void map_validity(char *map, t_data *data)
{
    // (void) data;
    // Function that checks for the valid character in the map.
    line_len_validity(map);
    // Function that checks for the valid number of character.
    nb_character_validity(map, data);
    // Function that check if every line of the map is the same length.
    character_validity(map);
}
