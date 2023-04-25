#ifndef IDT_H
#define IDT_H

#include <stdint.h>
#include <string.h>

#define IDT_ENTRIES 256

struct idt_entry
{
    uint16_t lower_offset;
    uint16_t segment;
    uint8_t  reserved;
    uint8_t flags;
    uint16_t upper_offset;
} __attribute__((packed));

struct idt_ptr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

extern void idt_load();

void constructIdtEntry(uint32_t, uint32_t, uint16_t, uint8_t);
void idt_install();

#endif /* IDT_H */

