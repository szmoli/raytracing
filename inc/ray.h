#ifndef RAY_H
#define RAY_H

#include "vec4.h"

typedef struct {
    vec4 orig;     // point of origin
    vec4 dir;   // direction vector
} ray;

/**
 * Calculates the point on the given ray based on the t parameter. Takes a pointer to the ray for memory efficiency.
 * @param r The pointer of the ray
 * @param t The t parameter
 */
vec4 rat(const ray* r, float t) {
    return (vec4){vadd(r->orig, vscale(r->dir, t))};
}

#endif