/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marbaron <marbaron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:33:56 by marbaron          #+#    #+#             */
/*   Updated: 2024/04/29 12:12:34 by marbaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	// 1). Function that reads and stash the map.
	// This is basically all of the parsing.
	// 2). function that checks if we have a valid map.
		// Check the map's conditon.
		// 1). Check if it only contains -> '1', '0', 'P', 'E', 'C' and "\n".
		// 2). Check if it contains the right amount of each thing's.
		// 3). Check the length of each horizontal line.
			// a). If any of the line after the first line are not the same
			//	   Length as the first one return an error msg.
		// 4). Check if the wall's are only made of '1'.
		// 5). Check for a valid path in the map.
}