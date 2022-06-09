//
// Created by intheloop on 6/9/22.
//

#ifndef ESCAPE_UTILITIES_H
#define ESCAPE_UTILITIES_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

namespace Engine {
    template <typename T>
    struct Vector2 {
        T x = 0, y = 0;

        Vector2() = default;
        Vector2(const Vector2& vec);
        Vector2(T x, T y);

        //basic operations
        Vector2<T> operator+(const Vector2<T>& vec);
        Vector2<T> operator-(const Vector2<T>& vec);
        Vector2<T> operator*(const Vector2<T>& vec);
        Vector2<T> operator*(const T& scalar);
        Vector2<T> operator/(const Vector2<T>& vec);
        Vector2<T> operator/(const T& scalar);
        Vector2<T> operator+=(const Vector2<T>& vec);
        Vector2<T> operator-=(const Vector2<T>& vec);
        Vector2<T> operator*=(const Vector2<T>& vec);
        Vector2<T> operator*=(const T& scalar);
        Vector2<T> operator/=(const Vector2<T>& vec);
        Vector2<T> operator/=(const T& scalar);
    };

    using Uint8 = unsigned char;
    struct Color {
        Uint8 red = 255, green = 255, blue = 255, alpha = 255;

        //constructors
        Color() = default;
        Color(Uint8 red, Uint8 green, Uint8 blue);
        Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

        //methods
        void setRenderColor(SDL_Renderer* renderer) const;
    };
} // Engine

//for printing
template <typename T>
std::ostream& operator<<(std::ostream& os, const Engine::Vector2<T>& vec);

#endif //ESCAPE_UTILITIES_H
