#include "extras.h"
#include "idt.h"
#include <stdio.h>

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();


void isrs_install()
{
    constructIdtEntry(0, (uint32_t) isr0, 0x08, 0x8E);
    constructIdtEntry(1, (uint32_t) isr1, 0x08, 0x8E);
    constructIdtEntry(2, (uint32_t) isr2, 0x08, 0x8E);
    constructIdtEntry(3, (uint32_t) isr3, 0x08, 0x8E);
    constructIdtEntry(4, (uint32_t) isr4, 0x08, 0x8E);
    constructIdtEntry(5, (uint32_t) isr5, 0x08, 0x8E);
    constructIdtEntry(6, (uint32_t) isr6, 0x08, 0x8E);
    constructIdtEntry(7, (uint32_t) isr7, 0x08, 0x8E);
    constructIdtEntry(8, (uint32_t) isr8, 0x08, 0x8E);
    constructIdtEntry(9, (uint32_t) isr9, 0x08, 0x8E);
    constructIdtEntry(10, (uint32_t) isr10, 0x08, 0x8E);
    constructIdtEntry(11, (uint32_t) isr11, 0x08, 0x8E);
    constructIdtEntry(12, (uint32_t) isr12, 0x08, 0x8E);
    constructIdtEntry(13, (uint32_t) isr13, 0x08, 0x8E);
    constructIdtEntry(14, (uint32_t) isr14, 0x08, 0x8E);
    constructIdtEntry(15, (uint32_t) isr15, 0x08, 0x8E);
    constructIdtEntry(16, (uint32_t) isr16, 0x08, 0x8E);
    constructIdtEntry(17, (uint32_t) isr17, 0x08, 0x8E);
    constructIdtEntry(18, (uint32_t) isr18, 0x08, 0x8E);
    constructIdtEntry(19, (uint32_t) isr19, 0x08, 0x8E);
    constructIdtEntry(20, (uint32_t) isr20, 0x08, 0x8E);
    constructIdtEntry(21, (uint32_t) isr21, 0x08, 0x8E);
    constructIdtEntry(22, (uint32_t) isr22, 0x08, 0x8E);
    constructIdtEntry(23, (uint32_t) isr23, 0x08, 0x8E);
    constructIdtEntry(24, (uint32_t) isr24, 0x08, 0x8E);
    constructIdtEntry(25, (uint32_t) isr25, 0x08, 0x8E);
    constructIdtEntry(26, (uint32_t) isr26, 0x08, 0x8E);
    constructIdtEntry(27, (uint32_t) isr27, 0x08, 0x8E);
    constructIdtEntry(28, (uint32_t) isr28, 0x08, 0x8E);
    constructIdtEntry(29, (uint32_t) isr29, 0x08, 0x8E);
    constructIdtEntry(30, (uint32_t) isr30, 0x08, 0x8E);
    constructIdtEntry(31, (uint32_t) isr31, 0x08, 0x8E);
}

const char* exception_messages[] = 
{
    "Division by zero",
    "Debug",
    "Non Maskable Interrupt Exception",
    "Breakpoint Exception",
    "Into Detected Overflow Exception",
    "Out of Bounds Exception",
    "Invalid Opcode Exception",
    "No Coprocessor Exception",
    "Double Fault Exception",
    "Coprocessor Segment Overrun Exception",
    "Bad TSS Exception",
    "Segment Not Present Exception",
    "Stack Fault Exception",
    "General Protection Fault Exception",
    "Page Fault Exception",
    "Unknown Interrupt Exception",
    "Coprocessor Fault Exception",
    "Alignment Check Exception (486+)",
    "Machine Check Exception (Pentium/586+)",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions",
    "Reserved Exceptions"
};


void fault_handler(struct regs* r)
{
    printf("Fault Handler has been called.\n");
    if (r->int_no < 32)
    {
        puts(exception_messages[r->int_no]);
        puts("Exception. System will halt.\n");
        for (;;){}
    }
    for (;;){}
}
