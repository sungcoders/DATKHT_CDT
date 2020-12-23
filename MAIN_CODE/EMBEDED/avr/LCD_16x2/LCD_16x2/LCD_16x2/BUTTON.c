#include "main.h"
#include "PORT.h"
#include "BUTTON.h"

void BT_init()
{
	BT1_PORT |= (1<<BT1);
	BT2_PORT |= (1<<BT2);
}

unsigned char Button_ReadBT1()
{
	char Return_value = BT_NOT_PRESSED;
	unsigned long Timeout_loop = 100000;

	if (!(BT1_PIN & (1<<BT1)))
	{
		_delay_us(100);
		if (!(BT1_PIN & (1<<BT1)))
		{
			while ((!(BT1_PIN & (1<<BT1))) && (--Timeout_loop != 0));
			if (Timeout_loop == 0)
			{
				Return_value = BT_NOT_PRESSED;
			}
			else
			{
				Return_value = BT_PRESSED;
			}
		}
	}
	return Return_value;
}

unsigned char Button_ReadBT2()
{
	char Return_value = BT_NOT_PRESSED;
	unsigned long Timeout_loop = 100000;

	if (!(BT2_PIN & (1<<BT2)))
	{
		_delay_us(100);
		if (!(BT2_PIN & (1<<BT2)))
		{
			while ((!(BT2_PIN & (1<<BT2))) && (--Timeout_loop != 0));

			if (Timeout_loop == 0)
			{
				Return_value = BT_NOT_PRESSED;
			}
			else
			{
				Return_value = BT_PRESSED;
			}
		}
	}
	
	return Return_value;
}
