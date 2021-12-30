#include "irq.h"
#include <stdio.h>

int timer_ticks = 0;

void timer_handle(struct regs* r)
{
    timer_ticks++;

    if (timer_ticks % 18 == 0)
    {
        printf("One second has passed\n");
    }
}

void timer_install()
{
    irq_install_handler(0, timer_handle);
}
