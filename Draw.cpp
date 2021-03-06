//
// Created by intheloop on 6/9/22.
//

#include "Draw.h"

namespace Engine {
    DrawHandler::DrawHandler(SDL_Renderer *renderer) {
        m_renderer = renderer;
        if (m_renderer == nullptr)
            throw std::runtime_error("invalid renderer");
    }

    void DrawHandler::point(const int& x, const int& y, const Color &color) const {
        if (m_renderer == nullptr)
            return;
        point(Vector2<int>{x, y}, color);
    }

    void DrawHandler::point(const Vector2<int> &pos, const Color &color) const {
        if (m_renderer == nullptr)
            return;
        color.setRenderColor(m_renderer);
        SDL_RenderDrawPoint(m_renderer, pos.x, pos.y);
    }

    void DrawHandler::pointf(const float &x, const float &y, const Color &color) const {
        point({static_cast<int>(std::round(x)), static_cast<int>(std::round(y))}, color);
    }

    void DrawHandler::pointf(const Vector2<float> &pos, const Color &color) const {
        point(pos.x, pos.y, color);
    }

    void DrawHandler::line(
            const Vector2<int> &pos1, const Vector2<int> &pos2, const Color& color
    ) const {
        if (m_renderer == nullptr)
            return;
        color.setRenderColor(m_renderer);
        SDL_RenderDrawLine(m_renderer,
               pos1.x, pos1.y, pos2.x, pos2.y
       );
    }

    void DrawHandler::linef(
            const Vector2<float> &pos1, const Vector2<float> &pos2, const Color &color
    ) const {
        line(
                Vector2<int>{
                    static_cast<int>(std::round(pos1.x)),
                    static_cast<int>(std::round(pos1.y))
                },
                Vector2<int>{
                    static_cast<int>(std::round(pos2.x)),
                    static_cast<int>(std::round(pos2.y))
                },
                color
        );
    }

    void DrawHandler::rectangle(
            const Vector2<int>& pos, const Vector2<int>& size, const Color& color
    ) const {
        if (m_renderer == nullptr || !size.x || !size.y)
            return;
        color.setRenderColor(m_renderer);

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

    void DrawHandler::rectanglef(
            const Vector2<float> &pos, const Vector2<float> &size, const Color &color
    ) const {
        rectangle(
                {
                    static_cast<int>(std::round(pos.x)),
                    static_cast<int>(std::round(pos.y))
                },
                {
                    static_cast<int>(std::round(size.x)),
                    static_cast<int>(std::round(size.y)),
                },
                color
        );
    }

    void DrawHandler::circle(
            const Vector2<int> &pos, const int &radius, const Color &color
    ) const {
        if (m_renderer == nullptr || !radius)
            return;
        color.setRenderColor(m_renderer);

        //Bresenhams algorithm
        Vector2<int> drawPos{0, radius};
        int d = 3 - 2 * radius;
        while (drawPos.x <= drawPos.y) {
            line(
                    {pos.x + drawPos.x, pos.y + drawPos.y},
                    {pos.x - drawPos.x, pos.y + drawPos.y},
                    color
            );
            line(
                    {pos.x + drawPos.x, pos.y - drawPos.y},
                    {pos.x - drawPos.x, pos.y - drawPos.y},
                    color
            );
            line(
                    {pos.x + drawPos.y, pos.y + drawPos.x},
                    {pos.x - drawPos.y, pos.y + drawPos.x},
                    color
            );
            line(
                    {pos.x + drawPos.y, pos.y - drawPos.x},
                    {pos.x - drawPos.y, pos.y - drawPos.x},
                    color
            );

            drawPos.x++;
            if (d > 0) {
                drawPos.y--;
                d = d + 4 * (drawPos.x - drawPos.y) + 10;
            } else
                d = d + 4 * drawPos.x + 6;
        }
    }

    void DrawHandler::circlef(const Vector2<float> &pos, const float &radius, const Color &color) const {
        circle(
                {
                    static_cast<int>(std::round(pos.x)),
                    static_cast<int>(std::round(pos.y))
                },
                static_cast<int>(radius), color
        );
    }


} // Engine