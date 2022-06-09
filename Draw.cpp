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
        for (int x = pos.x; x <= pos.x + size.x; x++)
            for (int y = pos.y; y < pos.y + size.y; y++)
                SDL_RenderDrawPoint(m_renderer, x, y);
    }
} // Engine