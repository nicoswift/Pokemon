#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Unit.h"



class Monster{

    /*enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STILL  
    };



    int monster_width = 50;
    int monster_height = 50;
    
    int animcount = 4;

    const static int frames = 2;

    SDL_Point position;
    Unit* curunit;
    Unit* nextunit;
    Texture* b_texture;
    SDL_Rect collider;
    Direction curdir;
    Direction nextdir;

    SDL_Rect UP_frames[frames];
    SDL_Rect DOWN_frames[frames];
    SDL_Rect LEFT_frames[frames];
    SDL_Rect RIGHT_frames[frames];

    /*UP_frames[0] = {}; //set dimensions in the image 
    UP_frames[1] = {}; //set dimensions in the image 

    DOWN_frames[0] = {}; //set dimensions in the image 
    DOWN_frames[1] = {}; //set dimensions in the image 

    LEFT_frames[0] = {}; //set dimensions in the image 
    LEFT_frames[1] = {}; //set dimensions in the image 

    RIGHT_frames[0] = {}; //set dimensions in the image 
    RIGHT_frames[1] = {}; //set dimensions in the image

    bool isMoving = false;

    Monster(Unit* unitt, Texture* texture);

    void SetUnit(Unit* unitt);

    void Refresh();

    void Render();

    bool CheckCollision(SDL_Rect other_collider);

    void HandleKeys(SDL_Event* event);

    bool MoveOneUnit(Direction dir);

    bool Motion();

    SDL_Rect GetCollider();

    Direction GetDirection();

    Direction GetNextDirection();

    Unit GetCurUnit();

    Unit GetNextUnit();

    SDL_Rect GetPos();*/

};