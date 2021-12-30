#include "idt.h"

struct idt_entry idt[IDT_ENTRIES];
struct idt_ptr idtp;

void constructIdtEntry(uint32_t idx, uint32_t offset, uint16_t segment, uint8_t flags)
{
    /* First, we'll set the offset fields */
    idt[idx].lower_offset = (offset & 0xFFFF);
    idt[idx].upper_offset = (offset >> 16) & 0xFFFF;

    /* Second, the segment selector field */
    idt[idx].segment = segment;

    /* Third, set reserved field to only 0s */
    idt[idx].reserved = 0;

    /* Finally, set the flags field. */
    idt[idx].flags = flags;
}

void idt_install()
{
    idtp.limit = (sizeof(struct idt_entry) * IDT_ENTRIES) - 1;
    idtp.base = (uint32_t) &idt[0];

    /* Clear out the IDT and set everything to zero */
    memset(&idt[0], 0, sizeof(struct idt_entry) * IDT_ENTRIES);

    /* Add ISRs here using constructIdtEntry */

    /* Load location of IDT in CPUs register */
    idt_load();
}

