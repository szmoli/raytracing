#include "stdio.h"
#include "math.h"

int main(int cargs, char** vargs) {
    const int img_w = 256;
    const int img_h = 256;

    FILE* file = fopen("renders/render0.ppm", "w");
    printf("started rendering...\n");

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", img_w, img_h);
    fprintf(file, "255\n");
    for (int y = 0; y < img_h; ++y) {
        for (int x = 0; x < img_w; ++x) {
            float r = (float)x / (img_w - 1);
            float g = (float)y / (img_h - 1);
            float b = 0;
            int ir = (int)(r * 255);
            int ig = (int)(g * 255);
            int ib = (int)(b * 255);
            fprintf(file, "%d %d %d", ir, ig, ib);
            if (!(y == img_h - 1 && x == img_w - 1)) {
                fprintf(file, "\n");
            }
        }
    }

    fclose(file);
    printf("finished rendering.\n");
}