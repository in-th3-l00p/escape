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
        DrawHandler() = default;
        explicit DrawHandler(SDL_Renderer* renderer);

        //todo: change this code pls it's baddd, add templates or sum
        void point(const int& x, const int& y, const Color& color) const;
        void point(const Vector2<int>& pos, const Color& color) const;
        void pointf(const float& x, const float& y, const Color& color) const;
        void pointf(const Vector2<float>& pos, const Color& color) const;

        void line(
                const Vector2<int>& pos1, const Vector2<int>& pos2, const Color& color
        ) const;
        void linef(
                const Vector2<float>& pos1, const Vector2<float>& pos2, const Color& color
        ) const;

        void rectangle(
                const Vector2<int>& pos, const Vector2<int>& size, const Color& color
        ) const;
        void rectanglef(
                const Vector2<float>& pos, const Vector2<float>& size, const Color& color
        ) const;

        void circle(
                const Vector2<int>& pos, const int& radius, const Color& color
        ) const;
        void circlef(
                const Vector2<float>& pos, const float& radius, const Color& color
        ) const;
    };
} // Engine

#endif //ESCAPE_DRAW_H
