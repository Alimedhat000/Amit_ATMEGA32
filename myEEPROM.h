#ifndef MY_EEPROM_PROJECT
#define	MY_EEPROM_PROJECT

#include <xc.h>



void EEPROM_TWI_WRITE(int Address,char Data);
char EEPROM_TWI_READ(int EEPROM_Address, int Address);


#endif	/* MY_EEPROM_PROJECT */
