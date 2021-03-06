/*
** EPITECH PROJECT, 2018
** header
** File description:
** header
*/
#ifndef MY_WORLD_H
#define MY_WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <math.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define ANGLE_X 35
#define ANGLE_Y 25.264
#define SCALING_X 64
#define SCALING_Y 64
#define SCALING_Z 64
#define DEF_3DMAP "ressources/default/default_map3D.legend"

#define BUTTON_GREEN "ressources/ui/button_green.png"
#define BUTTON_GREEN_BURN "ressources/ui/button_green_burn.png"
#define BUTTON_GREEN_HOVER "ressources/ui/button_green_hover.png"

#define HOVER_SHAPE "ressources/ui/hover_vertex.png"
#define CONVEX_SHAPE "ressources/ui/convex_txtr_base.png"

#define FONT1 "ressources/font/font01.otf"

#define TXTR_GRASS "ressources/ui/grass_texture.jpg"
#define TXTR_DIRT "ressources/ui/brown.png"
#define TXTR_ROCK_BURN "ressources/ui/rock_texture_burn.png"
#define TXTR_ROCK "ressources/ui/rock_texture.jpg"
#define TXTR_WATER "ressources/ui/water_texture.jpg"
#define TXTR_GELE "ressources/ui/gele_texture.jpg"
#define TXTR_GRASS_HOVER "ressources/ui/grass_texture_hover.jpg"

#define SONG_BUILD "ressources/sound/build.ogg"
#define SONG_DUG "ressources/sound/dug.ogg"
#define SONG_BACK "ressources/sound/background.ogg"

#define HOVER_MOUSE "ressources/hover/01.jpg"

#define PANEL_SAVE "ressources/ui/panel_save.png"
#define PANEL_BKGRD "ressources/ui/background.jpg"

#define ELEMENT_H1 "ressources/elements/house_1.png"
#define ELEMENT_T1 "ressources/elements/tree_1.png"
#define ELEMENT_H2 "ressources/elements/house_2.png"
#define ELEMENT_O1 "ressources/elements/bench_1.png"
#define ELEMENT_O2 "ressources/elements/object1.png"

typedef struct element_s {
	sfSprite *sprt;
	sfTexture **txtr;
	sfVector2f pos;
	sfVector2f size;
	sfBool active;
	sfBool rendered;
	int id;
} element_t;

typedef struct input_map_s {
	int **map;
	int len_x;
	int len_y;
	int error;
} input_map_t;

typedef struct map_node_s {
	input_map_t input_map;
	sfVector2f iso_point;
	sfConvexShape *node_shape;
	sfTexture *node_txtr;
	sfTexture *hover_txtr;
	sfVector2f *convex_points;
	sfCircleShape *hover_shape;
	sfTexture *hover_shape_txtr;
	sfBool hover_visible;
	sfVector2f stock_translation;
	element_t element;
} map_node_t;

typedef struct buble_box_s {
	sfVector2f pos;
	sfText *message;
	sfFont *font;
	sfBool display;
} buble_box_t;

typedef struct button_s {
	sfRectangleShape *shape;
	sfRectangleShape *shape_hover;
	sfTexture *txtr;
	sfVector2f size;
	sfVector2f pos;
	sfText *message;
	sfFont *font;
	char *buble_str;
	sfBool hovered;
} button_t;

typedef struct text_box_s {
	sfVector2f panel_pos;
	sfVector2f text_pos;
	sfVector2f size;
	sfTexture *panel_txtr;
	sfSprite *panel_sprt;
	char *stock_str;
	sfText *panel_txt;
	sfText *dynamic_txt;
	sfFont *font;
	button_t *buttons;
} text_box_t;

typedef struct tools_state_s {
	sfBool elevate;
	sfBool dig;
	sfBool corner;
	sfBool save;
	sfBool load;
	sfBool element;
} tools_state_t;

typedef struct ui_size_s {
	int tr_size;
	int app_size;
	int tools_size;
} ui_size_t;

typedef struct ui_s {
	ui_size_t ui_size;
	button_t *button_translate;
	button_t *button_application;
	button_t *button_tools;
	tools_state_t tools_state;
	text_box_t input_box;
	text_box_t input_box_load;
} ui_t;

typedef struct visualizer_s {
	sfSprite *sprt;
	sfTexture *txtr;
	sfVector2f pos;
} visualizer_t;

typedef struct window_s {
	sfVector2u size;
	sfRectangleShape *background;
	sfTexture *background_txtr;
	sfRenderWindow *m_window;
	sfEvent event;
	ui_t window_ui;
	sfBool map_visible;
	map_node_t **stock_map2d;
	buble_box_t buble_box;
	sfBool quit;
	visualizer_t elem_visu;
} window_t;

