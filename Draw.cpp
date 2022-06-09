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

    void DrawHandler::line(
            const Vector2<int> &pos1, const Vector2<int> &pos2, const Color& color
    ) const {
        color.setRenderColor(m_renderer);
        SDL_RenderDrawLine(m_renderer,
               pos1.x, pos1.y, pos2.x, pos2.y
       );
    }

    void DrawHandler::rectangle(
            const Vector2<int>& pos, const Vector2<int>& size, const Color& color
    ) const {
        color.setRenderColor(m_renderer);

        //checking for special cases
        if (!size.x || !size.y)
            return;

        if (size.x == 1) {
            Vector2<int> pos2 = pos;
            pos2.y += size.y;
            line(pos, pos2, color);
            return;
        } else if (size.y == 1) {
            Vector2<int> pos2 = pos;
            pos2.x += size.x;
            line(pos, pos2, color);
            return;
        }

        //for the normal case
        SDL_Rect sdlRect = {pos.x, pos.y, size.x, size.y};
        SDL_RenderFillRect(m_renderer, &sdlRect);
    }
} // Engine