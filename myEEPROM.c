#include "myEEPROM.h"
#include "myI2C.h"

void EEPROM_TWI_WRITE(int EEPROM_Address, int Address, char Data)
{
    // Send Start Condition
    I2C_Send_Start();
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_START)) {
        return;
    }
    // Send EEPROM Address
    I2C_Send_SLA(EEPROM_Address, I2C_WRITE);
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_SLA_ACK)) {
        return;
    }
    // Send memory Address
    I2C_Send_Data(Address >> 8); // Sending the higher nibble
    I2C_wait();
    I2C_Send_Data(Address); // Sending the higher nibble
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_DATA_ACK)) {
        return;
    }

    //Sending the Data
    I2C_Send_Data(Data);
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_DATA_ACK)) {
        return;
    }

    I2C_Send_Stop();
}

char EEPROM_TWI_READ(int EEPROM_Address, int Address)
{

    // Send Start Condition
    I2C_Send_Start();
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_START)) {
        return;
    }
    // Send EEPROM Address with write to edit current address
    I2C_Send_SLA(EEPROM_Address, I2C_WRITE);
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_SLA_ACK)) {
        return;
    }
    // Send memory Address
    I2C_Send_Data(Address >> 8); // Sending the higher nibble
    I2C_wait();
    I2C_Send_Data(Address); // Sending the higher nibble
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_DATA_ACK)) {
        return;
    }
    // Repeated Start Condition
    I2C_Send_Start();
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_REP_START)) {
        return;
    }
    // Send EEPROM Address with read 
    I2C_Send_SLA(EEPROM_Address, I2C_WRITE);
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MR_SLA_ACK)) {
        return;
    }
    // Receive the Data
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MR_DATA_NO_ACK)) {
        return;
    }
    char data = TWDR;
    I2C_Send_Stop();

    return data;

}