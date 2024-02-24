.extern main
.section .hardware_init,"ax",@progbits

.global _hardware_init
.ent _hardware_init
_hardware_init:

		// Set up gp
		la      r28, _gp
		
		// Init/Clear BSS segment
		la      r8, __bss_start
		la      r9, _bss_end__
		ldi     r10, 0
clear_bss_loop:
		sb		r10, [r8]+, 1
		cmp!	r8, r9
		ble!	clear_bss_loop
		nop
		jl main
		nop
		
.end _hardware_init
