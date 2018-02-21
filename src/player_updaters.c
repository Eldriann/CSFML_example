/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** All the player related updaters
*/

/* File created the 21/02/2018 at 19:35:57 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include <stdbool.h>
#include "my_sfml.h"
#include "platformer.h"

/* This function will clip the position of the sprite and animate it */
static int updater_player_animation(gameobject_t *player, int delta_time)
{
	sf_animation_2d_t *anim = get_component(player, ANIMATION_2D);
	sf_transform_t *tr = get_component(player, TRANSFORM);
	sf_rigidbody_2d_t *rb = get_component(player, RIGIDBODY_2D);
	int frames_passed = 0;

	if (rb->speed.x == 0 && rb->speed.y == 0)
		return (0);
	anim->timer += delta_time;
	if (anim->timer >= anim->speed) {
		frames_passed = (int)(anim->timer / anim->speed);
		anim->view_rect.left += (anim->view_rect.width * frames_passed);
		anim->timer -= (anim->speed * frames_passed);
		if (anim->view_rect.left >= anim->max_rect.left)
			anim->view_rect.left = 0;
		sfSprite_setTextureRect(anim->sprite, anim->view_rect);
	}
	sfSprite_setPosition(anim->sprite, (sfVector2f){tr->position.x, tr->position.y});
	return (0);
}

/*This function will set the horizontal speed of the player based on the input*/
static int updater_player_movement(gameobject_t *player)
{
	bool is_leftkey_pressed = sfKeyboard_isKeyPressed(sfKeyLeft);
	bool is_rightkey_pressed = sfKeyboard_isKeyPressed(sfKeyRight);
	int axis_x = is_rightkey_pressed - is_leftkey_pressed;
	sf_rigidbody_2d_t *player_rb = get_component(player, RIGIDBODY_2D);

	player_rb->speed.x = axis_x * PLAYER_SPEED;
	return (0);
}

/* Will call all the needed functions */
int player_updater(gameobject_t *player, int delta_time)
{
	updater_player_animation(player, delta_time);
	updater_player_movement(player);
	return (0);
}

static int is_grounded(sf_engine_t *engine, gameobject_t *player)
{
	int nb_collisions = 0;
	sf_collider_2d_t *col = get_component(player, COLLIDER_2D);
	sf_transform_t *tr = get_component(player, TRANSFORM);
	sfIntRect below_player;

	if (col == NULL)
		return (0);
	below_player = col->hitbox;
	below_player.left += tr->position.x;
	below_player.top += tr->position.y + 1;
	/* We get the number of collisions but the objects that collide with do not interess us so we free the array*/
	free(engine->get_collisions_rect(engine, below_player, &nb_collisions, player));
	if (nb_collisions)
		return (1);
	return (0);
}

/*
** Make the player jump
*/
void do_player_jump(sf_engine_t *engine)
{
	gameobject_t *player_go = engine->get_gameobject(engine, "player");
	sf_rigidbody_2d_t *rb = get_component(player_go, RIGIDBODY_2D);

	if (rb == NULL)
		return;
	if (is_grounded(engine, player_go))
		rb->speed.y = -PLAYER_JUMP_FORCE;
}