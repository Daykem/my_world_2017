/*
** EPITECH PROJECT, 2018
** button appli
** File description:
** world
*/

#include "my_world.h"

void button_load(map_node_t **map2d, window_t *window)
{
	update_map("data2", window);
}

void button_quit(map_node_t **map2d)
{
	exit(0);
}
