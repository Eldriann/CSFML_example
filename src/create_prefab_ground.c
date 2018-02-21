/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** Ground prefab
*/

/* File created the 21/02/2018 at 20:59:56 by julian.frabel@epitech.eu */

#include <stdio.h>
#include "my_sfml.h"
#include "platformer.h"

static int add_components(gameobject_t *ground)
{
	if (ground->add_component(ground, TRANSFORM))
		return (84);
	if (ground->add_component(ground, COLLIDER_2D))
		return (84);
	if (ground->add_component(ground, RIGIDBODY_2D))
		return (84);
	if (ground->add_component(ground, ANIMATION_2D))
		return (84);
	return (0);
}

static void initialize_components(sf_engine_t *engine,
gameobject_t *ground, sfIntRect position)
{
	sf_transform_t *tr = get_component(ground, TRANSFORM);
	sf_animation_2d_t *anim = get_component(ground, ANIMATION_2D);
	sf_collider_2d_t *collider = get_component(ground, COLLIDER_2D);
	sf_rigidbody_2d_t *rb = get_component(ground, RIGIDBODY_2D);

	if (tr == NULL || anim == NULL || collider == NULL)
		return;
	anim->set_sprite(anim, engine->get_sprite(engine, GROUND_TEXTURE));
	tr->position.x = position.left;
	tr->position.y = position.top;
	collider->hitbox.width = position.width;
	collider->hitbox.height = position.height;
	rb->is_static = 1; /*Say that this object will never move with physic*/
	sfSprite_setPosition(anim->sprite, (sfVector2f){position.left, position.top});
	sfSprite_setScale(anim->sprite, (sfVector2f){position.width / GROUND_TEXTURE_SIZE, position.height / GROUND_TEXTURE_SIZE});
	engine->add_to_layer(engine, GAME, (void **)&(anim->sprite));
}

gameobject_t *create_prefab_ground(sf_engine_t *engine, sfIntRect position)
{
	gameobject_t *ground = create_gameobject("ground");

	if (ground == NULL) {
		perror("Could not create ground!\n");
		return (NULL);
	}
	if (add_components(ground)) {
		perror("Could not create ground components!\n");
		ground->destroy(ground);
		return (NULL);
	}
	initialize_components(engine, ground, position);
	engine->add_gameobject(engine, ground);
	engine->add_physic_object(engine, ground);
	return (ground);
}