/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:42:23 by marbaron          #+#    #+#             */
/*   Updated: 2024/04/30 12:54:00 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void line_len_validity(char *map)
{
    // Get the length of the first line and compare it to all of the 
    // following line.
}

void nb_character_validity(char *map, t_data *data)
{
    // If the number of 'P' is not 1, if the number of 'E' is not 1 and
    // if the number of C is less than 1 return an error msg.
}

void character_validity(char *map)
{
    // If the characters in the map are not: 1, 0, P, E, C or \n
    // return an error msg.
}

void side_wall_validity(t_data *data)
{
    // Check each of the side wall of the map and if they are not
    // 1 return an error msg.
}

void map_validity(char *map, t_data *data)
{
    // Function that checks for the valid character in the map.
    // Function that checks for the valid number of character.
    // Function that check if every line of the map is the same length.
}
