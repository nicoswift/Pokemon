#pragma once
#include "Gastly.h"
#include "Wall.h"

Gastly::Gastly (Unit* Unitx, Texture* texture){

    curunit = Unitx;
    ftexture = texture;

    if (Unitx!=NULL){
        fposition.x = Unitx->GetPos().x*width;
        fposition.y = Unitx->GetPos().x*height;
    }else{
        fposition.x = 0;
        fposition.y = 0;
    }


}

void Gastly::Render(){
    ftexture->Render(fposition.x, fposition.y);
}

SDL_Point Gastly::GetPos(){
    return fposition;
}


SDL_Rect Gastly::GetCollider(){
    return collider;
}

Unit* Gastly::GetCurUnit(){
    return curunit;
}

