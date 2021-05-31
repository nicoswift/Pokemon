#include "Texture.h"
#include "Matrix.h"


class Gastly{

    public:
    int width = 20;
    int height = 20;

    SDL_Point fposition;
    Unit* curunit;
    Texture* ftexture;
    SDL_Rect collider;

    Gastly (Unit* Unitx, Texture* texture);

    void SetUnit(Unit* unitt);
    
    void Render();

    SDL_Rect GetCollider();

    Unit GetCurUnit();

    SDL_Rect GetPos();

}