#include "Texture.h"
#include "Unit.h"
#include "Matrix.h"
#include "Element.h"

class Pokeball : public Element {

    public:
    int width = 20;
    int height = 20;

    SDL_Point position;
    Unit* curunit;
    Texture* ftexture;

    SDL_Rect collider;

    Pokeball (Unit* Unitx, Texture* texture);

    void Render();

    void SetUnit(Unit* unitt);

    SDL_Rect GetCollider();

    Unit* GetCurUnit();

    SDL_Point GetPos();
};