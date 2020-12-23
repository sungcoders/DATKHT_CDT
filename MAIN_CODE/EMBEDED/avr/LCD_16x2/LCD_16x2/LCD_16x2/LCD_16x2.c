#include "main.h"
#include "PORT.h"

#include "LCD_16x2.h"




//ham tao xung tren chan EN de LCD nhan du lieu
void LCD_Enable(void){
	PORTC |=(0x01<<LCD_EN);
	_delay_us(3);
	PORTC &=~(0x01<<LCD_EN);
	_delay_us(50);
}

//Ham Gui 4 Bit Du Lieu Ra LCD
void LCD_Send4Bit(unsigned char Data)
{
	( Data	  &1)?(PORTB |=(1<<LCD_D4)):(PORTB &=~(0x01<<LCD_D4));
	((Data>>1)&1)?(PORTB |=(1<<LCD_D5)):(PORTB &=~(0x01<<LCD_D5));
	((Data>>2)&1)?(PORTB |=(1<<LCD_D6)):(PORTB &=~(0x01<<LCD_D6));
	((Data>>3)&1)?(PORTB |=(1<<LCD_D7)):(PORTB &=~(0x01<<LCD_D7));
	

}
// Ham Gui 1 Lenh Cho LCD
void LCD_SendCommand(unsigned char command)
{
	
	LCD_Send4Bit((unsigned char)command >>4);/* Gui 4 bit cao */
	LCD_Enable();
	LCD_Send4Bit(command); /* Gui 4 bit thap*/
	LCD_Enable();
}

// Ham Xoa Man Hinh LCD
void LCD_Clear()
{
	LCD_SendCommand(0x01);
	_delay_ms(2);
}

//bat con tro, nhap nhay con tro
void LCD_BlinkPointer()
{
	LCD_SendCommand(0x0E);
}
//tat con tro, nhap nhay con tro
void LCD_BlinkPointerPlus()
{
	LCD_SendCommand(0x0F);
}
// Ham Khoi Tao LCD
void LCD_Init(){
	LCD_Send4Bit(0x00);	  //turn on LCD
	_delay_ms(20);
	PORTC &=~(0x01<<LCD_RS);	//ghi vao IR
	PORTC &=~(0x01<<LCD_RW);
	LCD_Send4Bit(0x03);	  //function setting
	LCD_Enable();
	_delay_ms(5);
	LCD_Enable();
	_delay_us(100);
	LCD_Enable();
	LCD_Send4Bit(0x02);	  //di chuyen con tro ve dau man hnh
	LCD_Enable();
	LCD_SendCommand( 0x28 ); //lua chon che do 4 bit
	LCD_SendCommand( 0x0c);  // bat hien thi va tat con tro di
	LCD_SendCommand( 0x06 ); // tu dong di chuyen con tro
	LCD_Clear();
	
}
// set toa do hien thi
void LCD_Gotoxy(unsigned char x, unsigned char y)
{
	unsigned char address;
	if(!y)address=(0x80+x);
	else address=(0xc0+x);
	LCD_SendCommand(address);
}

void LCD_PutChar(unsigned char Data)
{
	PORTC |=(0x01<<LCD_RS);	//keo RS len 1 de ghi vao DR
	LCD_SendCommand(Data);
	PORTC &=~(0x01<<LCD_RS);
}

void LCD_Puts(char *s)
{
	while (*s)
	{
		LCD_PutChar(*s);
		s++;
	}
}