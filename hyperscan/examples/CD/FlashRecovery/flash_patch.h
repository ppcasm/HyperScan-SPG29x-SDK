const unsigned int flash_patch[] = {
// Addr: 0x9F000000 - Insn: b 0x9f000080
0x9000BC80,
// Addr: 0x9F000004 - Insn: nop
0x80008000,
// Addr: 0x9F000008 - Insn: nop
0x80008000,
// Addr: 0x9F00000C - Insn: nop
0x80008000,
// Addr: 0x9F000010 - Insn: b 0x9f0004e8
0x9001BCD8,
// Addr: 0x9F000014 - Insn: b 0x9f0004ee
0x9001BCDA,
// Addr: 0x9F000018 - Insn: b 0x9f0004f8
0x9001BCE0,
// Addr: 0x9F00001C - Insn: b 0x9f000550
0x9001BD34,
// Addr: 0x9F000020 - Insn: b 0x9f000558
0x9001BD38,
// Addr: 0x9F000024 - Insn: b 0x9f000560
0x9001BD3C,
// Addr: 0x9F000028 - Insn: b 0x9f000234
0x9000BE0C,
// Addr: 0x9F00002C - Insn: nop
0x80008000,
// Addr: 0x9F000030 - Insn: nop
0x80008000,
// Addr: 0x9F000034 - Insn: nop
0x80008000,
// Addr: 0x9F000038 - Insn: nop
0x80008000,
// Addr: 0x9F00003C - Insn: nop
0x80008000,
// Addr: 0x9F000040 - Insn: ldiu! r0, 83
// Addr: 0x9F000042 - Insn: bvc! 0x9f0000d0
0x4D475053,
// Addr: 0x9F000044 - Insn: j! 0x9f000230
// Addr: 0x9F000046 - Insn: jl! 0x9f000038
0x30393230,
// Addr: 0x9F000048 - Insn: j! 0x9f000032
// Addr: 0x9F00004A - Insn: j! 0x9f000630
0x36303032,
// Addr: 0x9F00004C - Insn: j! 0x9f000730
// Addr: 0x9F00004E - Insn: j! 0x9f000832
0x38323730,
// Addr: 0x9F000050 - Insn: bitset! r1, 0x9
// Addr: 0x9F000052 - Insn: swp! r4, 56
0x7474614D,
// Addr: 0x9F000054 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000058 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F00005C - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000060 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000064 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000068 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F00006C - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000070 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000074 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000078 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F00007C - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000080 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F000084 - Insn: ori r8, 0x104
0x85148208,
// Addr: 0x9F000088 - Insn: ldis r9, 0x11
0x95388022,
// Addr: 0x9F00008C - Insn: ori r9, 0x8317
0x8536862E,
// Addr: 0x9F000090 - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F000094 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000098 - Insn: ori r8, 0x5c
0x851480B8,
// Addr: 0x9F00009C - Insn: ldi r9, 0x3
0x85388006,
// Addr: 0x9F0000A0 - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F0000A4 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F0000A8 - Insn: ori r8, 0x58
0x851480B0,
// Addr: 0x9F0000AC - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F0000B0 - Insn: ldis r8, 0x8815
0x951A902A,
// Addr: 0x9F0000B4 - Insn: ori r8, 0x8
0x85148010,
// Addr: 0x9F0000B8 - Insn: ldi r9, 0x1076
0x8538A0EC,
// Addr: 0x9F0000BC - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F0000C0 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F0000C4 - Insn: ori r8, 0x44
0x85148088,
// Addr: 0x9F0000C8 - Insn: ldi r9, 0x3
0x85388006,
// Addr: 0x9F0000CC - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F0000D0 - Insn: ldis r8, 0x8806
0x951A900C,
// Addr: 0x9F0000D4 - Insn: ori r8, 0x80
0x85148100,
// Addr: 0x9F0000D8 - Insn: ldi r9, 0x4
0x85388008,
// Addr: 0x9F0000DC - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F0000E0 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F0000E4 - Insn: ori r8, 0x44
0x85148088,
// Addr: 0x9F0000E8 - Insn: ldi r9, 0x2
0x85388004,
// Addr: 0x9F0000EC - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F0000F0 - Insn: ldis r8, 0x9f00
0x951ABE00,
// Addr: 0x9F0000F4 - Insn: ori r8, 0x40
0x85148080,
// Addr: 0x9F0000F8 - Insn: lw! r9, [r8]
// Addr: 0x9F0000FA - Insn: mhfl! r18, r9
0x02922988,
// Addr: 0x9F0000FC - Insn: bl 0x9f0004c8
0x9000BFCD,
// Addr: 0x9F000100 - Insn: srli r9, r9, 8
0x8129A074,
// Addr: 0x9F000104 - Insn: mv r18, r9
0x8249BC56,
// Addr: 0x9F000108 - Insn: bl 0x9f0004c8
0x9000BFC1,
// Addr: 0x9F00010C - Insn: srli r9, r9, 8
0x8129A074,
// Addr: 0x9F000110 - Insn: mv r18, r9
0x8249BC56,
// Addr: 0x9F000114 - Insn: bl 0x9f0004c8
0x9000BFB5,
// Addr: 0x9F000118 - Insn: srli r9, r9, 8
0x8129A074,
// Addr: 0x9F00011C - Insn: mv r18, r9
0x8249BC56,
// Addr: 0x9F000120 - Insn: bl 0x9f0004c8
0x9000BFA9,
// Addr: 0x9F000124 - Insn: ldi r18, 0xd
0x8658801A,
// Addr: 0x9F000128 - Insn: bl 0x9f0004c8
0x9000BFA1,
// Addr: 0x9F00012C - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000130 - Insn: ori r8, 0xfc
0x851481F8,
// Addr: 0x9F000134 - Insn: ldi r9, 0x3
0x85388006,
// Addr: 0x9F000138 - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F00013C - Insn: ldis r8, 0x8820
0x951A9040,
// Addr: 0x9F000140 - Insn: ori r8, 0x58
0x851480B0,
// Addr: 0x9F000144 - Insn: lw r11, [r8, 0]
0xC1688000,
// Addr: 0x9F000148 - Insn: ldis r8, 0x8820
0x951A9040,
// Addr: 0x9F00014C - Insn: ori r8, 0x60
0x851480C0,
// Addr: 0x9F000150 - Insn: lw r22, [r8, 0]
0xC2C88000,
// Addr: 0x9F000154 - Insn: srli r22, r22, 24
0x82D6E074,
// Addr: 0x9F000158 - Insn: bittst! r11, 0xd
// Addr: 0x9F00015A - Insn: beq! 0x9f000172
0x440C6B6E,
// Addr: 0x9F00015C - Insn: andri r23, r22, 0x7
0xB2F6800E,
// Addr: 0x9F000160 - Insn: bittgl.c r23, r23, 0x2
0x82F7882F,
// Addr: 0x9F000164 - Insn: bittst.c r23, 0x1
0x8017842D,
// Addr: 0x9F000168 - Insn: beq 0x9f00017c
0x90009014,
// Addr: 0x9F00016C - Insn: bittgl.c r23, r23, 0x0
0x82F7802F,
// Addr: 0x9F000170 - Insn: b! 0x9f00017c
// Addr: 0x9F000172 - Insn: mhfl! r23, r11
0x07B24F06,
// Addr: 0x9F000174 - Insn: srli r23, r23, 14
0x82F7B874,
// Addr: 0x9F000178 - Insn: andri r23, r23, 0x7
0xB2F7800E,
// Addr: 0x9F00017C - Insn: bitset.c r23, r23, 0x3
0x82F78C2B,
// Addr: 0x9F000180 - Insn: bl 0x9f0001ba
0x9000BC3B,
// Addr: 0x9F000184 - Insn: ldi r18, 0x44
0x86588088,
// Addr: 0x9F000188 - Insn: bl 0x9f0004c8
0x9000BF41,
// Addr: 0x9F00018C - Insn: bl 0x9f0002c6
0x9000BD3B,
// Addr: 0x9F000190 - Insn: ldis r30, 0xa000
0x97DAC000,
// Addr: 0x9F000194 - Insn: ori r30, 0x1000
0x87D4A000,
// Addr: 0x9F000198 - Insn: mfcr r29, cr29
0x9BBD8001,
// Addr: 0x9F00019C - Insn: bittst.c r29, 0x1d
0x801DF42D,
// Addr: 0x9F0001A0 - Insn: bne 0x9f000234
0x90009494,
// Addr: 0x9F0001A4 - Insn: mfcr r29, cr29
0x9BBD8001,
// Addr: 0x9F0001A8 - Insn: bitset.c r29, r29, 0x1c
0x83BDF02B,
// Addr: 0x9F0001AC - Insn: mtcr r29, cr29
0x9BBD8000,
// Addr: 0x9F0001B0 - Insn: b 0x9f0001b0
0x9000BC00,
// Addr: 0x9F0001B4 - Insn: br r30
0x801EBC08,
// Addr: 0x9F0001B8 - Insn: nop!
// Addr: 0x9F0001BA - Insn: mv! r10, r3
0x0A330000,
// Addr: 0x9F0001BC - Insn: ldis r8, 0x8820
0x951A9040,
// Addr: 0x9F0001C0 - Insn: ori r8, 0xd4
0x851481A8,
// Addr: 0x9F0001C4 - Insn: lw! r6, [r8]
// Addr: 0x9F0001C6 - Insn: bitclr! r6, 0x0
0x66042688,
// Addr: 0x9F0001C8 - Insn: sw r6, [r8, 0]
0xD0C88000,
// Addr: 0x9F0001CC - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F0001D0 - Insn: ori r8, 0x60
0x851480C0,
// Addr: 0x9F0001D4 - Insn: lw! r6, [r8]
// Addr: 0x9F0001D6 - Insn: bitset! r6, 0x1f
0x66FD2688,
// Addr: 0x9F0001D8 - Insn: bl 0x9f0001f0
0x9000BC19,
// Addr: 0x9F0001DC - Insn: bl 0x9f000220
0x9000BC45,
// Addr: 0x9F0001E0 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F0001E4 - Insn: ori r8, 0x60
0x851480C0,
// Addr: 0x9F0001E8 - Insn: sw! r6, [r8]
// Addr: 0x9F0001EA - Insn: nop!
0x0000268C,
// Addr: 0x9F0001EC - Insn: nop!
// Addr: 0x9F0001EE - Insn: br! r10
0x0FA40000,
// Addr: 0x9F0001F0 - Insn: bittst.c r23, 0x1
0x8017842D,
// Addr: 0x9F0001F4 - Insn: bne 0x9f000200
0x9000940C,
// Addr: 0x9F0001F8 - Insn: bittst.c r23, 0x0
0x8017802D,
// Addr: 0x9F0001FC - Insn: bne! 0x9f00020e
// Addr: 0x9F0001FE - Insn: b! 0x9f000208
0x4F054509,
// Addr: 0x9F000200 - Insn: bittst.c r23, 0x0
0x8017802D,
// Addr: 0x9F000204 - Insn: bne! 0x9f000214
// Addr: 0x9F000206 - Insn: b! 0x9f00021a
0x4F0A4508,
// Addr: 0x9F000208 - Insn: bitclr! r6, 0x19
// Addr: 0x9F00020A - Insn: bitclr! r6, 0x1a
0x66D466CC,
// Addr: 0x9F00020C - Insn: br! r3
// Addr: 0x9F00020E - Insn: bitset! r6, 0x19
0x66CD0F34,
// Addr: 0x9F000210 - Insn: bitclr! r6, 0x1a
// Addr: 0x9F000212 - Insn: br! r3
0x0F3466D4,
// Addr: 0x9F000214 - Insn: bitclr! r6, 0x19
// Addr: 0x9F000216 - Insn: bitset! r6, 0x1a
0x66D566CC,
// Addr: 0x9F000218 - Insn: br! r3
// Addr: 0x9F00021A - Insn: bitset! r6, 0x19
0x66CD0F34,
// Addr: 0x9F00021C - Insn: bitset! r6, 0x1a
// Addr: 0x9F00021E - Insn: br! r3
0x0F3466D5,
// Addr: 0x9F000220 - Insn: bittst.c r23, 0x2
0x8017882D,
// Addr: 0x9F000224 - Insn: bne! 0x9f00022c
// Addr: 0x9F000226 - Insn: bitset! r6, 0x17
0x66BD4504,
// Addr: 0x9F000228 - Insn: bitclr! r6, 0x18
// Addr: 0x9F00022A - Insn: br! r3
0x0F3466C4,
// Addr: 0x9F00022C - Insn: bitclr! r6, 0x17
// Addr: 0x9F00022E - Insn: bitset! r6, 0x18
0x66C566BC,
// Addr: 0x9F000230 - Insn: br r3
0x8003BC08,
// Addr: 0x9F000234 - Insn: ldis r4, 0x9f00
0x949ABE00,
// Addr: 0x9F000238 - Insn: ori r4, 0x23c
0x84948478,
// Addr: 0x9F00023C - Insn: cache 27, [r4, 0]
0xE3648000,
// Addr: 0x9F000240 - Insn: ldis r4, 0x8807
0x949A900E,
// Addr: 0x9F000244 - Insn: ori r4, 0x60
0x849480C0,
// Addr: 0x9F000248 - Insn: lw r6, [r4, 0]
0xC0C48000,
// Addr: 0x9F00024C - Insn: ldis r5, 0xffff
0x94BBFFFE,
// Addr: 0x9F000250 - Insn: and r6, r6, r5
0x80C69420,
// Addr: 0x9F000254 - Insn: ldi r5, 0x4834
0x84B99068,
// Addr: 0x9F000258 - Insn: or r6, r6, r5
0x80C69422,
// Addr: 0x9F00025C - Insn: sw r6, [r4, 0]
0xD0C48000,
// Addr: 0x9F000260 - Insn: ldi r11, 0x0
0x85788000,
// Addr: 0x9F000264 - Insn: ldis r6, 0x9e00
0x94DABC00,
// Addr: 0x9F000268 - Insn: ori r6, 0x1000
0x84D4A000,
// Addr: 0x9F00026C - Insn: ldis r7, 0x8000
0x94FA8000,
// Addr: 0x9F000270 - Insn: ori r7, 0x1fc
0x84F483F8,
// Addr: 0x9F000274 - Insn: ldis r10, 0xf
0x9558801E,
// Addr: 0x9F000278 - Insn: ori r10, 0xf000
0x8557E000,
// Addr: 0x9F00027C - Insn: add r10, r10, r7
0x814A9C10,
// Addr: 0x9F000280 - Insn: lw! r9, [r6]
// Addr: 0x9F000282 - Insn: sw! r9, [r7]
0x297C2968,
// Addr: 0x9F000284 - Insn: addi r6, 4
0x84C08008,
// Addr: 0x9F000288 - Insn: addi r7, 4
0x84E08008,
// Addr: 0x9F00028C - Insn: cmp! r7, r10
// Addr: 0x9F00028E - Insn: bleu! 0x9f000280
0x43F927A3,
// Addr: 0x9F000290 - Insn: nop!
// Addr: 0x9F000292 - Insn: nop!
0x00000000,
// Addr: 0x9F000294 - Insn: ldis r0, 0x803f
0x941A807E,
// Addr: 0x9F000298 - Insn: ori r0, 0xfffc
0x8417FFF8,
// Addr: 0x9F00029C - Insn: ldis r4, 0x8807
0x949A900E,
// Addr: 0x9F0002A0 - Insn: ori r4, 0x60
0x849480C0,
// Addr: 0x9F0002A4 - Insn: lw r6, [r4, 0]
0xC0C48000,
// Addr: 0x9F0002A8 - Insn: ldis r5, 0xffff
0x94BBFFFE,
// Addr: 0x9F0002AC - Insn: and r6, r6, r5
0x80C69420,
// Addr: 0x9F0002B0 - Insn: ldi r5, 0x4b04
0x84B99608,
// Addr: 0x9F0002B4 - Insn: or r6, r6, r5
0x80C69422,
// Addr: 0x9F0002B8 - Insn: sw r6, [r4, 0]
0xD0C48000,
// Addr: 0x9F0002BC - Insn: ldis r8, 0x9e00
0x951ABC00,
// Addr: 0x9F0002C0 - Insn: ori r8, 0x740
0x85148E80,
// Addr: 0x9F0002C4 - Insn: br! r8
// Addr: 0x9F0002C6 - Insn: mv! r10, r3
0x0A330F84,
// Addr: 0x9F0002C8 - Insn: ldi r4, 0xc07
0x8498980E,
// Addr: 0x9F0002CC - Insn: ldis r5, 0x1
0x94B88002,
// Addr: 0x9F0002D0 - Insn: ori r5, 0x4834
0x84B59068,
// Addr: 0x9F0002D4 - Insn: ldi r6, 0x1ff
0x84D883FE,
// Addr: 0x9F0002D8 - Insn: ldi r7, 0x1ff
0x84F883FE,
// Addr: 0x9F0002DC - Insn: bl 0x9f000560
0x9000BE85,
// Addr: 0x9F0002E0 - Insn: ldi r4, 0x1
0x84988002,
// Addr: 0x9F0002E4 - Insn: ldis r8, 0x8020
0x951A8040,
// Addr: 0x9F0002E8 - Insn: bl 0x9f00033c
0x9000BC55,
// Addr: 0x9F0002EC - Insn: ldis r6, 0x8807
0x94DA900E,
// Addr: 0x9F0002F0 - Insn: ori r6, 0x60
0x84D480C0,
// Addr: 0x9F0002F4 - Insn: lw r7, [r6, 0]
0xC0E68000,
// Addr: 0x9F0002F8 - Insn: ldis r6, 0x7800
0x94D9F000,
// Addr: 0x9F0002FC - Insn: and r7, r7, r6
0x80E79820,
// Addr: 0x9F000300 - Insn: srli r7, r7, 7
0x80E79C74,
// Addr: 0x9F000304 - Insn: ldis r6, 0x8807
0x94DA900E,
// Addr: 0x9F000308 - Insn: ori r6, 0x40
0x84D48080,
// Addr: 0x9F00030C - Insn: lw r5, [r6, 0]
0xC0A68000,
// Addr: 0x9F000310 - Insn: or r7, r7, r5
0x80E79422,
// Addr: 0x9F000314 - Insn: sw r7, [r6, 0]
0xD0E68000,
// Addr: 0x9F000318 - Insn: srli r18, r7, 20
0x8247D074,
// Addr: 0x9F00031C - Insn: addi r18, 48
0x86408060,
// Addr: 0x9F000320 - Insn: bl 0x9f0004c8
0x9000BDA9,
// Addr: 0x9F000324 - Insn: ldi r18, 0xd
0x8658801A,
// Addr: 0x9F000328 - Insn: bl 0x9f0004c8
0x9000BDA1,
// Addr: 0x9F00032C - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000330 - Insn: ori r8, 0xbc
0x85148178,
// Addr: 0x9F000334 - Insn: ldiu! r9, 2
// Addr: 0x9F000336 - Insn: sw! r9, [r8]
0x298C5902,
// Addr: 0x9F000338 - Insn: br r10
0x800ABC08,
// Addr: 0x9F00033C - Insn: ldi r20, 0x5
0x8698800A,
// Addr: 0x9F000340 - Insn: ldis r5, 0x8807
0x94BA900E,
// Addr: 0x9F000344 - Insn: ori r5, 0x60
0x84B480C0,
// Addr: 0x9F000348 - Insn: lw r6, [r5, 0]
0xC0C58000,
// Addr: 0x9F00034C - Insn: ldi r24, 0x0
0x87188000,
// Addr: 0x9F000350 - Insn: ldi r16, 0x0
0x86188000,
// Addr: 0x9F000354 - Insn: ldi r5, 0x0
0x84B88000,
// Addr: 0x9F000358 - Insn: ldis r25, 0x89a0
0x973A9340,
// Addr: 0x9F00035C - Insn: ldi r7, 0x3ff
0x84F887FE,
// Addr: 0x9F000360 - Insn: ldis r27, 0xffff
0x977BFFFE,
// Addr: 0x9F000364 - Insn: ori r27, 0xc000
0x87778000,
// Addr: 0x9F000368 - Insn: and r8, r27, r8
0x811BA020,
// Addr: 0x9F00036C - Insn: ldi r27, 0x4000
0x87798000,
// Addr: 0x9F000370 - Insn: add r8, r8, r27
0x8108EC10,
// Addr: 0x9F000374 - Insn: ldis r27, 0xc0
0x97788180,
// Addr: 0x9F000378 - Insn: and r25, r25, r27
0x8339EC20,
// Addr: 0x9F00037C - Insn: ldis r27, 0x40
0x97788080,
// Addr: 0x9F000380 - Insn: add r25, r25, r27
0x8339EC10,
// Addr: 0x9F000384 - Insn: mv r26, r25
0x8359BC56,
// Addr: 0x9F000388 - Insn: mv r9, r8
0x8128BC56,
// Addr: 0x9F00038C - Insn: ldi r12, 0x0
0x85988000,
// Addr: 0x9F000390 - Insn: addi r8, 516
0x85008408,
// Addr: 0x9F000394 - Insn: sw r12, [r8, 0]
0xD1888000,
// Addr: 0x9F000398 - Insn: addi r7, -1
0x84E3FFFE,
// Addr: 0x9F00039C - Insn: cmp! r7, r5
// Addr: 0x9F00039E - Insn: bne! 0x9f000390
0x45F92753,
// Addr: 0x9F0003A0 - Insn: ldi r7, 0x3ff
0x84F887FE,
// Addr: 0x9F0003A4 - Insn: mlfh! r12, r26
// Addr: 0x9F0003A6 - Insn: mv! r8, r9
0x08930CA1,
// Addr: 0x9F0003A8 - Insn: addis r12, 63
0x9580807E,
// Addr: 0x9F0003AC - Insn: addi r12, 293
0x8580824A,
// Addr: 0x9F0003B0 - Insn: addi r8, 516
0x85008408,
// Addr: 0x9F0003B4 - Insn: sw r12, [r8, 0]
0xD1888000,
// Addr: 0x9F0003B8 - Insn: addi r7, -1
0x84E3FFFE,
// Addr: 0x9F0003BC - Insn: cmp! r7, r5
// Addr: 0x9F0003BE - Insn: bne! 0x9f0003a8
0x45F52753,
// Addr: 0x9F0003C0 - Insn: ldi r7, 0x3ff
0x84F887FE,
// Addr: 0x9F0003C4 - Insn: addis r26, 63
0x9740807E,
// Addr: 0x9F0003C8 - Insn: addi r26, 293
0x8740824A,
// Addr: 0x9F0003CC - Insn: addi r9, 516
0x85208408,
// Addr: 0x9F0003D0 - Insn: lw r13, [r9, 0]
0xC1A98000,
// Addr: 0x9F0003D4 - Insn: cmp.c r26, r13
0x807AB419,
// Addr: 0x9F0003D8 - Insn: bne 0x9f000414
0x9000943C,
// Addr: 0x9F0003DC - Insn: addi r7, -1
0x84E3FFFE,
// Addr: 0x9F0003E0 - Insn: cmp! r7, r5
// Addr: 0x9F0003E2 - Insn: bne! 0x9f0003c4
0x45F12753,
// Addr: 0x9F0003E4 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F0003E8 - Insn: ldi r18, 0x4c
0x86588098,
// Addr: 0x9F0003EC - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F0003F0 - Insn: mv r18, r4
0x8244BC56,
// Addr: 0x9F0003F4 - Insn: addi r18, 48
0x86408060,
// Addr: 0x9F0003F8 - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F0003FC - Insn: cmp.c r20, r4
0x80749019,
// Addr: 0x9F000400 - Insn: beq 0x9f000488
0x90009088,
// Addr: 0x9F000404 - Insn: bittst.c r24, 0x0
0x8018802D,
// Addr: 0x9F000408 - Insn: bne 0x9f000488
0x90009480,
// Addr: 0x9F00040C - Insn: addi r24, 1
0x87008002,
// Addr: 0x9F000410 - Insn: mhfl! r16, r4
// Addr: 0x9F000412 - Insn: b! 0x9f000434
0x4F110042,
// Addr: 0x9F000414 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F000418 - Insn: ldi r18, 0x4d
0x8658809A,
// Addr: 0x9F00041C - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F000420 - Insn: mv r18, r4
0x8244BC56,
// Addr: 0x9F000424 - Insn: addi r18, 48
0x86408060,
// Addr: 0x9F000428 - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F00042C - Insn: cmp.c r20, r4
0x80749019,
// Addr: 0x9F000430 - Insn: beq 0x9f000458
0x90009028,
// Addr: 0x9F000434 - Insn: addi r4, 1
0x84808002,
// Addr: 0x9F000438 - Insn: slli r27, r4, 27
0x8364EC70,
// Addr: 0x9F00043C - Insn: bitclr! r6, 0x1e
// Addr: 0x9F00043E - Insn: bitclr! r6, 0x1d
0x66EC66F4,
// Addr: 0x9F000440 - Insn: bitclr! r6, 0x1c
// Addr: 0x9F000442 - Insn: bitclr! r6, 0x1b
0x66DC66E4,
// Addr: 0x9F000444 - Insn: or r6, r27, r6
0x80DB9822,
// Addr: 0x9F000448 - Insn: ldis r27, 0x8807
0x977A900E,
// Addr: 0x9F00044C - Insn: ori r27, 0x60
0x877480C0,
// Addr: 0x9F000450 - Insn: sw r6, [r27, 0]
0xD0DB8000,
// Addr: 0x9F000454 - Insn: b 0x9f00035c
0x93FFBF08,
// Addr: 0x9F000458 - Insn: bittst.c r24, 0x0
0x8018802D,
// Addr: 0x9F00045C - Insn: beq 0x9f000498
0x9000903C,
// Addr: 0x9F000460 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F000464 - Insn: ldi r18, 0x52
0x865880A4,
// Addr: 0x9F000468 - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F00046C - Insn: slli r27, r16, 27
0x8370EC70,
// Addr: 0x9F000470 - Insn: bitclr! r6, 0x1e
// Addr: 0x9F000472 - Insn: bitclr! r6, 0x1d
0x66EC66F4,
// Addr: 0x9F000474 - Insn: bitclr! r6, 0x1c
// Addr: 0x9F000476 - Insn: bitclr! r6, 0x1b
0x66DC66E4,
// Addr: 0x9F000478 - Insn: or r6, r27, r6
0x80DB9822,
// Addr: 0x9F00047C - Insn: ldis r27, 0x8807
0x977A900E,
// Addr: 0x9F000480 - Insn: ori r27, 0x60
0x877480C0,
// Addr: 0x9F000484 - Insn: sw r6, [r27, 0]
0xD0DB8000,
// Addr: 0x9F000488 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F00048C - Insn: ldi r18, 0x4b
0x86588096,
// Addr: 0x9F000490 - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F000494 - Insn: br r3
0x8003BC08,
// Addr: 0x9F000498 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F00049C - Insn: ldi r18, 0x46
0x8658808C,
// Addr: 0x9F0004A0 - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F0004A4 - Insn: ldis r27, 0x8807
0x977A900E,
// Addr: 0x9F0004A8 - Insn: ori r27, 0x60
0x877480C0,
// Addr: 0x9F0004AC - Insn: lw r18, [r27, 0]
0xC25B8000,
// Addr: 0x9F0004B0 - Insn: bitclr.c r18, r18, 0x1e
0x8252F829,
// Addr: 0x9F0004B4 - Insn: bitclr.c r18, r18, 0x1d
0x8252F429,
// Addr: 0x9F0004B8 - Insn: bitset.c r18, r18, 0x1c
0x8252F02B,
// Addr: 0x9F0004BC - Insn: bitset.c r18, r18, 0x1b
0x8252EC2B,
// Addr: 0x9F0004C0 - Insn: sw r18, [r27, 0]
0xD25B8000,
// Addr: 0x9F0004C4 - Insn: br r3
0x8003BC08,
// Addr: 0x9F0004C8 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F0004CC - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F0004D0 - Insn: nop
0x80008000,
// Addr: 0x9F0004D4 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F0004D8 - Insn: ori r19, 0x10
0x86748020,
// Addr: 0x9F0004DC - Insn: lw r18, [r19, 0]
0xC2538000,
// Addr: 0x9F0004E0 - Insn: bittst.c r18, 0x5
0x8012942D,
// Addr: 0x9F0004E4 - Insn: bne! 0x9f0004d0
// Addr: 0x9F0004E6 - Insn: br! r3
0x0F3445F6,
// Addr: 0x9F0004E8 - Insn: mv! r12, r3
// Addr: 0x9F0004EA - Insn: ldiu! r9, 5
0x59050C33,
// Addr: 0x9F0004EC - Insn: b! 0x9f000504
// Addr: 0x9F0004EE - Insn: mv! r12, r3
0x0C334F0C,
// Addr: 0x9F0004F0 - Insn: bl 0x9f0006f8
0x9000BE09,
// Addr: 0x9F0004F4 - Insn: ldiu! r9, 3
// Addr: 0x9F0004F6 - Insn: b! 0x9f000504
0x4F075903,
// Addr: 0x9F0004F8 - Insn: mv r12, r3
0x8183BC56,
// Addr: 0x9F0004FC - Insn: bl 0x9f0006f8
0x9000BDFD,
// Addr: 0x9F000500 - Insn: ldiu! r9, 15
// Addr: 0x9F000502 - Insn: b! 0x9f000504
0x4F01590F,
// Addr: 0x9F000504 - Insn: ldis r8, 0xffff
0x951BFFFE,
// Addr: 0x9F000508 - Insn: ori r8, 0xffff
0x8517FFFE,
// Addr: 0x9F00050C - Insn: ldis r13, 0x880a
0x95BA9014,
// Addr: 0x9F000510 - Insn: ori r13, 0x20
0x85B48040,
// Addr: 0x9F000514 - Insn: lw! r15, [r13]
// Addr: 0x9F000516 - Insn: sw! r8, [r13]
0x28DC2FD8,
// Addr: 0x9F000518 - Insn: ldis r13, 0x880a
0x95BA9014,
// Addr: 0x9F00051C - Insn: ori r13, 0x24
0x85B48048,
// Addr: 0x9F000520 - Insn: lw! r14, [r13]
// Addr: 0x9F000522 - Insn: sw! r8, [r13]
0x28DC2ED8,
// Addr: 0x9F000524 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000528 - Insn: sw! r9, [r8]
// Addr: 0x9F00052A - Insn: nop!
0x0000298C,
// Addr: 0x9F00052C - Insn: nop!
// Addr: 0x9F00052E - Insn: ldiu! r9, 7
0x59070000,
// Addr: 0x9F000530 - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F000534 - Insn: bl 0x9f000720
0x9000BDED,
// Addr: 0x9F000538 - Insn: ldis r13, 0x880a
0x95BA9014,
// Addr: 0x9F00053C - Insn: ori r13, 0x20
0x85B48040,
// Addr: 0x9F000540 - Insn: sw r15, [r13, 0]
0xD1ED8000,
// Addr: 0x9F000544 - Insn: ldis r13, 0x880a
0x95BA9014,
// Addr: 0x9F000548 - Insn: ori r13, 0x24
0x85B48048,
// Addr: 0x9F00054C - Insn: sw! r14, [r13]
// Addr: 0x9F00054E - Insn: br! r12
0x0FC42EDC,
// Addr: 0x9F000550 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000554 - Insn: ldiu! r9, 23
// Addr: 0x9F000556 - Insn: sw! r9, [r8]
0x298C5917,
// Addr: 0x9F000558 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F00055C - Insn: ldiu! r9, 39
// Addr: 0x9F00055E - Insn: sw! r9, [r8]
0x298C5927,
// Addr: 0x9F000560 - Insn: mv! r12, r3
// Addr: 0x9F000562 - Insn: bittst! r4, 0xb
0x645E0C33,
// Addr: 0x9F000564 - Insn: bnel 0x9f0005c8
0x90009465,
// Addr: 0x9F000568 - Insn: bl 0x9f0006f8
0x9000BD91,
// Addr: 0x9F00056C - Insn: bl 0x9f0006a4
0x9000BD39,
// Addr: 0x9F000570 - Insn: bittst! r4, 0xc
// Addr: 0x9F000572 - Insn: bne! 0x9f0005a6
0x451A6466,
// Addr: 0x9F000574 - Insn: bittst! r4, 0x7
// Addr: 0x9F000576 - Insn: beq! 0x9f0005a0
0x4415643E,
// Addr: 0x9F000578 - Insn: bl 0x9f000624
0x9000BCAD,
// Addr: 0x9F00057C - Insn: bl 0x9f0005f6
0x9000BC7B,
// Addr: 0x9F000580 - Insn: bl 0x9f000720
0x9000BDA1,
// Addr: 0x9F000584 - Insn: bl 0x9f000714
0x9000BD91,
// Addr: 0x9F000588 - Insn: ldis r19, 0x8815
0x967A902A,
// Addr: 0x9F00058C - Insn: ldi r18, 0x41
0x86588082,
// Addr: 0x9F000590 - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F000594 - Insn: ldi r18, 0xd
0x8658801A,
// Addr: 0x9F000598 - Insn: sw r18, [r19, 0]
0xD2538000,
// Addr: 0x9F00059C - Insn: br r12
0x800CBC08,
// Addr: 0x9F0005A0 - Insn: bl 0x9f0005fe
0x9000BC5F,
// Addr: 0x9F0005A4 - Insn: b! 0x9f0005ac
// Addr: 0x9F0005A6 - Insn: bittst! r4, 0xd
0x646E4F04,
// Addr: 0x9F0005A8 - Insn: bnel 0x9f0005d8
0x90009431,
// Addr: 0x9F0005AC - Insn: bittst.c r4, 0xa
0x8004A82D,
// Addr: 0x9F0005B0 - Insn: bnel 0x9f00064c
0x9000949D,
// Addr: 0x9F0005B4 - Insn: bl 0x9f000624
0x9000BC71,
// Addr: 0x9F0005B8 - Insn: bl 0x9f000602
0x9000BC4B,
// Addr: 0x9F0005BC - Insn: bl 0x9f000720
0x9000BD65,
// Addr: 0x9F0005C0 - Insn: bl 0x9f000714
0x9000BD55,
// Addr: 0x9F0005C4 - Insn: br r12
0x800CBC08,
// Addr: 0x9F0005C8 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F0005CC - Insn: ori r8, 0xbc
0x85148178,
// Addr: 0x9F0005D0 - Insn: ldiu! r9, 3
// Addr: 0x9F0005D2 - Insn: sw! r9, [r8]
0x298C5903,
// Addr: 0x9F0005D4 - Insn: b 0x9f0005e4
0x9000BC10,
// Addr: 0x9F0005D8 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F0005DC - Insn: ori r8, 0xb4
0x85148168,
// Addr: 0x9F0005E0 - Insn: ldiu! r9, 1
// Addr: 0x9F0005E2 - Insn: sw! r9, [r8]
0x298C5901,
// Addr: 0x9F0005E4 - Insn: ldis r9, 0x0
0x95388000,
// Addr: 0x9F0005E8 - Insn: ori r9, 0x0
0x85348000,
// Addr: 0x9F0005EC - Insn: addi r9, 1
0x85208002,
// Addr: 0x9F0005F0 - Insn: cmp! r9, r6
// Addr: 0x9F0005F2 - Insn: bne! 0x9f0005ec
0x45FD2963,
// Addr: 0x9F0005F4 - Insn: br! r3
// Addr: 0x9F0005F6 - Insn: mv! r9, r4
0x09430F34,
// Addr: 0x9F0005F8 - Insn: srli r9, r9, 4
0x81299074,
// Addr: 0x9F0005FC - Insn: b! 0x9f00060c
// Addr: 0x9F0005FE - Insn: ldiu! r9, 6
0x59064F08,
// Addr: 0x9F000600 - Insn: b! 0x9f00060c
// Addr: 0x9F000602 - Insn: mv! r9, r4
0x09434F06,
// Addr: 0x9F000604 - Insn: andi r9, 0x70
0x853080E0,
// Addr: 0x9F000608 - Insn: srli r9, r9, 4
0x81299074,
// Addr: 0x9F00060C - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000610 - Insn: ori r8, 0x4
0x85148008,
// Addr: 0x9F000614 - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F000618 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F00061C - Insn: ldiu! r9, 6
// Addr: 0x9F00061E - Insn: sw! r9, [r8]
0x298C5906,
// Addr: 0x9F000620 - Insn: br r3
0x8003BC08,
// Addr: 0x9F000624 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000628 - Insn: ori r8, 0xc
0x85148018,
// Addr: 0x9F00062C - Insn: mv r9, r4
0x8124BC56,
// Addr: 0x9F000630 - Insn: andi r9, 0x300
0x85308600,
// Addr: 0x9F000634 - Insn: srli r9, r9, 8
0x8129A074,
// Addr: 0x9F000638 - Insn: sw r9, [r8, 0]
0xD1288000,
// Addr: 0x9F00063C - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000640 - Insn: ori r8, 0x8
0x85148010,
// Addr: 0x9F000644 - Insn: ldiu! r9, 0
// Addr: 0x9F000646 - Insn: sw! r9, [r8]
0x298C5900,
// Addr: 0x9F000648 - Insn: br r3
0x8003BC08,
// Addr: 0x9F00064C - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F000650 - Insn: ori r8, 0xb4
0x85148168,
// Addr: 0x9F000654 - Insn: ldiu! r9, 0
// Addr: 0x9F000656 - Insn: sw! r9, [r8]
0x298C5900,
// Addr: 0x9F000658 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F00065C - Insn: ori r8, 0xb8
0x85148170,
// Addr: 0x9F000660 - Insn: mv r9, r4
0x8124BC56,
// Addr: 0x9F000664 - Insn: andi r9, 0xf
0x8530801E,
// Addr: 0x9F000668 - Insn: sw! r9, [r8]
// Addr: 0x9F00066A - Insn: ldiu! r0, 0
0x5000298C,
// Addr: 0x9F00066C - Insn: ori r9, 0x0
0x85348000,
// Addr: 0x9F000670 - Insn: addi r9, 1
0x85208002,
// Addr: 0x9F000674 - Insn: cmp! r9, r7
// Addr: 0x9F000676 - Insn: bne! 0x9f000670
0x45FD2973,
// Addr: 0x9F000678 - Insn: ldis r8, 0x8821
0x951A9042,
// Addr: 0x9F00067C - Insn: ori r8, 0xb4
0x85148168,
// Addr: 0x9F000680 - Insn: ldiu! r9, 1
// Addr: 0x9F000682 - Insn: sw! r9, [r8]
0x298C5901,
// Addr: 0x9F000684 - Insn: ldis r9, 0x0
0x95388000,
// Addr: 0x9F000688 - Insn: ori r9, 0x0
0x85348000,
// Addr: 0x9F00068C - Insn: addi r9, 1
0x85208002,
// Addr: 0x9F000690 - Insn: cmp! r9, r7
// Addr: 0x9F000692 - Insn: bne! 0x9f00068c
0x45FD2973,
// Addr: 0x9F000694 - Insn: br! r3
// Addr: 0x9F000696 - Insn: ldiu! r9, 3
0x59030F34,
// Addr: 0x9F000698 - Insn: andi r13, 0xf0
0x85B081E0,
// Addr: 0x9F00069C - Insn: slli r13, r13, 7
0x81AD9C70,
// Addr: 0x9F0006A0 - Insn: b 0x9f0006c4
0x9000BC24,
// Addr: 0x9F0006A4 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F0006A8 - Insn: ori r8, 0x40
0x85148080,
// Addr: 0x9F0006AC - Insn: lw r9, [r8, 0]
0xC1288000,
// Addr: 0x9F0006B0 - Insn: srli r13, r9, 16
0x81A9C074,
// Addr: 0x9F0006B4 - Insn: bittst! r5, 0x10
// Addr: 0x9F0006B6 - Insn: bne! 0x9f000696
0x45F06586,
// Addr: 0x9F0006B8 - Insn: ldi r9, 0x0
0x85388000,
// Addr: 0x9F0006BC - Insn: andi r13, 0xf
0x85B0801E,
// Addr: 0x9F0006C0 - Insn: slli r13, r13, 11
0x81ADAC70,
// Addr: 0x9F0006C4 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F0006C8 - Insn: ori r8, 0x94
0x85148128,
// Addr: 0x9F0006CC - Insn: sw! r9, [r8]
// Addr: 0x9F0006CE - Insn: mv! r14, r5
0x0E53298C,
// Addr: 0x9F0006D0 - Insn: andi r14, 0xffff
0x85D3FFFE,
// Addr: 0x9F0006D4 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F0006D8 - Insn: ori r8, 0x60
0x851480C0,
// Addr: 0x9F0006DC - Insn: lw r9, [r8, 0]
0xC1288000,
// Addr: 0x9F0006E0 - Insn: srli r9, r9, 16
0x8129C074,
// Addr: 0x9F0006E4 - Insn: andi r9, 0x87ff
0x85328FFE,
// Addr: 0x9F0006E8 - Insn: or r9, r9, r13
0x8129B422,
// Addr: 0x9F0006EC - Insn: slli r9, r9, 16
0x8129C070,
// Addr: 0x9F0006F0 - Insn: or r9, r9, r14
0x8129B822,
// Addr: 0x9F0006F4 - Insn: sw! r9, [r8]
// Addr: 0x9F0006F6 - Insn: br! r3
0x0F34298C,
// Addr: 0x9F0006F8 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F0006FC - Insn: ori r8, 0x5c
0x851480B8,
// Addr: 0x9F000700 - Insn: ldiu! r9, 1
// Addr: 0x9F000702 - Insn: sw! r9, [r8]
0x298C5901,
// Addr: 0x9F000704 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F000708 - Insn: ori r8, 0x6c
0x851480D8,
// Addr: 0x9F00070C - Insn: lw! r9, [r8]
// Addr: 0x9F00070E - Insn: bittst! r9, 0x0
0x69062988,
// Addr: 0x9F000710 - Insn: beq! 0x9f00070c
// Addr: 0x9F000712 - Insn: br! r3
0x0f3444FE,
// Addr: 0x9F000714 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F000718 - Insn: ori r8, 0x5c
0x851480B8,
// Addr: 0x9F00071C - Insn: ldiu! r9, 4
// Addr: 0x9F00071E - Insn: sw! r9, [r8]
0x298C5904,
// Addr: 0x9F000720 - Insn: ldis r8, 0x8807
0x951A900E,
// Addr: 0x9F000724 - Insn: ori r8, 0x5c
0x851480B8,
// Addr: 0x9F000728 - Insn: ldiu! r9, 0
// Addr: 0x9F00072A - Insn: sw! r9, [r8]
0x298C5900,
// Addr: 0x9F00072C - Insn: br! r3
// Addr: 0x9F00072E - Insn: nop!
0x00000F34,
// Addr: 0x9F000730 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000734 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F000738 - Insn: nop!/nop!
0x00000000,
// Addr: 0x9F00073C - Insn: nop!/nop!
0x00000000,

/* -- PLACE PATCHES HERE (0x9F000740 ~ 0x9F000FFF is available) -- */
0x8A00893C,
0x80008000,
0x0203220E,
0x94FA9040,
0x94DA9040,
0xC0C68000,
0x94D48200,
0x0023267C,
0x0F34220A,
0x8C40FFE4,
0x8403FFF8,
0x8040BC56,
0x94DA902A,
0x84D48020,
0x262C2668,
0x8A00878C,
0x94DA902A,
0x84D48020,
0x262C2668,
0xC0C28000,
0x84D08010,
0x84C88001,
0x93FF97E8,
0xC0C28000,
0x84D08040,
0x84C88001,
0x262845EC,
0x84D08100,
0x84C88001,
0x93FF93CC,
0x84408008,
0x220A0023,
0x00000F34,
0x220E230E,
0x8403FFF8,
0x741C0203,
0x94FA902A,
0x267C7618,
0x8A008765,
0x84408008,
0x220A0023,
0x0F34230A,
0x220E230E,
0x8403FFF8,
0x741C0203,
0x8A008810,
0x266B7618,
0x80C68058,
0x76180763,
0x84C08002,
0x0473761C,
0x8A0087C5,
0x266B7618,
0x80C68058,
0x84C88001,
0x93FF97DC,
0x84408008,
0x220A0023,
0x0F34230A,
0x0203220E,
0x94DA902A,
0x84D48020,
0xC0C68000,
0x84D08020,
0x84C88001,
0x93FF97EC,
0x94DA902A,
0xC0C68000,
0x80C6805C,
0x00230463,
0x0F34220A,
0x220E230E,
0x8403FFE8,
0x8040BC56,
0x979AC008,
0x8795A280,
0x84988002,
0x98808000,
0x00000000,
0x00000000,
0x80008000,
0x949AC000,
0x98838000,
0x94FA9042,
0x84F48178,
0x94DA9042,
0x84D48178,
0xC0C68000,
0x84D48008,
0xD0C78000,
0x94FA9014,
0x84F48040,
0x94DA9014,
0x84D48040,
0xC0C68000,
0x951BFFF6,
0x8517FFFE,
0x80C6A020,
0xD0C78000,
0x94DAC000,
0x84D4A8C0,
0x06430F6C,
0x84C88001,
0x90009438,
0x94FA9040,
0x84F48048,
0x94D8BFFC,
0x84D4BFC0,
0xD0C78000,
0x949ABE00,
0x84949820,
0x8A0087E9,
0x94DAC01E,
0x84D5BA00,
0x76107614,
0x8006BC09,
0x8A008930,
0x949ABE00,
0x84949840,
0x8A0087E9,
0x94DAC000,
0x84D4A000,
0x7608760C,
0x8006BC09,
0x84408018,
0x220A0023,
0x0F34230A,
0x230E2C0E,
0x8C40FFE4,
0x8403FFC0,
0x8040BC56,
0x94FA9040,
0x84F48098,
0x94D8FE7E,
0x84D4E604,
0xD0C78000,
0x94DA9040,
0x84D480E0,
0xC0C68000,
0x84D08400,
0x84C88001,
0x90009048,
0x94DAC006,
0x84D687C8,
0x7638763C,
0xC0C68000,
0x94F9889E,
0x84F59AAA,
0x80669C19,
0x90009408,
0x8A00885D,
0x949ABE00,
0x84949840,
0x8A0087E9,
0x94DAC000,
0x84D4A000,
0x76307634,
0x8006BC09,
0x8A008BFC,
0x94FA9040,
0x84F48048,
0x94D8BFFC,
0x84D4BFC0,
0xD0C78000,
0x94FA900E,
0x84F480C0,
0x94DA900E,
0x84D480C0,
0xC0C68000,
0x94D3FFFE,
0x84D59068,
0xD0C78000,
0x8A008749,
0xE30F8000,
0x80008000,
0x00000000,
0x00000000,
0x80008000,
0xE20F8000,
0x80008000,
0x00000000,
0x00000000,
0x80008000,
0xE34F8000,
0x80008000,
0x00000000,
0x00000000,
0x80008000,
0x94DA902A,
0x84D48020,
0xC0C68000,
0x84D08020,
0x84C88001,
0x93FF93EC,
0x949ABE00,
0x84949868,
0x8A0087E9,
0x762C5600,
0x76875600,
0x761C5600,
0x8A00882D,
0x07630643,
0xC0C2800C,
0x80C69C22,
0xD0C2800C,
0x8A00882D,
0x80C4BC56,
0x80C6A070,
0x76180763,
0x80C69C22,
0xD0C2800C,
0x8A00882D,
0x80C4BC56,
0x80C6C070,
0x76180763,
0x80C69C22,
0xD0C2800C,
0x8A00882D,
0x80C4BC56,
0x80C6E070,
0x76180763,
0x80C69C22,
0xD0C2800C,
0x949ABE00,
0x84949890,
0x8A0087E9,
0x94DA8000,
0x84D483F8,
0x56007614,
0xD0C28014,
0x8A008B46,
0x07637628,
0xC0C28008,
0x81879810,
0x8A00882D,
0x26CF0643,
0xC0C28014,
0x84D083FE,
0x84C88001,
0x9000942E,
0x951A9040,
0x85148048,
0xD8C28010,
0x80E6805C,
0x84D88002,
0x80C69C30,
0x80C69470,
0x94C0BFFC,
0x7683268C,
0x84C08002,
0x76837687,
0x80C6805C,
0x84C8800F,
0x90008C08,
0x76875600,
0xC0C28014,
0x84C08002,
0x7728762C,
0x27637618,
0x93FF8790,
0x94FA900E,
0x84F480C0,
0x94DA900E,
0x84D480C0,
0xC0C68000,
0x94D3FFFE,
0x84D59608,
0xD0C78000,
0x94DAC000,
0x84D4A000,
0xD0C28004,
0x94FA9040,
0x84F48048,
0x94D8BFFC,
0xD0C78000,
0x95FAC000,
0x85F483F8,
0xE30F8000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x95FAC000,
0x85F483F8,
0xE20F8000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x95FAC000,
0x85F483F8,
0xE34F8000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x80008000,
0x0F6C7608,
0x04635600,
0x84408040,
0x220A0023,
0x2C0A230A,
0x00000F34,
0x20425355,
0x746F6F42,
0x0A2E2E2E,
0x00000000,
0x61666544,
0x20746C75,
0x746F6F42,
0x0A2E2E2E,
0x00000000,
0x6F636552,
0x79726576,
0x6F6F4220,
0x2E2E2E74,
0x00000000,
0x472E2E2E,
0x000A214F,
};
