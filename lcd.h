/*
 * lcd.h
 *
 * Created: 11/13/2017 6:40:14 PM
 *  Author: M.Nasser
 */ 


#ifndef LCD_H_
#define LCD_H_


#define FIRST_POSITION 0x80
/*
initialization of LCD 
this function takes void and return void
*/
void VLcd_init(void);

/*
set 4 bits on data lines
this functions takes unsigned char and returns void
*/
void VLcd_set_bits(unsigned char);

/*
set enable pin 
this function takes void and returns void
*/
void VLcd_enable(void);
/*
send char to data lines 4bits by 4 bits
this function takes unsigned char and returns void
*/
void VLcd_send(unsigned char);

/*
send 4_lines command
this function takes unsigned char and return void
*/
void VLcd_send4_cmd(unsigned char);

/*
send character to lcd to show
this function takes unsigned char and return void
*/
void VLcd_write_char(unsigned char character);

/*
send string to lcd to show
this function takes unsigned char pointer and return void
*/
void VLcd_write_string(unsigned char* str_ptr);

/*
clear lcd 
this function takes void and return void 
*/
void VLcd_clear (void);

/*
goto position
this function takes 2 unsigned char (columns , row) and returns void
*/
void VLcd_goto(unsigned char x, unsigned char y);

#endif /* LCD_H_ */