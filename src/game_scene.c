/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** Main scene
*/

/* File created the 21/02/2018 at 18:39:28 by julian.frabel@epitech.eu */

#include "my_sfml.h"

/*
** Here the data pointer of the scene that can be used to transfer
** data between scenes will not be used.
** Normaly you should do a structure that hold all the data that transit between
** scenes.
*/

/* Function called when the scene is loaded */
/*
** You can also use a static to load the scene only the first time if needed.
** Initialize_physic_state need to be called only once per loaded scene
** or the scene won't be able to use physics.
** (if you reset a scene you need to call it again)
*/
int load_game_scene(sf_engine_t *engine, void *data)
{
	(void)data;
	if (engine == NULL)
		return (84);
	engine->initialize_physic_state(engine);
	return (0);
}

/* Function called each frame when the scene is loaded */
int loop_game_scene(sf_engine_t *engine, void *data)
{
	sfEvent event;

	(void)data;
	if (engine == NULL)
		return (84);
	while (sfRenderWindow_pollEvent(engine->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(engine->window);
	}
	return (0);
}

/* Fuction called when the scene is unloaded */
/*
** If you do not call the reset scene the next time the scene is loaded
** all the old objects will remain at their place in their state.
*/
int unload_game_scene(sf_engine_t *engine, void *data)
{
	(void)data;
	reset_scene(engine->current_scene);
	return (0);
}

sf_scene_t *create_game_scene(sf_engine_t *engine)
{
	sf_scene_t *new_scene = create_scene("game");

	if (new_scene == NULL || engine == NULL)
		return (NULL);
	new_scene->load = &load_game_scene;
	new_scene->loop = &loop_game_scene;
	new_scene->unload = &unload_game_scene;
	engine->add_scene(engine, new_scene);
	return (new_scene);
}