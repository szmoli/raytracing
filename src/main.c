#include <stdio.h>
#include <math.h>
#include "../inc/vec4.h"
#include "../inc/rgba.h"

#include "../inc/glad.h"

#define RGFW_IMPLEMENTATION
#include "../inc/RGFW.h"

int main(int cargs, char** vargs) {
    const float aspect_ratio = 16.0f / 10.0f;
    const int win_w = 1000;
    const int win_h = win_w / aspect_ratio;

    RGFW_window* win = RGFW_createWindow("Raytracing", RGFW_RECT(0, 0, win_w, win_h), RGFW_windowCenter | RGFW_windowNoResize);
    RGFW_window_makeCurrent(win);

    while (RGFW_window_shouldClose(win) == 0) {
        RGFW_event* ev = RGFW_window_checkEvent(win);
        switch (win->event.type) {
        case RGFW_quit:
            RGFW_window_setShouldClose(win);
            break;        
        default:
            break;
        }
    }    

    RGFW_window_close(win);
    return 0;
}