.syntax unified
.cpu cortex-m3
.thumb

.global vector_table
.global reset_handler
.extern main

.section .isr_vector,"a",%progbits
.align 2

vector_table:
    .word _estack              /* Initial stack pointer */
    .word reset_handler        /* Reset */

.section .text.reset_handler

.thumb_func
reset_handler:
    bl main
