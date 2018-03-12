/*
 * lcd_config.h
 *
 * Created: 11/13/2017 6:40:45 PM
 *  Author: DELL
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#include <avr/io.h>




#define SMALL_SIZE   1
#define LARG_SIZE    0
#define TWO_LINES    1
#define ONE_LINE     0
#define _4_lines     0
#define _8_lines     1
#define SHIFT_RIGHT  1
#define SHIFT_LEFT   0
#define WITH_TEXT    1
#define WITHOUT_TEXT 0
#define BLINKING_ON  1
#define BLINKING_OFF 0
#define CURSOR_ON    1
#define CURSOR_OFF   0

// commands configuration
#define DISPLAY_OFF   0x08
#define CLEAR_DISPLAY 0x01
#define DISPLAY_ON    ((1<<3)|(1<<2)|(CURSOR<<1)|(CURSOR_BLINKING<<0))
#define ENTRY_MODE    ((1<<2)|(DISPLAY_MOVE<<1)|(SHIFT_TEXT<<0))
#define SET_FUNCTION  ((1<<5)|(DATA_LINES<<4)|(LINES<<3)|(FONT_SIZE<<2)) 

//data lines configurations
// for 8 lines configuration
/*
#define DB0        0
#define DB0_DIR_R  DDRB
#define DB0_DATA_R PORTB 

#define DB1        1
#define DB1_DIR_R  DDRB
#define DB1_DATA_R PORTB

#define DB2        2
#define DB2_DIR_R  DDRB
#define DB2_DATA_R PORTB

#define DB3        3
#define DB3_DIR_R  DDRB
#define DB3_DATA_R PORTB
*/

#define DB4        4
#define DB4_DIR_R  DDRB
#define DB4_DATA_R PORTB

#define DB5        5
#define DB5_DIR_R  DDRB
#define DB5_DATA_R PORTB

#define DB6        6
#define DB6_DIR_R  DDRB
#define DB6_DATA_R PORTB

#define DB7        7
#define DB7_DIR_R  DDRB
#define DB7_DATA_R PORTB


// control lines configuration
#define RS        0
#define RS_DIR_R  DDRB
#define RS_DATA_R PORTB

#define RW        1
#define RW_DIR_R  DDRB
#define RW_DATA_R PORTB

#define E        2
#define E_DIR_R  DDRB
#define E_DATA_R PORTB

//LCD configuration
#define FONT_SIZE       SMALL_SIZE    //SMALL_SIZE or LARG_SIZE
#define LINES           TWO_LINES     //TWO_LINES or ONE_LINE
#define DATA_LINES      _4_lines     //_4_lines or _8_lines
#define DISPLAY_MOVE    SHIFT_RIGHT  // SHIFT_RIGHT OR SHIFT_LEFT
#define SHIFT_TEXT      WITHOUT_TEXT // WITH_TEXT OR WITHOUT_TEXT
#define CURSOR          CURSOR_OFF    // CURSOR_ON or CURSOR_OFF
#define CURSOR_BLINKING BLINKING_OFF  // BLINKING_ON OR BLINKING_OFF

#endif /* LCD_CONFIG_H_ */