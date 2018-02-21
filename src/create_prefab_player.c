/*
** EPITECH PROJECT, 2017
** my_sfml
** File description:
** Create a player gameobject
*/

/* File created the 21/02/2018 at 19:14:10 by julian.frabel@epitech.eu */

#include <stdio.h>
#include "my_sfml.h"
#include "platformer.h"

/* We add all the components needed for the player */
/*
** TRANSFORM: positions, scale...
** RIGIDBODY_2D: so that our player has physics
** COLLIDER_2D: our player can collide with other objects
** ANIMATION_2D: our player has an animation
*/
static int add_components(gameobject_t *player)
{
	if (player->add_component(player, TRANSFORM) == NULL)
		return (84);
	if (player->add_component(player, RIGIDBODY_2D) == NULL)
		return (84);
	if (player->add_component(player, COLLIDER_2D) == NULL)
		return (84);
	if (player->add_component(player, ANIMATION_2D) == NULL)
		return (84);
	return (0);
}

/* Here we initialize the components and add a renderer */
static void initialize_components(sf_engine_t *engine, gameobject_t *player)
{
	/* We get the animation component of the player */
	sf_animation_2d_t *anim = get_component(player, ANIMATION_2D);

	if (anim == NULL)
		return;
	anim->set_sprite(anim, engine->get_sprite(engine, PLAYER_TEXTURE));
	anim->view_rect.width = PLAYER_ANIMATION_SIZE;
	anim->view_rect.height = PLAYER_ANIMATION_SIZE;
	anim->max_rect.left = PLAYER_ANIMATION_SIZE * PLAYER_ANIMATION_NB_FRAME;
	anim->speed = PLAYER_ANIMATION_SPEED;
	engine->add_to_layer(engine, GAME, (void **)&(anim->sprite));
}

gameobject_t *create_prefab_player(sf_engine_t *engine)
{
	gameobject_t *player = create_gameobject("player");

	if (player == NULL) {
		perror("Could not create player prefab!");
		return (NULL);
	}
	if (add_components(player)) {
		perror("Could not create player components!");
		player->destroy(player);
		return (NULL);
	}
	initialize_components(engine, player);
	engine->add_gameobject(engine, player);/* We add player to the engine */
	engine->add_physic_object(engine, player);/* And the physic one */
	engine->add_update(engine, player, (UPDATER)&player_updater);
	return (player);
}