typedef void ISR_HANDLER(int _vector_, void *data, void *reg_stack);
extern ISR_HANDLER *hal_interrupt_handlers[];
extern void *hal_interrupt_data[];

void irq_dispatch(register unsigned int cp0_cause)
{
	cp0_cause = (cp0_cause & 0x00FC0000) >> 18;
	(*hal_interrupt_handlers[cp0_cause])(cp0_cause, hal_interrupt_data[cp0_cause], 0);
}

void AP_Attach_ISR(register unsigned int vector, register ISR_HANDLER *_isr_, register void *data)
{
	if((0 < vector) && (vector < 64))
	{
		hal_interrupt_handlers[vector] = _isr_;
		hal_interrupt_data[vector] = data;
	}
}
