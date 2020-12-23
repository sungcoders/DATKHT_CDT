/*
 * LCD_16x2.c
 *
 * Created: 11/07/2019 11:33:47 SA
 * Author : maixu
 */ 

#include "main.h"
#include "EOS_T1.h"
#include "LCD_16x2.h"
#include "PORT.h"
#include "BUTTON.h"
#include <stdio.h>

char num;
static char str[16];

int main(void)
{
	
    DDRB  |=((1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7));
	PORTB |=((1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7));
	DDRC  |=((1<<LCD_EN)|(1<<LCD_RW)|(1<<LCD_RS));
	PORTC |=((1<<LCD_EN)|(1<<LCD_RW)|(1<<LCD_RS));
	
	BT_init();
	LCD_Init();
	//EOS_T1_Init(60);
		
    while (1) 
    {
		//sprintf(str,"Number=%3d",num);
		//LCD_Gotoxy(0,0);
		//LCD_Puts(str);
    }
}

