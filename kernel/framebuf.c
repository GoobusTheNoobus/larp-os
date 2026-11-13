#include "framebuf.h"
#include <stdint.h>

void PutPixel(
    struct limine_framebuffer *fb, 
    uint64_t x, 
    uint64_t y, 
    uint8_t r, 
    uint8_t g, 
    uint8_t b
) 
{
    // Out of bounds!
    if (x >= fb->width || y >= fb->height)
        return; 

    // We don't just do address + y * width, since there might be padding
    volatile uint8_t *row = (volatile uint8_t*)fb->address + y * fb->pitch;
    volatile uint32_t *pixel = (volatile uint32_t*)(row + x * 4);

    uint32_t color =
        ((uint32_t)r << fb->red_mask_shift) |
        ((uint32_t)g << fb->green_mask_shift) |
        ((uint32_t)b << fb->blue_mask_shift);
    *pixel = color;
}

void DrawRect(
    struct limine_framebuffer *fb,
    uint64_t x,
    uint64_t y,
    uint64_t w,
    uint64_t h,
    uint8_t r,
    uint8_t g,
    uint8_t b
) 
{
    for (uint64_t x_ = x; x_ < x + w; ++x_) 
    {
        for (uint64_t y_ = y; y_ < y + h; ++y_) 
        {
            PutPixel(fb, x_, y_, r, g, b);
        }  
    }
}