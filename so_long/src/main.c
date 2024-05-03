/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:33:56 by marbaron          #+#    #+#             */
/*   Updated: 2024/05/03 14:44:54 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char *read_and_stash_map(char *map)
{
	char	*stored_map;
	int		fd;
	char	buff;
	int		map_size;

	map_size = 0;
	fd = open(map, O_RDONLY);
	while (read(fd, &buff, 1))
		map_size++;
	stored_map = (char *)malloc(sizeof(char) * (map_size + 1));
	close(fd);
	fd = open(map, O_RDONLY);
	read(fd, stored_map, map_size);
	stored_map[map_size] = '\0';
	close(fd);
	return (stored_map);
	
}

int main(int argc, char **argv)
{
	t_data data;
	(void) argc;
	
	// 1). Function that reads and stash the map.
	// The original map is not read an stash as a 2d array.
	data.orignial_map = read_and_stash_map(argv[1]);
	map_validity(data.orignial_map, &data);
	// This is basically all of the parsing.
	// 2). function that checks if we have a valid map.
		// Check the map's conditon.
		// 1). Check if it only contains -> '1', '0', 'P', 'E', 'C' and "\n".
		// 2). Check if it contains the right amount of each thing's.
		// 3). Check the length of each horizontal line.
			// a). If any of the line after the first line are not the same
			//	   Length as the first one return an error msg.
		// 4). Check if the wall's are only made of '1'.
	// 3). Check for valid path in the map
		// 1). Count the number of collectables in the the map.
		// 2). Find the starting position of the player. 
		// 3). Then do floodfill on a backup map so it doesn't change the 
		// 	   map.
}