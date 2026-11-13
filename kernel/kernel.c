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

#include <stddef.h>
#include <stdint.h>
#include "limine.h"
#include "framebuf.h"

// Start requests
__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t limine_requests_start[] = LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests")))
static volatile uint64_t limine_base_revision[] = LIMINE_BASE_REVISION(6);

__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request fb_req = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

// End requests
__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limine_requests_end[] =
    LIMINE_REQUESTS_END_MARKER;

void KernelMain(void)
{
    if (!LIMINE_BASE_REVISION_SUPPORTED(limine_base_revision))
    {
        while (1)
        {
            __asm__ volatile ("cli; hlt");
        }
    }

    if (fb_req.response == NULL || fb_req.response->framebuffer_count < 1)
    {
        while (1)
        {
            __asm__ volatile ("hlt");
        }
    }

    struct limine_framebuffer *fb = fb_req.response->framebuffers[0];

    if (
        fb->bpp != 32 || // We only support 32bpp
        fb->memory_model != LIMINE_FRAMEBUFFER_RGB
    )
    {
        while (1)
        {
            __asm__ volatile ("hlt");
        }
    }

    // Fill screen!!! :D
    DrawRect(fb, 0, 0, fb->width, fb->height, 5, 7, 20);
    DrawRect(fb, 20, 20, 80, 80, 255, 255, 255);

    while (1)
    {
        __asm__ volatile ("hlt");
    }
}