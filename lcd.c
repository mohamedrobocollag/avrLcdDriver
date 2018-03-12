/*
 * lcd.c
 *
 * Created: 11/13/2017 6:39:47 PM
 *  Author: M.Nasser
 */ 

#include "lcd.h"
#include "lcd_config.h"
#include <util/delay.h>

/* 
initialization function 
this function takes void and return void
wait 100 ms after power on 
set data pins as output 
set RS,  RW and E as output 
send command  0x30 to start lcd
send command  0x30 to start lcd
send command  0x32 to start lcd
send function set command
send display off command
send clear display command 
send entry mode set command 
send display on command 
*/
void VLcd_init(void)
{
	//wait 100 ms after power on
	_delay_ms(100);
	
	//set data pins as output
	DB4_DIR_R |=(1<<DB4);
	DB5_DIR_R |=(1<<DB5); 
	DB6_DIR_R |=(1<<DB6);
	DB7_DIR_R |=(1<<DB7);
	
	
	//set RS,  RW and E as output
	RS_DIR_R |=(1<<RS);
	RW_DIR_R |=(1<<RW);
	E_DIR_R  |=(1<<E); 
	
	//send command  0x30 to start lcd
	VLcd_send4_cmd(0x30); 
	//send command  0x30 to start lcd
	VLcd_send4_cmd(0x30);
	//send command 0x32 to start lcd
	VLcd_send4_cmd(0x32);
	
	//send function set command
	VLcd_send4_cmd(SET_FUNCTION);
	//send display off command
	VLcd_send4_cmd(DISPLAY_OFF);
	//send clear display command 
	VLcd_send4_cmd(CLEAR_DISPLAY);
	//send entry mode set command 
	VLcd_send4_cmd(ENTRY_MODE);
	//send display on command 
	VLcd_send4_cmd(DISPLAY_ON);
	
}

/*
set 4 bits on data lines
this functions takes unsigned char and returns void
make sure DATA lines (0's)
set DATA lines to most significant bits
*/
void VLcd_set_bits(unsigned char bits)
{
	//make sure DATA lines (0's)
	DB4_DATA_R &=~(1<<DB4);
	DB5_DATA_R &=~(1<<DB5);
	DB6_DATA_R &=~(1<<DB6);
	DB7_DATA_R &=~(1<<DB7);
	
	//set DATA lines to most significant bits
	DB4_DATA_R |=(bits & (1<<DB4));
	DB5_DATA_R |=(bits & (1<<DB5));
	DB6_DATA_R |=(bits & (1<<DB6));
	DB7_DATA_R |=(bits & (1<<DB7));
}

/*
set enable pin
this function takes void and returns void
set enable pin high
delay for 20 ms
set enable pin low
set delay for 20 ms
*/
void VLcd_enable(void)
{
	E_DATA_R |=(1<<E);//set enable pin high
	_delay_ms(1);//delay for 20 ms
	E_DATA_R &=~(1<<E);//set enable pin low
	_delay_ms(1);//set delay for 20 ms
}

/*
send char to data lines 4bits by 4 bits
this function takes unsigned char and returns void
set most significant on data lines
set lest significant on data lines
*/
void VLcd_send(unsigned char data)
{
	//set most significant on data lines
	VLcd_set_bits(data);
	
	//set enable pin 
	VLcd_enable();
	
	//shift cmd to deal with lest significant bits
	data =(data<<4); 
	//set lest significant on data lines
	VLcd_set_bits(data);
	
	//set enable pin
	VLcd_enable();

}

/*
sending command to LCD using 4 lines interface
this function takes unsigned char and return void
set RW as write (0)
set SR as command mode 0
send cmd to lcd
*/
void VLcd_send4_cmd(unsigned char cmd)
{
	//set RW as write (0)
	RW_DATA_R &=~(1<<RW);
	
	//set RS as command mode 0
	RS_DATA_R &=~(1<<RS);
	
	//send cmd to lcd
	VLcd_send(cmd);
	
}

/*
sending char to LCD using 4 lines interface
this function takes unsigned char and return void
set RW as write (0)
set SR as data mode (1)
send char to lcd
*/
void VLcd_write_char(unsigned char character)
{
	//set RW as write (0)
	RW_DATA_R &=~(1<<RW);
	
	//set RS as command mode 0
	RS_DATA_R |=(1<<RS);
	
	//send char to lcd
	VLcd_send(character);
	
}

/* 
send string to lcd to show 
this functions takes unsigned char pointer and return void
while this char is not '\0' -end of string- 
show this char
*/
void VLcd_write_string(unsigned char* str_ptr)
{
	unsigned char count =0 ;
	//while this char is not '\0' -end of string-
	while (str_ptr[count]!= '\0')
	{
		//show this char
		VLcd_write_char(str_ptr[count]);
		count++;
	}	
}

/*
clear lcd
this function takes void and return void
*/
void VLcd_clear (void)
{
	VLcd_send4_cmd(CLEAR_DISPLAY);
}

/*
goto position 
this function takes 2 unsigned char (columns , row) and returns void
add rows and columns to first position 
send DDRAM ADDRESS command
*/
void VLcd_goto(unsigned char x, unsigned char y)
{
	unsigned char new_position = FIRST_POSITION+(y*(0x40))+x;
	VLcd_send4_cmd(new_position);
	
}
