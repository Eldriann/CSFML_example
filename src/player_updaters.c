/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** All the player related updaters
*/

/* File created the 21/02/2018 at 19:35:57 by julian.frabel@epitech.eu */

#include <stdbool.h>
#include "my_sfml.h"
#include "platformer.h"

/* This function will clip the position of the sprite and animate it */
static int updater_player_animation(gameobject_t *player, int delta_time)
{
	sf_animation_2d_t *anim = get_component(player, ANIMATION_2D);
	sf_transform_t *tr = get_component(player, TRANSFORM);
	sf_rigidbody_2d_t *rb = get_component(player, RIGIDBODY_2D);

	if (rb->speed.x == 0 && rb->speed.y == 0)
		return (0);
	anim->timer += delta_time;
	if (anim->timer >= anim->speed) {
		anim->view_rect.left += anim->view_rect.width;
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