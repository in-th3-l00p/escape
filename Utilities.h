//
// Created by intheloop on 6/9/22.
//

#ifndef ESCAPE_UTILITIES_H
#define ESCAPE_UTILITIES_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <random>
#include <memory>
#include <sstream>

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

    //todo: better implementation (more minimalistic)
    class RandomGenerator {
    private:
        std::unique_ptr<std::mt19937> m_rng;
    public:
        RandomGenerator();
        int random(const Vector2<int>& range) const;
        float random(const Vector2<float>& range) const;
        double random(const Vector2<double>& range) const;
        Uint8 random(const Vector2<Uint8>& range) const;
    };

    namespace uuid {
        static std::random_device dev;
        static std::mt19937 gen(dev());
        static std::uniform_int_distribution<> dist1(0, 15);
        static std::uniform_int_distribution<> dist2(8, 11);

        //todo: maybe return as a 128 bit data type
        inline std::string generateUUID4() {
            std::stringstream ss;
            ss << std::hex;
            for (int i = 0; i < 8; i++)
                ss << dist1(gen);
            ss << '-';
            for (int i = 0; i < 4; i++)
                ss << dist1(gen);
            ss << "-4";
            for (int i = 0; i < 3; i++)
                ss << dist1(gen);
            ss << '-' << dist2(gen);
            for (int i = 0; i < 3; i++)
                ss << dist1(gen);
            ss << '-';
            for (int i = 0; i < 12; i++)
                ss << dist1(gen);
            return ss.str();
        }
    }
} // Engine

//for printing a vector2
template <typename T>
std::ostream& operator<<(std::ostream& os, const Engine::Vector2<T>& vec);

#endif //ESCAPE_UTILITIES_H
