#include "Wall.h"

Zoroark::Zoroark (Unit* Unitx, Texture* texture){

    curunit = Unitx;
    ftexture = texture;

    if (Unitx!=NULL){
        fposition.x = Unitx->GetPos.x*fwidth;
        fposition.y = Unitx->GetPos.x*fheight;
    }else{
        fposition.x = 0;
        fposition.y = 0;
    }

}

void Zoroark::Render(){
    ftexture->Render(fposition.x, fposition.y);
}

SDL_Point Zoroark::GetPos(){
    return fposition;
}


SDL_Rect Zoroark::GetCollider(){
    return collider;
}

Unit Zoroark::GetCurUnit(){
    return curunit;
}

SDL_Rect Zoroark::GetPos(){
    return fposition;
}
