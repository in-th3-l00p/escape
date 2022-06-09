//
// Created by intheloop on 6/9/22.
//

#include "Utilities.h"

namespace Engine {
    template<typename T>
    Vector2<T>::Vector2(const Vector2 &vec) {
        x = vec.x;
        y = vec.y;
    }

    template<typename T>
    Vector2<T>::Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2<T>& vec) {
        Vector2<T> aux{*this};
        aux += vec;
        return aux;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2<T>& vec) {
        Vector2<T> aux{*this};
        aux -= vec;
        return aux;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator*(const Vector2<T>& vec) {
        Vector2<T> aux{*this};
        aux *= vec;
        return aux;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator*(const T& scalar) {
        Vector2<T> aux{*this};
        aux *= scalar;
        return aux;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator/(const Vector2<T>& vec) {
        Vector2<T> aux{*this};
        aux /= vec;
        return aux;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator/(const T& scalar) {
        Vector2<T> aux{*this};
        aux /= scalar;
        return aux;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator+=(const Vector2<T>& vec) {
        x += vec.x;
        y += vec.y;
        return *this;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator-=(const Vector2<T>& vec) {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator*=(const Vector2<T>& vec) {
        x *= vec.x;
        y *= vec.y;
        return *this;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator*=(const T& scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator/=(const Vector2<T>& vec) {
        x /= vec.x;
        y /= vec.y;
        return *this;
    }

    template<typename T>
    Vector2<T> Vector2<T>::operator/=(const T& scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Color::Color(Uint8 red, Uint8 green, Uint8 blue) {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    Color::Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
        : Color::Color(red, green, blue)
    {
        this->alpha = alpha;
    }

    void Color::setRenderColor(SDL_Renderer* renderer) const {
        SDL_SetRenderDrawBlendMode(
                renderer, (alpha == 255 ? SDL_BLENDMODE_NONE : SDL_BLENDMODE_BLEND)
        );
        SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    }

    //random generator
    RandomGenerator::RandomGenerator() {
        std::random_device dev;
        m_rng = std::make_unique<std::mt19937>(dev());
    }

    int RandomGenerator::random(const Vector2<int>& range) const {
        std::uniform_int_distribution<int> dist(range.x, range.y);
        return dist(*m_rng);
    }

    float RandomGenerator::random(const Vector2<float> &range) const {
        std::uniform_real_distribution<float> dist(range.x, range.y);
        return dist(*m_rng);
    }

    double RandomGenerator::random(const Vector2<double> &range) const {
        std::uniform_real_distribution<double> dist(range.x, range.y);
        return dist(*m_rng);
    }

    Uint8 RandomGenerator::random(const Vector2<Uint8> &range) const {
        std::uniform_int_distribution<Uint8> dist(range.x, range.y);
        return dist(*m_rng);
    }
} // Engine

//printing a vector2
template<typename T>
std::ostream& operator<<(std::ostream& os, const Engine::Vector2<T>& vec) {
    os << '{' << vec.x << ", " << vec.y << '}';
    return os;
}

//compile Vector2 only for scalar types
template class Engine::Vector2<int>;
template std::ostream& operator<<(std::ostream& os, const Engine::Vector2<int>& vec);
template class Engine::Vector2<float>;
template std::ostream& operator<<(std::ostream& os, const Engine::Vector2<float>& vec);
template class Engine::Vector2<double>;
template std::ostream& operator<<(std::ostream& os, const Engine::Vector2<double>& vec);
template class Engine::Vector2<Uint8>;
template std::ostream& operator<<(std::ostream& os, const Engine::Vector2<Uint8>& vec);
