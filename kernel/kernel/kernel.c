#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	printf("What is even going on?.\n");
    //__asm__("div %0" :: "r"(0));
}
