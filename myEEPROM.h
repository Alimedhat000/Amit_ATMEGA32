#ifndef MY_EEPROM_PROJECT
#define	MY_EEPROM_PROJECT

#include <xc.h>
#include "myI2C.h"
#include "mySPI.h"


void EXT_EEPROM_TWI_WRITE(int EEPROM_Address, int Address, char Data);
char EXT_EEPROM_TWI_READ(int EEPROM_Address, int Address);

void INT_EEPROM_WRITE(unsigned int address, char data);
char INT_EEPROM_READ(unsigned int address);

#endif	/* MY_EEPROM_PROJECT */
