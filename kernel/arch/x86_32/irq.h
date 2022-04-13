#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>
#include "extras.h"

void irq_install_handler(int32_t, void (*)(struct regs*));

#endif /* IRQ_H */

