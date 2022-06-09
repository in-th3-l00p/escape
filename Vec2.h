//
// Created by intheloop on 6/9/22.
//

#ifndef ESCAPE_VEC2_H
#define ESCAPE_VEC2_H

#include <iostream>
#include <string>

namespace Engine {
    template <typename T>
    class Vec2 {
    public:
        T x = 0, y = 0;

        Vec2() = default;
        Vec2(const Vec2& vec);
        Vec2(T x, T y);

        //basic operations
        Vec2<T> operator+(const Vec2<T>& vec);
        Vec2<T> operator-(const Vec2<T>& vec);
        Vec2<T> operator*(const Vec2<T>& vec);
        Vec2<T> operator*(const T& scalar);
        Vec2<T> operator/(const Vec2<T>& vec);
        Vec2<T> operator/(const T& scalar);
        Vec2<T> operator+=(const Vec2<T>& vec);
        Vec2<T> operator-=(const Vec2<T>& vec);
        Vec2<T> operator*=(const Vec2<T>& vec);
        Vec2<T> operator*=(const T& scalar);
        Vec2<T> operator/=(const Vec2<T>& vec);
        Vec2<T> operator/=(const T& scalar);
    };
} // Engine

//for printing
template <typename T>
std::ostream& operator<<(std::ostream& os, const Engine::Vec2<T>& vec);

#endif //ESCAPE_VEC2_H
