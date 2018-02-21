/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** main
*/

/* File created the 21/02/2018 at 18:11:34 by julian.frabel@epitech.eu */

#include "my_sfml.h"
#include "platformer.h"

int main(int ac, char **av, char **env)
{
	sf_engine_t *engine = create_new_engine(env);

	(void)ac;
	(void)av;
	if (engine == NULL)
		return (84);
	load_all_scenes(engine);
	while (sfRenderWindow_isOpen(engine->window)) {
		engine->update(engine);
		if (engine->current_scene)
			engine->current_scene->loop(engine, NULL);
		engine->render(engine);
	}
	engine->destroy(engine);
	return (0);
}