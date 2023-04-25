#include "extras.h"
#include "idt.h"
#include "irq.h"
#include "IOPort.h"
#include <stdint.h>

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

// Array to hold function pointers, so we can handle custom 
// IRQ handlers for a given IRQ
void* irq_routines[16] = 
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

void irq_install_handler(int32_t irq, void (*handler)(struct regs *r))
{
    irq_routines[irq] = handler;
}

void irq_uninstall_handler(int32_t irq)
{
    irq_routines[irq] = 0;
}

// Now, the default mappings from IRQ to IDT entries cause a conflict.
// IRQs 0 - 7 are mapped (by default) to IDT entries 8 - 15, but the
// CPU expects IDT entries 0 - 32 for exception ISRs. So remap the IRQs
// to go into the unoccupied slots
void irq_remap()
{
    // starts the initialization sequence (in cascade mode)
    outb(0x20, 0x11);   // init both the slave and master PICs
    io_wait();
    outb(0xA0, 0x11);
    io_wait();

    outb(0x21, 0x20);   // map irqs with an offset of 32 (instead of the default value of 8)
    io_wait();
    outb(0xA1, 0x28);   // map irqs for the slave with an offset of 40
    io_wait();

    outb(0x21, 0x04);   // tell master PIC that there's a slave connected to IRQ2 (0000 0100)
    io_wait();
    outb(0xA1, 0x02);   // tell slave PIC its cascade identity
    io_wait();

    // Set master and slave PICs to 8086/88 mode
    outb(0x21, 0x01);   
    io_wait();
    outb(0xA1, 0x01);
    io_wait();

    // restore the saved masks
    outb(0x21, 0);
    outb(0xA1, 0);
}

void irq_install()
{
    irq_remap();

    constructIdtEntry(32, (uint32_t) irq0, 0x08, 0x8E);
    constructIdtEntry(33, (uint32_t) irq1, 0x08, 0x8E);
    constructIdtEntry(34, (uint32_t) irq2, 0x08, 0x8E);
    constructIdtEntry(35, (uint32_t) irq3, 0x08, 0x8E);
    constructIdtEntry(36, (uint32_t) irq4, 0x08, 0x8E);
    constructIdtEntry(37, (uint32_t) irq5, 0x08, 0x8E);
    constructIdtEntry(38, (uint32_t) irq6, 0x08, 0x8E);
    constructIdtEntry(39, (uint32_t) irq7, 0x08, 0x8E);
    constructIdtEntry(40, (uint32_t) irq8, 0x08, 0x8E);
    constructIdtEntry(41, (uint32_t) irq9, 0x08, 0x8E);
    constructIdtEntry(42, (uint32_t) irq10, 0x08, 0x8E);
    constructIdtEntry(43, (uint32_t) irq11, 0x08, 0x8E);
    constructIdtEntry(44, (uint32_t) irq12, 0x08, 0x8E);
    constructIdtEntry(45, (uint32_t) irq13, 0x08, 0x8E);
    constructIdtEntry(46, (uint32_t) irq14, 0x08, 0x8E);
    constructIdtEntry(47, (uint32_t) irq15, 0x08, 0x8E);
}

void irq_handler(struct regs* r)
{
    // Blank function pointer
    void (*handler)(struct regs* r);

    // Get the corresponding handler for the interrupt type
    handler = irq_routines[r->int_no - 32];

    if (handler)
    {
        handler(r);
    }

    // IRQ should have been handled at this point, we can begin
    // sending EOI (end of interrupts) (0x20) to the slave and master

    // If the IRQ came from the master, only need to send an EOI
    // to just the master.
    
    // If the IRQ came from the slave, then need to send EOI to
    // both, since the slave is connected to the master.

    if ((r->int_no - 32) >= 8)
    {
        outb(0xA0, 0x20);
    }
    outb(0x20, 0x20);
}
