#ifndef COLOR_H
#define COLOR_H
#include "Vec3.h"
#include <iostream>

namespace Color {
    using color = vec3;
    void write_color(std::ostream& out, const color& pixel_color);
}

#endif
