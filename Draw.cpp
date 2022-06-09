//
// Created by intheloop on 6/9/22.
//

#include "Draw.h"

namespace Engine {
    DrawHandler::DrawHandler(SDL_Renderer *renderer) {
        m_renderer = renderer;
        if (m_renderer == nullptr)
            std::runtime_error("invalid renderer");
    }

    void DrawHandler::rectangle(
            const Vector2<int>& pos,
            const Vector2<int>& size,
            const Color& color
    ) const {
        color.setRenderColor(m_renderer);

        //checking for special cases
        if (size.x == 0 || size.y == 0)
            return;

        if (size.x == 1) {
            SDL_RenderDrawLine(
                    m_renderer, pos.x, pos.y, pos.x, pos.y + size.y
            );
            return;
        } else if (size.y == 1) {
            SDL_RenderDrawLine(
                    m_renderer, pos.x, pos.y, pos.x + size.x, pos.y
            );
            return;
        }

        //for the normal case
        SDL_Rect sdlRect = {pos.x, pos.y, size.x, size.y};
        SDL_RenderFillRect(m_renderer, &sdlRect);
    }
} // Engine