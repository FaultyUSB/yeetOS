#include "gdt.h"
#include <stdint.h>

struct gdt_entry gdt[GDT_ENTRIES];
struct gdt_ptr gp;

void constructGdtEntry(uint32_t idx, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
    /* Encode the limit fields of the segment entry */
    gdt[idx].lower_limit = (limit & 0xFFFF);
    gdt[idx].granularity = (limit >> 16) & 0x0F;

    /* Encode the base fields of the segment entry */
    gdt[idx].lower_base = (base & 0xFFFF);
    gdt[idx].mid_base = (base >> 16) & 0xFF;
    gdt[idx].upper_base = (base >> 24) & 0xFF;

    /* Encode the access byte of the segment entry */
    gdt[idx].access = access; 

    /* Encode the flags field (contained in granularity) */
    gdt[idx].granularity |= (gran & 0xF0);
}

void gdt_install()
{
    gp.limit = (sizeof(struct gdt_entry) * GDT_ENTRIES) - 1;
    gp.base = (uint32_t) &gdt[0];

    /* First entry has to be NULL in GDT */
    constructGdtEntry(0, 0, 0, 0, 0);

    /* Second entry will describe our code segment */
    constructGdtEntry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    /* Third entry will describe the data segment */
    constructGdtEntry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    /* Now the GDT has been populated, we can flush the CPUs segment registers */
    gdt_flush();
}
