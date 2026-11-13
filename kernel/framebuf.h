 /* ====================================================
 *		  _                      _____ _____ 
 *		 | |                    |  _  /  ___|
 *		 | |     __ _ _ __ _ __ | | | \ `--. 
 *		 | |    / _` | '__| '_ \| | | |`--. \ 
 *		 | |___| (_| | |  | |_) \ \_/ /\__/ /
 *		 \_____/\__,_|_|  | .__/ \___/\____/ 
 *                        | |                
 *                        |_|                
 *
 * ====================================================
 *
 * LarpOS is licensed under the MIT license
 * Copyright (c) 2026 David H.
 *
 * ====================================================
 */
 
#include <stdint.h>
#ifndef FRAMEBUF_H
#define FRAMEBUF_H 1

#include "limine.h"

void PutPixel(
    struct limine_framebuffer *fb,
    uint64_t x,
    uint64_t y,
    uint8_t r,
    uint8_t g,
    uint8_t b
);

void DrawRect(
    struct limine_framebuffer *fb,
    uint64_t x,
    uint64_t y,
    uint64_t w,
    uint64_t h,
    uint8_t r,
    uint8_t g,
    uint8_t b
);


#endif