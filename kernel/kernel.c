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

__attribute__((used, section(".limine_requests")))
static volatile uint64_t limine_base_revision[] = LIMINE_BASE_REVISION(6);

void kmain(void)
{
    if (!LIMINE_BASE_REVISION_SUPPORTED(limine_base_revision))
    {
        while (1)
        {
            __asm__ volatile ("cli; hlt");
        }
    }

    while (1)
    {
        __asm__ volatile ("hlt");
    }
}