# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve a stack for the initial thread.
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# Refresh Segment Registers when GDT gets updated
.section .text
.global gdt_flush
.extern gp
gdt_flush:
    lgdt [gp]
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    jmp $0x08, $flush2
flush2:
    ret

# Load the IDT table into the CPUs register
.section .text
.global idt_load
.extern idtp
idt_load:
    lidt [idtp]
    ret

# Create ISR stubs for each of the 32 exceptions. For each exception, we will branch into a common ISR stub
.section .text
.global isr0 
.global isr1 
.global isr2 
.global isr3 
.global isr4 
.global isr5 
.global isr6 
.global isr7 
.global isr8 
.global isr9 
.global isr10 
.global isr11 
.global isr12 
.global isr13 
.global isr14 
.global isr15 
.global isr16 
.global isr17 
.global isr18 
.global isr19 
.global isr20 
.global isr21 
.global isr22 
.global isr23 
.global isr24 
.global isr25 
.global isr26 
.global isr27 
.global isr28 
.global isr29 
.global isr30 
.global isr31 

# Divide by zero exception
isr0:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x0 # Push exception number
    jmp isr_common_stub

isr1:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x1 # Push exception number
    jmp isr_common_stub
isr2:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x2 # Push exception number
    jmp isr_common_stub
isr3:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x3 # Push exception number
    jmp isr_common_stub
isr4:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x4 # Push exception number
    jmp isr_common_stub
isr5:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x5 # Push exception number
    jmp isr_common_stub
isr6:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x6 # Push exception number
    jmp isr_common_stub
isr7:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x7 # Push exception number
    jmp isr_common_stub
isr8:
    cli 
    push $0x8 # Push exception number
    jmp isr_common_stub
isr9:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x9 # Push exception number
    jmp isr_common_stub
isr10:
    cli 
    push $0xA # Push exception number
    jmp isr_common_stub
isr11:
    cli 
    push $0xB # Push exception number
    jmp isr_common_stub
isr12:
    cli 
    push $0xC # Push exception number
    jmp isr_common_stub
isr13:
    cli 
    push $0xD # Push exception number
    jmp isr_common_stub
isr14:
    cli 
    push $0xE # Push exception number
    jmp isr_common_stub
isr15:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0xF # Push exception number
    jmp isr_common_stub
isr16:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x10 # Push exception number
    jmp isr_common_stub
isr17:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x11 # Push exception number
    jmp isr_common_stub
isr18:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x12 # Push exception number
    jmp isr_common_stub
isr19:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x13 # Push exception number
    jmp isr_common_stub
isr20:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x14 # Push exception number
    jmp isr_common_stub
isr21:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x15 # Push exception number
    jmp isr_common_stub
isr22:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x16 # Push exception number
    jmp isr_common_stub
isr23:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x17 # Push exception number
    jmp isr_common_stub
isr24:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x18 # Push exception number
    jmp isr_common_stub
isr25:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x19 # Push exception number
    jmp isr_common_stub
isr26:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x1A # Push exception number
    jmp isr_common_stub
isr27:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x1B # Push exception number
    jmp isr_common_stub
isr28:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x1C # Push exception number
    jmp isr_common_stub
isr29:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x1D # Push exception number
    jmp isr_common_stub
isr30:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x1E # Push exception number
    jmp isr_common_stub
isr31:
    cli 
    push $0x0 # Push error code (0 if error code won't exist)
    push $0x1F # Push exception number
    jmp isr_common_stub

.extern fault_handler

isr_common_stub:
    cld

    pusha
    push %ds
    push %es
    push %fs
    push %gs

    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    movl %esp, %eax
    pushl %eax
    call fault_handler
    #mov %eax, %esp
    #push %eax
    #mov $fault_handler, %eax
    #call *%eax
    pop %eax
    pop %gs
    pop %fs
    pop %es
    pop %ds
    popa
    add $8, %esp
    iret 

# Adding IRQ support 
.section .text
.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15

irq0:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $32
    jmp irq_common_stub
irq1:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $33
    jmp irq_common_stub
irq2:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $34
    jmp irq_common_stub
irq3:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $35
    jmp irq_common_stub
irq4:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $36
    jmp irq_common_stub
irq5:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $37
    jmp irq_common_stub
irq6:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $38
    jmp irq_common_stub
irq7:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $39
    jmp irq_common_stub
irq8:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $40
    jmp irq_common_stub
irq9:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $41
    jmp irq_common_stub
irq10:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $42
    jmp irq_common_stub
irq11:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $43
    jmp irq_common_stub
irq12:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $44
    jmp irq_common_stub
irq13:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $45
    jmp irq_common_stub
irq14:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $46
    jmp irq_common_stub
irq15:
    cli
    push $0 # Pushing a dummy error code onto the stack
    push $47
    jmp irq_common_stub

.extern irq_handler

irq_common_stub:
    cld

    pusha
    push %ds
    push %es
    push %fs
    push %gs

    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    movl %esp, %eax
    pushl %eax
    call irq_handler
    #mov %eax, %esp
    #push %eax
    #mov $fault_handler, %eax
    #call *%eax
    pop %eax
    pop %gs
    pop %fs
    pop %es
    pop %ds
    popa
    add $8, %esp
    iret 


# The kernel entry point.
.section .text
.global _start
.type _start, @function
_start:
	movl $stack_top, %esp

    # Initialize the GDT
    call gdt_install

    # Initialize the IDT
    call idt_install
    sti

    # Populate IDT with ISRs for exceptions (entries 0 - 31)
    call isrs_install

    # Popu IDT with ISRs for handling IRQs (entires 32 - 47)
    call irq_install
    sti

    #call timer_install
    call keyboard_install

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
    sti
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
#	cli
1:	hlt
	jmp 1b
.size _start, . - _start
