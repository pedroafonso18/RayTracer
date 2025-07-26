#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
public:
    Ray() = default;

    Ray(const vec3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    [[nodiscard]] const vec3& origin() const  { return orig; }
    [[nodiscard]] const vec3& direction() const { return dir; }

    [[nodiscard]] vec3 at(double t) const {
        return orig + t*dir;
    }

private:
    vec3 orig;
    vec3 dir;
};

#endif