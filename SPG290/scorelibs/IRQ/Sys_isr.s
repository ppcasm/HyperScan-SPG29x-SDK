// General Registers Symbolic
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

// CP0 Registers
#define CP0_STATUS   cr0
#define CP0_COND     cr1
#define CP0_CAUSE    cr2
#define CP0_EXCPVEC  cr3
#define CP0_CCR      cr4
#define CP0_EPC      cr5
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
#define SPR_HI	     sr1    		
#define SPR_LO	     sr2 

#define STACK_SIZE   32

.org 0
.section .exception_vec,"ax"   // 0xa00901fc
//=========================================================
// General/Debug
//=========================================================
.align 2
norm_debug_vec:         // DebugVec
    j norm_debug_service

.align 2
general_vec:            // GeneralVec
    j general_service
    
//=========================================================
// IRQ 1~63
//=========================================================
.align 2
int1_vec:               // IRQ1
    j int_service       // int_service
.align 2
int2_vec:               // IRQ2
    j int_service       // int_service
.align 2
int3_vec:               // IRQ3
    j int_service       // int_service
.align 2
int4_vec:               // IRQ4
    j int_service       // int_service
.align 2
int5_vec:               // IRQ5
    j int_service       // int_service
.align 2
int6_vec:               // IRQ6
    j int_service       // int_service
.align 2
int7_vec:               // IRQ7
    j int_service       // int_service
.align 2
int8_vec:               // IRQ8
    j int_service       // int_service
.align 2
int9_vec:               // IRQ9
    j int_service       // int_service
.align 2
int10_vec:              // IRQ10
    j int_service       // int_service
.align 2
int11_vec:              // IRQ11
    j int_service       // int_service
.align 2
int12_vec:              // IRQ12
    j int_service       // int_service
.align 2
int13_vec:              // IRQ13
    j int_service       // int_service
.align 2
int14_vec:              // IRQ14
    j int_service       // int_service
.align 2
int15_vec:              // IRQ15
    j int_service       // int_service
.align 2
int16_vec:              // IRQ16
    j int_service       // int_service
.align 2
int17_vec:              // IRQ17
    j int_service       // int_service
.align 2
int18_vec:              // IRQ18
    j int_service       // int_service
.align 2
int19_vec:              // IRQ19
    j int_service       // int_service
.align 2
int20_vec:              // IRQ20
    j int_service       // int_service
.align 2
int21_vec:              // IRQ21
    j int_service       // int_service
.align 2
int22_vec:              // IRQ22
    j int_service       // int_service
.align 2
int23_vec:              // IRQ23
    j int_service       // int_service
.align 2
int24_vec:              // IRQ24
    j save_reg          // save_reg
.align 2
int25_vec:              // IRQ25
    j save_reg          // save_reg
.align 2
int26_vec:              // IRQ26
    j save_reg          // save_reg
.align 2
int27_vec:              // IRQ27
    j save_reg          // save_reg
.align 2
int28_vec:              // IRQ28
    j save_reg          // save_reg
.align 2
int29_vec:              // IRQ29
    j save_reg          // save_reg
.align 2
int30_vec:              // IRQ30
    j save_reg          // save_reg
.align 2
int31_vec:              // IRQ31
    j save_reg          // save_reg
.align 2
int32_vec:              // IRQ32
    j save_reg          // save_reg
.align 2
int33_vec:              // IRQ33
    j save_reg          // save_reg
.align 2
int34_vec:              // IRQ34
    j save_reg          // save_reg
.align 2
int35_vec:              // IRQ35
    j save_reg          // save_reg
.align 2
int36_vec:              // IRQ36
    j save_reg          // save_reg
.align 2
int37_vec:              // IRQ37
    j save_reg          // save_reg
.align 2
int38_vec:              // IRQ38
    j save_reg          // save_reg
.align 2
int39_vec:              // IRQ39
    j save_reg          // save_reg
.align 2
int40_vec:              // IRQ40
    j save_reg          // save_reg
.align 2
int41_vec:              // IRQ41
    j save_reg          // save_reg
.align 2
int42_vec:              // IRQ42
    j save_reg          // save_reg
.align 2
int43_vec:              // IRQ43
    j save_reg          // save_reg
.align 2
int44_vec:              // IRQ44
    j save_reg          // save_reg
.align 2
int45_vec:              // IRQ45
    j save_reg          // save_reg
.align 2
int46_vec:              // IRQ46
    j save_reg          // save_reg
.align 2
int47_vec:              // IRQ47
    j save_reg          // save_reg
.align 2
int48_vec:              // IRQ48
    j save_reg          // save_reg
.align 2
int49_vec:              // IRQ49
    j save_reg          // save_reg
