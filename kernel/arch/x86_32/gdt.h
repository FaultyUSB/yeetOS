#ifndef GDT_H
#define GDT_H

#include <stdint.h>

#define GDT_ENTRIES 3

struct gdt_entry
{
    uint16_t lower_limit;
    uint16_t lower_base;
    uint8_t  mid_base;
    uint8_t  access;
    uint8_t  granularity;
    uint8_t  upper_base;
} __attribute__((packed));

struct gdt_ptr
{
    uint16_t limit;
    uint32_t  base;
} __attribute__((packed));

extern void gdt_flush();

#endif /* GDT_H */