sfVector2f		project_iso_point(int x, int y, int z);
window_t		create_window(int, int);
map_node_t		create_map_node(int, int, int, window_t);
map_node_t		**create_2d_map(input_map_t map3d, window_t);
int			display_vertex(window_t *, map_node_t **);
void			display_point(int, int, window_t *, map_node_t **);
sfVertexArray		*create_line(sfVector2f *, sfVector2f *);
sfVector2f		quick_projection_iso_point(sfVector2f, int);
button_t		create_button(sfVector2f position, char *msg,
				char *buble_str);
ui_t			create_ui(window_t);
void			button_translate(map_node_t **, int, int);
void			display_button_translate(window_t window,
					button_t *buttons);
int			check_error(int ac, char **av);
void			button_manager(sfMouseButtonEvent mouse_event,
				window_t *, map_node_t **);
sfBool			button_is_clicked(button_t button,
					sfMouseButtonEvent click_pos);
void			analyse_event(window_t *window, map_node_t **map2d);
void			hover_manager(sfMouseMoveEvent mouse_evt,
				map_node_t **, window_t *);
void			second_hover_manager(sfMouseMoveEvent mouse_evt,
					window_t *);
void			generate_texture(map_node_t **map2d);
void			display_button_translate(window_t window,
						button_t *buttons);
window_t		create_window_err(int, char **);
input_map_t		my_rd(char *str);
input_map_t		my_str_to_int_array(char *);
sfVector2u		get_hovered_point(map_node_t **map2d);
buble_box_t		create_buble_box(window_t);
void			display_button_application(window_t, button_t *);
void			buble_hover_manager(sfMouseMoveEvent, window_t *);
int			button_checker(button_t *,
				sfMouseMoveEvent mouse_pos, int);
void			display_button_tools(window_t window,
					button_t *buttons);
void			display_buble_box(buble_box_t box, window_t window);
void			tools_button_manager(sfMouseButtonEvent,
				window_t *, map_node_t **);
void			button_load(map_node_t **map2d, window_t *window);
void			button_quit(map_node_t **map2d, window_t *window);
void			selection_button_manager(window_t *window,
						button_t button);
void			save_map(char *file_name, window_t window);
void			write_file(int **map_z, int len_x,
				int len_y, FILE *fp);
sfBool			button_is_hovered(button_t button,
				sfMouseMoveEvent mouse_evt);
sfBool			button_is_clicked(button_t button,
					sfMouseButtonEvent click_pos);
sfBool			is_hovered(map_node_t **map2d);
void			change_button_message(button_t button,
				char *new_msg);
void			change_button_texture(button_t button,
				char *new_txtr);
void			set_box_pos(sfMouseMoveEvent mouse,
				buble_box_t box);
int			load_new_map(char *new_map_path,
				window_t *window);
void			tool_elevate(window_t *window,
				int x, int y, map_node_t **map2d);
void			tool_dig(window_t *window,
				int x, int y, map_node_t **map2d);
text_box_t		create_text_box(window_t, char *, char *);
sfVector2f		get_position_by_percent(window_t, int, int);
void			display_tree(window_t *);
void			handle_special_case(window_t *window,
					map_node_t **map2d);
void			handle_convex_texture(map_node_t node,
					window_t *window);
void			display_simple_button(window_t window,
					button_t button);
void			display_text_box(text_box_t box, window_t window);
int			manage_text_box(window_t *window,
					sfTextEvent input_txt);
void			manage_save_system(window_t *window);
void			button_text_box(window_t *window,
					sfMouseButtonEvent mouse_evt);
void			print_help(void);
void			key_manager(window_t *, sfKeyEvent, map_node_t **);
void			shortcut_tools(sfKeyEvent key, window_t *window);
sfVector2f		get_iso_point(int current_zoom,
				input_map_t tmp5, int i, int j);
void			button_zoom(map_node_t **map2d,
				int offset, window_t *window);
void			button_save(map_node_t **map2d, window_t *window);
void			free_all(window_t window, map_node_t **map2d);
void			free_ui(ui_t ui);
void			free_text_box(text_box_t item);
void			free_button_array(button_t *button, int size);
void			free_buble_box(buble_box_t item);
void			free_button(button_t button);
void			free_map2d(map_node_t **map2d);
void			free_line(sfVertexArray *array);
element_t		create_element(sfVector2f m_pos);
void			manage_elem_display(window_t window,
				map_node_t *node);
void			display_elements(window_t *window,
				map_node_t **map2d);
void			free_element(element_t item);
void			set_elem_hight(sfVector2f iso, element_t *item);
void			handle_exit_click(window_t *window,
				sfMouseButtonEvent mouse_evt);
void			handle_textbox_action(window_t *window,
			char *stock_tmp_save, char *stock_tmp_load);
visualizer_t		create_visualizer(window_t window);
void			manage_elem(window_t *window, map_node_t **map2d,
			button_t button, sfMouseButtonEvent mouse_event);
void			display_analizer(window_t window,
				visualizer_t visu);
void			free_visu(visualizer_t);
int			check_valid_file(char *path);
int			check_directory(char *file);
void			tool_elem(window_t *window, int x,
			int y, map_node_t **map2d);
#endif
