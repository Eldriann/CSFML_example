/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Core for the game objects
*/

#include <string.h>
#include <stdlib.h>
#include "my_sfml_core.h"
#include "my_sfml_gameobject.h"

gameobject_t *create_gameobject(char const *name)
{
	gameobject_t *new_go = malloc(sizeof(*new_go));

	if (new_go == NULL) {
		my_putdebug("Create GO:\n    ");
		my_putdebug(MSG_MY_SFML_MALLOC);
		return (NULL);
	}
	new_go->id = my_int_to_str((long)new_go);
	if (name == NULL)
		new_go->name = strdup("NO_NAME");
	else
		new_go->name = strdup(name);
	new_go->components = NULL;
	new_go->destroy = &destroy_gameobject;
	new_go->add_component = &add_component;
	new_go->add_custom_component = &add_custom_component;
	return (new_go);
}

void destroy_gameobject(gameobject_t *go)
{
	char *curr_id = NULL;

	if (go == NULL) {
		my_putdebug("Destroy gameobject:\n    ");
		my_putdebug(MSG_MY_SFML_ERR_NULL);
		return;
	}
	while (go->components != NULL) {
		curr_id = strdup(go->components->id);
		((component_cast_t *)go->components->data)->destroy(\
go->components->data);
		sf_remove(curr_id, &go->components);
		free(curr_id);
	}
	free(go->id);
	free(go->name);
	free(go);
}
