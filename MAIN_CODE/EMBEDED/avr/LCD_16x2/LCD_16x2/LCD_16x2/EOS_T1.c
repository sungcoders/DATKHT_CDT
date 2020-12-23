#include "main.h"
#include "EOS_T1.h"
#include "LCD_16x2.h"
#include <stdio.h>
#include <avr/interrupt.h>


unsigned int TCNT1_Number;

void EOS_T1_CalcuTimer(char T)
{
	TCNT1_Number= 65535-T*(F_CPU/(1000*8));
}

void EOS_T1_Init(char ms)
{
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
EOS_T1_CalcuTimer(ms);
TCNT1=TCNT1_Number;

ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
// Global enable interrupts
sei();
}
ISR (TIMER1_OVF_vect)
{
	// Reinitialize Timer1 value
	TCNT1=TCNT1_Number;
	if(Button_ReadBT1()=BT_PRESSED)
	{
		
	}
	
}