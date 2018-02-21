/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** Load all the project scenes
*/

/* File created the 21/02/2018 at 18:59:16 by julian.frabel@epitech.eu */

#include <stdio.h>
#include "my_sfml.h"
#include "platformer.h"

/*
** This function register all the scenes to the engine.
** It also change the current scene to the starting scene
*/
void load_all_scenes(sf_engine_t *engine)
{
	if (create_game_scene(engine) == NULL)
		perror("Could not create game scene!\n");
	engine->change_scene(engine, STARTING_SCENE, NULL);
}