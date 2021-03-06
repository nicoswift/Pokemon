#include "Squirtle.h"

Squirtle::Squirtle (Unit* Unitx, Texture* texture){

    curunit = Unitx;
    ftexture = texture;

    if (Unitx!=NULL){
        fposition.x = Unitx->GetPos.x*width;
        fposition.y = Unitx->GetPos.x*height;
    }else{
        fposition.x = 0;
        fposition.y = 0;
    }

}

void Squirtle::SetUnit(Unit *unitt)
{

    curunit = unit;

    if (curunit != NULL)
    {
        curunit.SetSquirtle(this);

        fposition.x = curunit.GetPos().x * Unit::width;
        fposition.y = curunit.GetPos().y * Unit::height;
    }
}


void Squirtle::Render(){
    ftexture->Render(fposition.x, fposition.y);
}

SDL_Point Squirtle::GetPos(){
    return fposition;
}

SDL_Rect Squirtle::GetCollider(){
    return collider;
}

Unit Squirtle::GetCurUnit(){
    return curunit;
}

SDL_Rect Squirtle::GetPos(){
    return fposition;
}

