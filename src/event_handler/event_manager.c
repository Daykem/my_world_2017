/*
** EPITECH PROJECT, 2018
** event manager
** File description:
** my_world
*/

#include "my_world.h"

void analyse_event(window_t *window, map_node_t **map2d)
{
	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->m_window);
	if (window->event.type == sfEvtMouseButtonPressed) {
		button_manager(window->event.mouseButton, window, map2d);
	}
	if (window->event.type == sfEvtMouseMoved) {
		hover_manager(window->event.mouseMove, map2d, *window);
	}
}
