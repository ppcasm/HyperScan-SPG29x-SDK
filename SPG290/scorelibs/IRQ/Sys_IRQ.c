extern void IRQ63(void);
extern void IRQ62(void);
extern void IRQ61(void);
extern void IRQ60(void);
extern void IRQ59(void);
extern void IRQ58(void);
extern void IRQ57(void);
extern void IRQ56(void);
extern void IRQ55(void);
extern void IRQ54(void);
extern void IRQ53(void);
extern void IRQ52(void);
extern void IRQ51(void);
extern void IRQ50(void);
extern void IRQ49(void);
extern void IRQ48(void);
extern void IRQ47(void);
extern void IRQ46(void);
extern void IRQ45(void);
extern void IRQ44(void);
extern void IRQ43(void);
extern void IRQ42(void);
extern void IRQ41(void);
extern void IRQ40(void);
extern void IRQ39(void);
extern void IRQ38(void);
extern void IRQ37(void);
extern void IRQ36(void);
extern void IRQ35(void);
extern void IRQ34(void);
extern void IRQ33(void);
extern void IRQ32(void);
extern void IRQ31(void);
extern void IRQ30(void);
extern void IRQ29(void);
extern void IRQ28(void);
extern void IRQ27(void);
extern void IRQ26(void);
extern void IRQ25(void);
extern void IRQ24(void);

//====================================================
// void intmsg(void)
//
//
//
//====================================================
void intmsg(void)
{
	while(1);
}

//====================================================
// void irq_dispatch(unsigned int cp0_cause)
//
//
//
//
//====================================================
void irq_dispatch(unsigned int cp0_cause)
{
	int intvec = 0;

	intvec = (cp0_cause & 0x00FC0000)>>18;
	
	switch (intvec)
	{
		case 63:				//
	   		IRQ63();
			break;
		case 62:				//
	   		IRQ62();
			break;
		case 61:				//
	   		IRQ61();
			break;
		case 60:				//
	   		IRQ60();
			break;
		case 59:				//
	   		IRQ59();
			break;
		case 58:				//
	   		IRQ58();
			break;
		case 57:				//
	   		IRQ57();
			break;
		case 56:
			IRQ56();			//
			break;
		case 55:
			IRQ55(); 			//
			break;
		case 54:
			IRQ54();			//
			break;
		case 53:
			IRQ53();			//
			break;
 		case 52: 				//
			IRQ52();
			break;
		case 51:				//
	   		IRQ51();
			break;
		case 50:				//
	   		IRQ50();
			break;
		case 49:				//
	  	 	IRQ49();
			break;
		case 48:				//
	   		IRQ48();
			break;
		case 47:				//
	   		IRQ47();
			break;
		case 46:				//
	   		IRQ46();
			break;
		case 45:				//
	   		IRQ45();
			break;
		case 44:				//
	   		IRQ44();
			break;
		case 43:				//
	   		IRQ43();
			break;
		case 42:				//
	   		IRQ42();
			break;
		case 41:				//
	   		IRQ41();
			break;
		case 40:				//
	  	 	IRQ40();
			break;
		case 39:				//
			IRQ39();
			break;
		case 38:				//
			IRQ38();
			break;
		case 37:				//
			IRQ37();
			break;
		case 36:				//
			IRQ36();
			break;
		case 35:				//
			IRQ35();
			break;
		case 34:				//
			IRQ34();
			break;
		case 33:				//
			IRQ33();
			break;
		case 32:				//
			IRQ32();
			break;
		case 31:				//
			IRQ31();
			break;
		case 30:				//
			IRQ30();
			break;
 		case 29:				//
	   		IRQ29();
			break;
 		case 28:				//
	  	 	IRQ28();
			break;
 		case 27:				//
	  	 	IRQ27();
			break;
 		case 26:				//
	  	 	IRQ26();
			break;
 		case 25:				//
	  	 	IRQ25();
			break;
 		case 24:				//
	  	 	IRQ24();
			break;
		default:
			break;
	}
	return;
}
