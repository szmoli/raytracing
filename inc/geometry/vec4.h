#ifndef VEC4_H
#define VEC4_H

#include <math.h>
#include <stdio.h>
#include <malloc.h>

typedef struct {
    float x;
    float y;
    float z;
    float w;
} vec4;

/**
 * Negates the given vector.
 * @param v Vector to negate
 * @return Negated vector
 */
vec4 vnegate(vec4 v) {
    return (vec4){-v.x, -v.y, -v.z, -v.w};
}

/**
 * Adds two vectors.
 * @param u First vector
 * @param v Second vector
 * @return Result from the addition
 */
vec4 vadd(vec4 u, vec4 v) {
    return (vec4){u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w};
}

/**
 * Substract two vectors.
 * @param u Vector to substract from (end)
 * @param v Vector to substarct (start)
 * @return Result from the substraction
 */
vec4 vsub(vec4 u, vec4 v) {
    return vadd(u, vnegate(v));
}

/**
 * Scales a vector.
 * @param v Vector to scale
 * @param s Scalar
 * @return Result from the scaling
 */
vec4 vscale(vec4 v, float s) {
    return (vec4){v.x * s, v.y * s, v.z * s, v.w * s};
}

/**
 * Calculates the dot product of two vectors.
 * @param u First vector
 * @param v Second vector
 * @return The dot product
 */
float vdot(vec4 u, vec4 v) {
    return u.x * v.x
         + u.y * v.y
         + u.z * v.z
         + u.w * v.w;
}

/**
 * Calculates the cross product of two vectors.
 * @param u First vector
 * @param v Second vector
 * @return The cross product
 */
vec4 vcross(vec4 u, vec4 v) {
    return (vec4){
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x,
        0.0f
    };
}

/**
 * Calculates the length of the given vector.
 * @param v The vector
 * @return The length of the vector
 */
float vlength(vec4 v) {
    return sqrtf(v.x * v.x
               + v.y * v.y
               + v.z * v.z
               + v.w * v.w
    );
}

/**
 * Normalizes the given vector to a unit vector.
 * @param v The vector
 * @return The normalized vector
 */
vec4 vnormalize(vec4 v) {
    float len = vlength(v);
    if (len == 0.0f) {
        return (vec4){0.0f, 0.0f, 0.0f, 0.0f};
    }
    return vscale(v, 1 / vlength(v));
}

/**
 * Returns the string form of a given vector. Uses malloc to allocate memory. The caller needs to call free() to avoid memory leaks.
 * @param v The vector
 * @return The string form of the vector
 */
char* vstring(vec4 v) {
    int len = snprintf(NULL, 0, "(%f, %f, %f, %f)", v.x, v.y, v.z, v.w);
    char* res = (char*)malloc(len + 1);
    snprintf(res, len + 1, "(%f, %f, %f, %f)", v.x, v.y, v.z, v.w);
    return res;
}

#endif