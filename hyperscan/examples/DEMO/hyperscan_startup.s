////////////////////////////////////////////////////
// Defination of registers and the save position
#define    SP        r0
#define    AT        r1
#define    BP        r2
#define    LR        r3
#define    A0        r4
#define    A1        r5
#define    A2        r6
#define    A3        r7
#define    T0        r8
#define    T1        r9
#define    T2        r10
#define    T3        r11
#define    S0        r12
#define    S1        r13
#define    S2        r14
#define    S3        r15
#define    S4        r16
#define    S5        r17
#define    S6        r18
#define    S7        r19
#define    S8        r20
#define    S9        r21
#define    T4        r22
#define    T5        r23
#define    T6        r24
#define    T7        r25
#define    T8        r26
#define    T9        r27
#define    R28       r28
#define    JP        r29
#define    K0        r30
#define    K1        r31

// CP0 register define
#define CP0_STATUS   cr0
#define CP0_COND     cr1
#define CP0_CAUSE    cr2
#define CP0_EPC      cr5
#define CP0_EXCPVEC  cr3
#define CP0_CCR      cr4
#define CP0_BADVA    cr6
#define CP0_WIRE     cr7
#define CP0_INDEX    cr8
#define CP0_CONTEXT  cr9
#define CP0_RANDOM   cr10
#define CP0_ENTRYHI  cr11
#define CP0_ENTRYLO  cr12
#define CP0_FMARLO   cr13
#define CP0_FMARHI   cr14
#define CP0_FMCR     cr15
#define CP0_FFMR     cr16
#define CP0_LLADDR   cr17
#define CP0_PREV     cr18
#define CP0_DREG     cr29
#define CP0_DEPC     cr30
#define CP0_DSAVE    cr31
#define SPR_HI       sr1
#define SPR_LO       sr2

//specification define
#define SR_CNT       sr0
#define SR_LCR       sr1
#define SR_SCR       sr2
#define STACK_SIZE   32
#define E_SP         0*4
#define E_AT         1*4
#define E_BP         2*4
#define E_LR         3*4
#define E_A0         4*4
#define E_A1         5*4
#define E_A2         6*4
#define E_A3         7*4
#define E_T0         8*4
#define E_T1         9*4
#define E_T2         10*4
#define E_T3         11*4
#define E_S0         12*4
#define E_S1         13*4
#define E_S2         14*4
#define E_S3         15*4
#define E_S4         16*4
#define E_S5         17*4
#define E_S6         18*4
#define E_S7         19*4
#define E_S8         20*4
#define E_S9         21*4
#define E_T4         22*4
#define E_T5         23*4
#define E_T6         24*4
#define E_T7         25*4
#define E_T8         26*4
#define E_T9         27*4
#define E_R28        28*4
#define E_JP         29*4
#define E_K0         30*4
#define E_K1         31*4
#define E_CP0_STATUS 32*4
#define E_CP0_COND   33*4
#define E_CP0_CAUSE  34*4
#define E_CP0_EPC    35*4
#define E_SPR_HI     36*4
#define E_SPR_LO     37*4
#define E_SR_CNT     38*4
#define E_SR_LCR     39*4
#define E_SR_SCR     40*4
#define E_SIZE       41*4 /* must be even */
//=========================================================
// startup code for standard project
//=========================================================
.extern main
.section .hardware_init,"ax",@progbits
.global _hardware_init
.ent _hardware_init
_hardware_init:

		li A0, 0x0				//	Interrupt disable
		mtcr A0, CP0_STATUS
		pflush
		nop
		nop
		nop
		nop
		nop
		
		li A0, 0xa0000000		//	change exception vector base to 0xa0000000
		mtcr A0, CP0_EXCPVEC

		li A0, 0x0				//	Interrupt disable
		mtcr A0, CP0_STATUS
		pflush
		nop
		nop
		nop
		nop
		nop
		
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
		
		// Disable write back data cache
		mfcr r5, cr4
		nop
		li r7, 0x80
		andri r6, r5, 0x80
		
		// Check under WB mode
		cmp.c r7, r6
		bne under_wt
		nop
under_wb:
		la r7, tgl_wb
		cache 0x1f, [r7, 0]			//	force write out dirty entry and set invalid
		nop
		nop
		nop
tgl_wb:
		cache 0x1d, [r7, 0]			//	toggle write-back function
		nop
under_wt:							//	Processor is under write-through mode

		// Enable BIU Write buffer
		la r4, biu_wben
biu_wben:
		cache 0x1b, [r4, 0]
		
		// Setup SDRAM
		la	r9, 0x88070060
		la r10, 0x95404b04
		sw r10, [r9, 0]
		
		// Setup stack pointer
		la r0,_stack

		// void main();
		jl main
		nop
		
		// Hang if we return from main, but later we will have it
		// go back to the firmware
loop_to_self:
		j loop_to_self
		nop
		 
.end _hardware_init

//=========================================================
// Soft exception isr
//=========================================================
.global norm_debug_service
norm_debug_service:
    j norm_debug_service
.global general_service
general_service:
    j general_service
