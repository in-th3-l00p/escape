//
// Created by intheloop on 6/9/22.
//

#ifndef ESCAPE_DRAW_H
#define ESCAPE_DRAW_H

#include <SDL2/SDL.h>
#include <exception>
#include "Utilities.h"

namespace Engine {
    class DrawHandler {
    private:
        //main renderer pointer
        SDL_Renderer* m_renderer;

    public:
        explicit DrawHandler(SDL_Renderer* renderer);

        void line(
                const Vector2<int>& pos1, const Vector2<int>& pos2, const Color& color
        ) const;
        void rectangle(
                const Vector2<int>& pos, const Vector2<int>& size, const Color& color
        ) const;
    };
} // Engine

#endif //ESCAPE_DRAW_H