.align 2
int50_vec:              // IRQ50
    j save_reg          // save_reg
.align 2
int51_vec:              // IRQ51
    j save_reg          // save_reg
.align 2
int52_vec:              // IRQ52
    j save_reg          // save_reg
.align 2
int53_vec:              // IRQ53
    j save_reg          // save_reg
.align 2
int54_vec:              // IRQ54
    j save_reg          // save_reg
.align 2
int55_vec:              // IRQ55
    j save_reg          // save_reg
.align 2
int56_vec:              // IRQ56
    j save_reg          // save_reg
.align 2
int57_vec:              // IRQ57
    j save_reg          // save_reg
.align 2
int58_vec:              // IRQ58
    j save_reg          // save_reg
.align 2
int59_vec:              // IRQ59
    j save_reg          // save_reg
.align 2
int60_vec:              // IRQ60
    j save_reg          // save_reg
.align 2
int61_vec:              // IRQ61
    j   save_reg        // save_reg
.align 2
int62_vec:              // IRQ62
    j save_reg          // save_reg
.align 2
int63_vec:              // IRQ63
    j save_reg          // save_reg

.extern intmsg          // intmsg from SysIRQ.c
//=========================================================
// IRQ SVC
//=========================================================
norm_debug_service:     // Debug
    jl intmsg           // intmsg();

general_service:        // General
    jl intmsg           // intmsg();

int_service:
    jl intmsg           // intmsg();

.extern irq_dispatch    // irq_dispatch from SysIRQ.c
.set r1
//=========================================================
// void save_reg(void)
// Save all register and jump to interrupt label table
// After completing service routine, load all register
//
//
//=========================================================
save_reg:
    subi SP, 38*4
    sw r1,  [SP, 1*4]
    sw r2,  [SP, 2*4]
    sw r3,  [SP, 3*4]
    sw r4,  [SP, 4*4]
    sw r5,  [SP, 5*4]
    sw r6,  [SP, 6*4]
    sw r7,  [SP, 7*4]
    sw r8,  [SP, 8*4]
    sw r9,  [SP, 9*4]
    sw r10, [SP, 10*4]
    sw r11, [SP, 11*4]
    sw r12, [SP, 12*4]
    sw r13, [SP, 13*4]
    sw r14, [SP, 14*4]
    sw r15, [SP, 15*4]
    sw r16, [SP, 16*4]
    sw r17, [SP, 17*4]
    sw r18, [SP, 18*4]
    sw r19, [SP, 19*4]
    sw r20, [SP, 20*4]
    sw r21, [SP, 21*4]
    sw r22, [SP, 22*4]
    sw r23, [SP, 23*4]
    sw r24, [SP, 24*4]
    sw r25, [SP, 25*4]
    sw r26, [SP, 26*4]
    sw r27, [SP, 27*4]
    sw r28, [SP, 28*4]
    sw r29, [SP, 29*4]
    sw r30, [SP, 30*4]
    sw r31, [SP, 31*4]
    mfcr    r13, cr1
    mfcr    r15, cr5
    sw r13, [SP, 33*4]
    sw r15, [SP, 35*4]

    mfcr    r4, cr2
    jl	irq_dispatch
    
    lw r1,  [SP, 1*4]
    lw r2,  [SP, 2*4]
    lw r3,  [SP, 3*4]
    lw r4,  [SP, 4*4]
    lw r5,  [SP, 5*4]
    lw r6,  [SP, 6*4]
    lw r7,  [SP, 7*4]
    lw r8,  [SP, 8*4]
    lw r9,  [SP, 9*4]
    lw r10, [SP, 10*4]
    lw r11, [SP, 11*4]
    lw r12, [SP, 12*4]
    lw r13, [SP, 13*4]
    lw r14, [SP, 14*4]
    lw r15, [SP, 15*4]
    lw r16, [SP, 16*4]
    lw r17, [SP, 17*4]
    lw r18, [SP, 18*4]
    lw r19, [SP, 19*4]
    lw r20, [SP, 20*4]
    lw r21, [SP, 21*4]
    lw r22, [SP, 22*4]
    lw r23, [SP, 23*4]
    lw r24, [SP, 24*4]
    lw r25, [SP, 25*4]
    lw r26, [SP, 26*4]
    lw r27, [SP, 27*4]
    lw r28, [SP, 28*4]
    lw r29, [SP, 29*4]
    lw r30, [SP, 30*4]
    lw r31, [SP, 31*4]
	lw r30, [SP, 33*4]
    lw r31, [SP, 35*4]
    mtcr    r30, cr1
    mtcr    r31, cr5
    addi	SP, 38*4
    rte

 
	

