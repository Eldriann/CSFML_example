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

/**
** \brief Create and return a new engine, will also create a new window
**
** @param env the environnement (to check for the DISPLAY variable)
*/
sf_engine_t *create_new_engine(char **env);

#endif /* !__PLATFORMER_H_ */