//=========================================================
// default interrupt dispatch isr
//=========================================================
.set AT
__default_interrupt_vsr:
    subi    SP, E_SIZE
    /* push general registers to stack */
    sw AT, [SP,E_AT]
    sw BP, [SP,E_BP]
    sw LR, [SP,E_LR]
    sw A0, [SP,E_A0]
    sw A1, [SP,E_A1]
    sw A2, [SP,E_A2]
    sw A3, [SP,E_A3]
    sw T0, [SP,E_T0]
    sw T1, [SP,E_T1]
    sw T2, [SP,E_T2]
    sw T3, [SP,E_T3]
    sw S0, [SP,E_S0]
    sw S1, [SP,E_S1]
    sw S2, [SP,E_S2]
    sw S3, [SP,E_S3]
    sw S4, [SP,E_S4]
    sw S5, [SP,E_S5]
    sw S6, [SP,E_S6]
    sw S7, [SP,E_S7]
    sw S8, [SP,E_S8]
    sw S9, [SP,E_S9]
    sw T4, [SP,E_T4]
    sw T5, [SP,E_T5]
    sw T6, [SP,E_T6]
    sw T7, [SP,E_T7]
    sw T8, [SP,E_T8]
    sw T9, [SP,E_T9]
    sw R28,[SP,E_R28]
    sw JP, [SP,E_JP]
    sw K0, [SP,E_K0]
    sw K1, [SP,E_K1]
    /* push CP0 registers to stack */
    mfcr    S1, CP0_COND
    sw S1, [SP,E_CP0_COND]
    mfcr    S3, CP0_EPC
    sw S3, [SP,E_CP0_EPC]
    mfcr    S4, CP0_STATUS
    sw S4, [SP,E_CP0_STATUS]
    /* push special control registers to stack */
    mfceh   S1
    sw S1, [SP,E_SPR_HI]
    mfcel   S1
    sw S1, [SP,E_SPR_LO]
    mfsr    S1, SR_CNT
    sw S1, [SP,E_SR_CNT]
    mfsr    S1, SR_LCR
    sw S1, [SP,E_SR_LCR]
    mfsr    S1, SR_SCR
    sw S1, [SP,E_SR_SCR]
    mfcr    A0, CP0_CAUSE
    jl irq_dispatch
    
no_ctxsw:
    /* pop special registers from stack */
    lw      T0, [SP, E_SPR_HI]
    mtceh   T0
    lw      T0, [SP, E_SPR_LO]
    mtcel   T0
    lw      T0, [SP, E_SR_CNT]
    mtsr    T0, SR_CNT
    lw      T0, [SP, E_SR_LCR]
    mtsr    T0, SR_LCR
    lw      T0, [SP, E_SR_SCR]
    mtsr    T0, SR_SCR
    /* pop general registers from stack */
    lw AT, [SP,E_AT]
    lw BP, [SP,E_BP]
    lw LR, [SP,E_LR]
    lw A0, [SP,E_A0]
    lw A1, [SP,E_A1]
    lw A2, [SP,E_A2]
    lw A3, [SP,E_A3]
    lw T2, [SP,E_T2]
    lw T3, [SP,E_T3]
    lw S0, [SP,E_S0]
    lw S1, [SP,E_S1]
    lw S2, [SP,E_S2]
    lw S3, [SP,E_S3]
    lw S4, [SP,E_S4]
    lw S5, [SP,E_S5]
    lw S6, [SP,E_S6]
    lw S7, [SP,E_S7]
    lw S8, [SP,E_S8]
    lw S9, [SP,E_S9]
    lw T4, [SP,E_T4]
    lw T5, [SP,E_T5]
    lw T6, [SP,E_T6]
    lw T7, [SP,E_T7]
    lw T8, [SP,E_T8]
    lw T9, [SP,E_T9]
    lw R28,[SP,E_R28]
    lw JP, [SP,E_JP]
    lw K0, [SP,E_K0]
    lw K1, [SP,E_K1]
    /* pop CP0 registers from stack */
    lw T0, [SP,E_CP0_COND]
    mtcr T0, CP0_COND
    lw T0, [SP,E_CP0_EPC]
    mtcr  T0, CP0_EPC
    lw T0, [SP,E_CP0_STATUS]
    mtcr T0, CP0_STATUS
    pflush
    lw T0, [SP,E_T0]
    lw T1, [SP,E_T1]
    addi SP, E_SIZE
score_fun_rte1:
    rte
//=========================================================
// default interrupt isr
//=========================================================
.global hal_default_isr
.ent hal_default_isr
hal_default_isr:
	br LR
.end hal_default_isr
//=========================================================
// exception & interrupt vector
//=========================================================
.section .exception_vec,"ax"
.set volatile
norm_debug_vec:         //Normal debug
    j norm_debug_service
general_vec:            //General
    j general_service
int_vec:
	.rept  63
	j __default_interrupt_vsr
	.endr
//=========================================================
// Interrupt Handler table
//=========================================================
.global	hal_interrupt_handlers
hal_interrupt_handlers:
	.long	hal_default_isr
	.rept	63
	.long	hal_default_isr
	.endr
.global	hal_interrupt_data
hal_interrupt_data:
	.rept	64 
	.long	0
	.endr
