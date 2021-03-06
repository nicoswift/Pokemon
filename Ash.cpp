#pragma once
#include "Ash.h"
#include "Wall.h"
#include "Matrix.h"
#include <string>
#include <algorithm>
using namespace std;

Ash::Ash(Unit* unitt, Texture* texture)
{

    curunit = unitt;
    nextunit = NULL;
    p_texture = texture;

    collider.w = ash_width;
    collider.h = ash_height;

    UP_frames[0] = {}; //set dimensions in the image 
    UP_frames[1] = {}; //set dimensions in the image 

    DOWN_frames[0] = {}; //set dimensions in the image 
    DOWN_frames[1] = {}; //set dimensions in the image 

    LEFT_frames[0] = {}; //set dimensions in the image 
    LEFT_frames[1] = {}; //set dimensions in the image 

    RIGHT_frames[0] = {}; //set dimensions in the image 
    RIGHT_frames[1] = {}; //set dimensions in the image

    if (unitt != NULL)
    {
        position.x = unitt->GetPos().x * ash_width;
        position.y = unitt->GetPos().y * ash_height;
    }
    else
    {
        position.x = 0;
        position.y = 0;
    }

    



    curdir = RIGHT;
    nextdir = RIGHT;
}

void Ash::HandleKeys(SDL_Event *event)
{

    if (event->type == SDL_KEYDOWN && event->key.repeat == 0)
    {
        if (event->key.keysym.sym == SDLK_UP)
        {
            nextdir = UP;
        }
        else if (event->key.keysym.sym == SDLK_DOWN)
        {
            nextdir = DOWN;
        }
        else if (event->key.keysym.sym == SDLK_LEFT)
        {
            nextdir = LEFT;
        }
        else if (event->key.keysym.sym == SDLK_RIGHT)
        {
            nextdir = RIGHT;
        }
    }
}

bool Ash::MoveOneUnit(Direction dir)
{
    if (dir == UP)
    {
        if (curunit->GetPos().y - 1 < 0)
        {
            return false;
        }
        nextunit = unitm->GetUnitFromMatrix(curunit->GetPos().x, curunit->GetPos().y - 1);

    }
    else if (dir == DOWN)
    {
        if (curunit->GetPos().y + 1 >= unitm->height)
        {
            return false;
        }
        nextunit = unitm->GetUnitFromMatrix(curunit->GetPos().x, curunit->GetPos().y + 1);
    }
    else if (dir == LEFT)
    {
        if (curunit->GetPos().x - 1 < 0)
        {
            return false;
        }
        nextunit = unitm->GetUnitFromMatrix(curunit->GetPos().x-1, curunit->GetPos().y);
    }
    else if (dir == RIGHT)
    {
        if (curunit->GetPos().x + 1 >= unitm->width)
        {
            return false;
        }
        nextunit = unitm->GetUnitFromMatrix(curunit->GetPos().x +1, curunit->GetPos().y);
    }

    if (nextunit==NULL || nextunit->GetWall()==NULL){
        nextunit=NULL;
        return false;
    }

    return true;
}

void Ash::Render()
{
    if (curdir==UP){
        p_texture->Render(position.x, position.y, &UP_frames[frame_num]);
    }
    else if(curdir==DOWN){
        p_texture->Render(position.x, position.y, &DOWN_frames[frame_num]);
    }
    else if(curdir==LEFT){
        p_texture->Render(position.x, position.y, &LEFT_frames[frame_num]);
    }
    else if(curdir==LEFT){
        p_texture->Render(position.x, position.y, &RIGHT_frames[frame_num]);
    }

}

