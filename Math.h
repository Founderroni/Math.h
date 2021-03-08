#pragma once

#include <math.h>

/*
* thanks to EchoHackCmd for letting me use and modify his code
* all functions use and return values in radians (-pi to pi)
* -pi -> 0 -> pi -> -pi...
*/

#define PI 3.14159265359 //pi
#define PI2 6.28318530718 //2pi
#define PI_DIV_2 1.57079632679 //pi/2
#define PI_DIV_180 0.01745329251 //pi/180
#define PI_180_DIV 57.2957795131 //180/pi

#define INRANGE(x, a, b)    (x >= a && x <= b)
#define MAX(a, b)    ((a < b) ? b : a)
#define MIN(a, b)    ((a < b) ? a : b)

struct vec2 {
    union {
        struct {
            float x, y;
        };
        float arr[2]{};
    };

    vec2() { x = y = 0; }

    vec2(float x, float y) : x(x), y(y) {}

    bool operator==(vec2 v) const { return v.x == x && v.y == y; };

    bool operator!=(vec2 v) const { return v.x != x || v.y != y; };

    /* Add */

    [[nodiscard]] vec2 add(float f) const {
        return {x + f, y + f};
    }

    [[nodiscard]] vec2 add(float a, float b) const {
        return {x + a, y + b};
    }

    [[nodiscard]] vec2 add(vec2 o) const {
        return {x + o.x, y + o.y};
    }

    /* Subtract */

    [[nodiscard]] vec2 sub(float f) const {
        return {x - f, y - f};
    }

    [[nodiscard]] vec2 sub(float a, float b) const {
        return {x - a, x - b};
    }

    [[nodiscard]] vec2 sub(vec2 o) const {
        return vec2(x - o.x, y - o.y);
    }

    /* Divide */

    [[nodiscard]] vec2 div(float f) const {
        return vec2(x / f, y / f);
    }

    [[nodiscard]] vec2 div(float a, float b) const {
        return vec2(x / a, y / b);
    }

    [[nodiscard]] vec2 div(vec2 o) const {
        return vec2(x / o.x, y / o.y);
    }

    /* Multiply */

    [[nodiscard]] vec2 mult(float f) const {
        return vec2(x * f, y * f);
    }

    [[nodiscard]] vec2 mult(float a, float b) const {
        return vec2(x * a, y * b);
    }

    [[nodiscard]] vec2 mult(vec2 o) const {
        return vec2(x * o.x, y * o.y);
    }

    /* Other */

    [[nodiscard]] vec2 toRad() {
        //rad = deg * pi/180;
        return vec2(x * PI_DIV_180, y * PI_DIV_180);
    }

    [[nodiscard]] vec2 toDeg() {
        //deg = rad * 180/pi;
        return vec2(x * PI_180_DIV, y * PI_180_DIV);
    }

    [[nodiscard]] int distance(const vec2 o) const {
        int dX = x - o.x;
        int dY = y - o.y;
        return sqrt(dX * dX + dY * dY);
    }
};

struct vec3 {
    union {
        struct {
            float x, y, z;
        };
        float arr[3]{};
    };

    vec3() { x = y = z = 0; }

    vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    bool operator==(vec3 v) const { return v.x == x && v.y == y && v.z == z; };

    bool operator!=(vec3 v) const { return v.x != x || v.y != y || v.z != z; };

    /* Add */

    [[nodiscard]] vec3 add(float f) const {
        return vec3(x + f, y + f, z + f);
    }

    [[nodiscard]] vec3 add(float a, float b, float c) const {
        return vec3(x + a, y + b, z + c);
    }

    [[nodiscard]] vec3 add(vec3 o) const {
        return vec3(x + o.x, y + o.y, z + o.z);
    }

    /* Subtract */

    [[nodiscard]] vec3 sub(float f) const {
        return vec3(x - f, y - f, z - f);
    }

    [[nodiscard]] vec3 sub(float a, float b, float c) const {
        return vec3(x - a, x - b, z - c);
    }

    [[nodiscard]] vec3 sub(vec3 o) const {
        return vec3(x - o.x, y - o.y, z - o.z);
    }

    /* Divide */

    [[nodiscard]] vec3 div(float f) const {
        return vec3(x / f, y / f, z / f);
    }

    [[nodiscard]] vec3 div(float a, float b, float c) const {
        return vec3(x / a, y / b, z / c);
    }

    [[nodiscard]] vec3 div(vec3 o) const {
        return vec3(x / o.x, y / o.y, z / o.y);
    }

    /* Multiply */

    [[nodiscard]] vec3 mult(float f) const {
        return vec3(x * f, y * f, z * f);
    }

    [[nodiscard]] vec3 mult(float a, float b, float c) const {
        return vec3(x * a, y * b, z * c);
    }

    [[nodiscard]] vec3 mult(vec3 o) const {
        return vec3(x * o.x, y * o.y, z * o.z);
    }

    /* Other */

    [[nodiscard]] vec3 floor() const {
        return vec3(floorf(x), floorf(y), floorf(z));
    }

    [[nodiscard]] float magnitude() const {
        return sqrtf(x * x + y * y + z * z);
    }

    [[nodiscard]] float magnitudexy() const {
        return sqrtf(x * x + y * y);
    }

    [[nodiscard]] float magnitudexz() const {
        return sqrtf(x * x + z * z);
    }

    [[nodiscard]] vec3 normalize() const {
        return div(magnitude());
    };

    [[nodiscard]] float distance(vec3 o) const {
        float dX = x - o.x;
        float dY = y - o.y;
        float dZ = z - o.z;
        return sqrt(dX * dX + dY * dY + dZ * dZ);
    }
};

class Math {
public:
    static float toRad(const float degAngle);

    static float toDeg(const float radAngle);

    static vec2 rotatePoint(const vec2 pointPos, const float angle);

    static vec2 getAngles(const vec3 playerPos, const vec3 lookPos);
};

float Math::toRad(const float degAngle) {
    //rad = deg * pi/180;
    return float(degAngle * PI_DIV_180);
}

float Math::toDeg(const float radAngle) {
    //deg = rad * 180/pi;
    return float(radAngle * PI_180_DIV);
}

/*point rotation around [0,0]*/
vec2 Math::rotatePoint(static vec2 pointPos, static float angle) {
    float cosTheta = cos(-angle);
    float sinTheta = sin(-angle);
    return vec2(
            cosTheta * (pointPos.x) - sinTheta * (pointPos.y),
            sinTheta * (pointPos.x) + cosTheta * (pointPos.y)
    );
}

/*player position to lookPos rotations*/
vec2 Math::getAngles(const vec3 playerPos, const vec3 lookPos) {
    float dX = playerPos.x - lookPos.x;
    float dY = playerPos.y - lookPos.y;
    float dZ = playerPos.z - lookPos.z;
    double distance = sqrt(dX * dX + dY * dY + dZ * dZ);
    return vec2(
            atan2(dY, distance),
            atan2(dZ, dX) + PI_DIV_2
    );
}
