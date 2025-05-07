#ifndef RGBA_H
#define RGBA_H

#include <stdbool.h>
#include "../geometry/vec4.h"

/**
 * Writes RGB color to the given file.
 * @param file The file to write to
 * @param rgba The RGBA color to write
 * @param newline Write a new line or not
 */
void write_color(FILE* file, vec4 rgba, bool newline) {
    fprintf(file, "%d %d %d", (int)(255 * rgba.x), (int)(255 * rgba.y), (int)(255 * rgba.z));
    if (newline) {
        fprintf(file, "\n");
    }
}

#endif