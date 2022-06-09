//
// Created by intheloop on 6/9/22.
//

#include "Vec2.h"

namespace Engine {
    template<typename T>
    Vec2<T>::Vec2(const Vec2 &vec) {
        x = vec.x;
        y = vec.y;
    }

    template<typename T>
    Vec2<T>::Vec2(T x, T y) {
        this->x = x;
        this->y = y;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator+(const Vec2<T>& vec) {
        Vec2<T> aux{*this};
        aux += vec;
        return aux;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator-(const Vec2<T>& vec) {
        Vec2<T> aux{*this};
        aux -= vec;
        return aux;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator*(const Vec2<T>& vec) {
        Vec2<T> aux{*this};
        aux *= vec;
        return aux;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator*(const T& scalar) {
        Vec2<T> aux{*this};
        aux *= scalar;
        return aux;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator/(const Vec2<T>& vec) {
        Vec2<T> aux{*this};
        aux /= vec;
        return aux;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator/(const T& scalar) {
        Vec2<T> aux{*this};
        aux /= scalar;
        return aux;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator+=(const Vec2<T>& vec) {
        x += vec.x;
        y += vec.y;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator-=(const Vec2<T>& vec) {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator*=(const Vec2<T>& vec) {
        x *= vec.x;
        y *= vec.y;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator*=(const T& scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator/=(const Vec2<T>& vec) {
        x /= vec.x;
        y /= vec.y;
        return *this;
    }

    template<typename T>
    Vec2<T> Vec2<T>::operator/=(const T& scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
} // Engine

template<typename T>
std::ostream& operator<<(std::ostream& os, const Engine::Vec2<T>& vec) {
    os << '{' << vec.x << ", " << vec.y << '}';
    return os;
}

//only for scalar types
template class Engine::Vec2<int>;
template std::ostream& operator<<(std::ostream& os, const Engine::Vec2<int>& vec);
template class Engine::Vec2<float>;
template std::ostream& operator<<(std::ostream& os, const Engine::Vec2<float>& vec);
template class Engine::Vec2<double>;
template std::ostream& operator<<(std::ostream& os, const Engine::Vec2<double>& vec);
