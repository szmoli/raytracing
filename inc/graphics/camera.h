#ifndef CAMERA_H
#define CAMERA_H

#include "../geometry/vec4.h"
#include "../geometry/mat4.h"

typedef struct {
    vec4 center;
    float w;
    float h;
} camera;



#endif