//
// Created by Blue Sky on 3/31/20.
//

#ifndef SURAKARTA_ZERO_UI_H
#define SURAKARTA_ZERO_UI_H
#include<stdio.h>
//#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Basic.h"
SDL_Texture *renderText(char *s, char *e, SDL_Color color,int fontSize);
choice begin(void);
void Init_Position(void);
void Init_Display_Position(void);
void Display(void);
#endif //SURAKARTA_ZERO_UI_H