void Ash::Refresh(){

    //NOTE

    if (nextunit!=NULL && nextunit->GetPokeball()!=NULL){

        // SUS about the Check Collision Method's need.
        //if (CheckCollisionForTwo(SDL_Rect(position.x,position.y, Unit::width, ash_height), nextunit->GetPokeball()->GetCollider()){
            //DELETE THE POKEBALL; DELETE YET TO BE IMPLEMENTED
            points++;
        //}
    }

    if (nextunit!=NULL && nextunit->GetSquirtle()!=NULL){
        //if (CheckCollisionForTwo(SDL_Rect(position.x,position.y, ash_width, ash_height), nextunit->GetSquirtle()->GetCollider()){
            //DELETE THE POKEBALL; DELETE YET TO BE IMPLEMENTED
            squrtle = true;
        //}
    }

    if (nextunit!=NULL && nextunit->GetJigglyPuff()!=NULL){
        //if (CheckCollisionForTwo(SDL_Rect(position.x,position.y, ash_width, ash_height), nextunit->GetJigglyPuff()->GetCollider()){
            //DELETE THE POKEBALL; DELETE YET TO BE IMPLEMENTED
            jpuff = true;
        //}
    }

    if (nextunit!=NULL && nextunit->GetGastly()!=NULL){
        //if (CheckCollisionForTwo(SDL_Rect(position.x,position.y, ash_width, ash_height), nextunit->GetGastly()->GetCollider()){
            //DELETE THE POKEBALL; DELETE YET TO BE IMPLEMENTED
            gastly = true;
        //}
    }

    if (nextunit!=NULL && nextunit->GetZoroark()!=NULL){
        //if (CheckCollisionForTwo(SDL_Rect(position.x,position.y, ash_width, ash_height), nextunit->GetZoroark()->GetCollider()){
            //DELETE THE POKEBALL; DELETE YET TO BE IMPLEMENTED
            zoroark = true;
        //}
    }

    if (curunit==nextunit || nextunit==NULL){
        if (curdir!=nextdir){
            if (MoveOneUnit(nextdir)){
                curdir = nextdir;
            }else{
                MoveOneUnit(curdir);
            }
        }else{
            MoveOneUnit(curdir);
        }

        if (nextunit==NULL){
            isMoving = false;
        }else{
            isMoving = true;
        }
    }else{

        if (curdir == UP){
            //position.y = max(position.y - speed , nextunit->GetPos().y*Unit::height);
        }else if (curdir==DOWN){
            //position.y = min(position.y + speed, nextunit->GetPos().y*Unit::height);
        }else if (curdir==LEFT){
            //position.x = max(position.x - speed, nextunit->GetPos().x*Unit::width);
        }else if (curdir ==RIGHT){
            //position.x = min(position.x + speed, nextunit->GetPos().x*Unit::width);
        }

        if ((curdir==LEFT|| curdir == RIGHT) && position.x == nextunit->GetPos().x*Unit::width){
            SetUnit(nextunit);
        }

        if ((curdir == UP|| curdir == DOWN) && position.x == nextunit->GetPos().y*Unit::height){
            SetUnit(nextunit);
        }
        collider.x = position.x;
        collider.y = position.y;
    }

}

void Ash::SetDimensions() {
    UP_frames[0] = {}; //set dimensions in the image 
    UP_frames[1] = {}; //set dimensions in the image 

    DOWN_frames[0] = {}; //set dimensions in the image 
    DOWN_frames[1] = {}; //set dimensions in the image 

    LEFT_frames[0] = {}; //set dimensions in the image 
    LEFT_frames[1] = {}; //set dimensions in the image 

    RIGHT_frames[0] = {}; //set dimensions in the image 
    RIGHT_frames[1] = {}; //set dimensions in the image
}

void Ash::SetUnit(Unit* unitt){
    curunit = unitt;
    if (curunit!=NULL){
        curunit->SetAsh(this);
        position.x = curunit->GetPos().x*Unit::width;
        position.y = curunit->GetPos().y*Unit::height;
    }
}

bool Ash::CheckCollision(SDL_Rect other_collider){

    if (collider.x + collider.w < other_collider.x ){
        return false;
    }

    if (collider.y + collider.h < other_collider.y ){
        return false;
    }

    if (collider.x > other_collider.x + other_collider.w ){
        return false;
    }
    
    if (collider.y > other_collider.y + other_collider.h ){
        return false;
    }

    return true;

    //CHECK

    /*if (collider.x + collider.w > other_collider.x && collider.x < other_collider.x ){
        return true;
    }

    if (collider.y + collider.h > other_collider.y && collider.y < other_collider.y ){
        return true;
    }

    if (other_collider.x + other_collider.w  > collider.x && collider.x > other_collider.x ){
        return true;
    }

    if (other_collider.y + other_collider.h  > collider.y && collider.y > other_collider.y ){
        return true;
    }

    return false;*/
}
bool Ash::CheckCollisionForTwo(SDL_Rect first_collider, SDL_Rect second_collider){

    if (first_collider.x + first_collider.w < second_collider.x ){
        return false;
    }

    if (first_collider.y + first_collider.h < second_collider.y ){
        return false;
    }

    if (first_collider.x > second_collider.x + second_collider.w ){
        return false;
    }
    
    if (first_collider.y > second_collider.y + second_collider.h ){
        return false;
    }

    return true;

}

bool Ash::Motion(){
    return isMoving;
}

SDL_Point Ash::GetPos()
{
    return position;
}

SDL_Rect Ash::GetCollider(){
    return collider;
}

Direction Ash::GetDirection(){
    return curdir;
}

Direction Ash::GetNextDirection(){
    return nextdir;
}

Unit* Ash::GetCurUnit(){
    return curunit;
}

Unit* Ash::GetNextUnit(){
    return nextunit;
}
