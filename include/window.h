#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect rect; // pos.x, pos.y, scale.x, scale.y
    SDL_bool is_open;

} Window;

Window window_newWindow(unsigned int width, unsigned int height);
void window_renderWindow(Window *window);
void window_DestroyWindow(Window *window);