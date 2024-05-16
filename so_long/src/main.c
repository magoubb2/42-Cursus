/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margueritebaronbeliveau <margueritebaro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:33:56 by marbaron          #+#    #+#             */
/*   Updated: 2024/05/16 12:21:54 by margueriteb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char **convert_simple_array(char *map)
{
	return (ft_split(map, '\n'));
}

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
	// This is basically all of the parsing.
	// 2). function that checks if we have a valid map.
	map_validity(data.orignial_map, &data);
	// Transform the simple array into a double array.
	data.map = convert_simple_array(data.orignial_map);
	// Initialise a backup map for the floodfill.
	data.floodfill_map = convert_simple_array(data.orignial_map);
	// 4). Check if the wall's are only made of '1'.
	side_wall_validity(&data);
	// 3). Check for valid path in the map
	path_validity(&data);
	// 4). Initialise mlx.
	data.mlx = mlx_init();
	// 5). Initialise the game window.
	printf("%i\n", data.row_number);
	printf("%i\n", data.colum_number);
	data.mlx_window = mlx_new_window(data.mlx, data.colum_number * 32, data.row_number * 32, "so_long");
	// 6). transform xpm to image. 
	xpm_to_image(&data);
	// 7). Add images to the window.
	put_img_to_window(&data);
	// 6) Initialise the game hook.
	// 7) mlx loop.
	mlx_loop(data.mlx);
}