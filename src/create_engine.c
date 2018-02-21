/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** Create a window and the engine and return it
*/

/* File created the 21/02/2018 at 18:20:32 by julian.frabel@epitech.eu */

#include <stdio.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "my_sfml.h"
#include "platformer.h"

static int has_display_vars(char **env)
{
	char *key = "DISPLAY";
	int key_len = strlen(key);

	if (env == NULL || key == NULL) {
		perror("Environnement was NULL, couldn't find DISPLAY.\n");
		return (0);
	}
	for (int i = 0; env[i] != NULL; i++) {
		if (!strncmp(key, env[i], key_len) && env[i][key_len] == '=')
			return (1);
	}
	perror("Couldn't find DISPLAY in environnement.\n");
	return (0);
}

static int create_window(sfRenderWindow **window)
{
	*window = sfRenderWindow_create((sfVideoMode){WINDOW_X, WINDOW_Y, 32},\
WINDOW_NAME, sfClose, NULL);
	if (*window == NULL) {
		perror("[ERROR]Window could not be created!\n");
		return (84);
	}
	sfRenderWindow_setFramerateLimit(*window, FPS_LIMIT);
	return (0);
}

sf_engine_t *create_new_engine(char **env)
{
	sf_engine_t *engine = NULL;
	sfRenderWindow *window = NULL;

	if (!has_display_vars(env))
		return (NULL);
	if (create_window(&window))
		return (NULL);
	engine = create_engine(window);
	if (engine == NULL) {
		perror("[ERROR]Engine could not be created!\n");
		sfRenderWindow_destroy(window);
		return (NULL);
	}
	return (engine);
}