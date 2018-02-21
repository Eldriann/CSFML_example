/*
** EPITECH PROJECT, 2017
** CSFML_example
** File description:
** Example header
*/

/* File created the 21/02/2018 at 18:15:15 by julian.frabel@epitech.eu */

#ifndef __PLATFORMER_H_
#define __PLATFORMER_H_

#include "my_sfml.h"

#define WINDOW_X 800
#define WINDOW_Y 600
#define WINDOW_NAME "CSFML_Example"

#define FPS_LIMIT 120

#define STARTING_SCENE "game"

#define PLAYER_TEXTURE "assets/sprites/player.png"
#define PLAYER_ANIMATION_SPEED 64
#define PLAYER_ANIMATION_SIZE 32
#define PLAYER_ANIMATION_NB_FRAME 3
#define PLAYER_SPEED 128 /* in pixel per seconds */

/**
** \brief Create and return a new engine, will also create a new window
**
** @param env the environnement (to check for the DISPLAY variable)
*/
sf_engine_t *create_new_engine(char **env);

/**
** \brief Create the game scene
**
** @param engine the engine to add too
*/
sf_scene_t *create_game_scene(sf_engine_t *engine);

/**
** \brief Load all scenes and switch to the STARTING_SCENE
**
** @param engine the engine to load to
*/
void load_all_scenes(sf_engine_t *engine);

/**
** \brief Create a player prefab and return it
*/
gameobject_t *create_prefab_player(sf_engine_t *engine);
/**
** \brief Updater for the player, will be run each frame
*/
int player_updater(gameobject_t *player, int delta_time);

#endif /* !__PLATFORMER_H_ */