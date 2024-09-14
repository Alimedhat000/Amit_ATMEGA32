#include "myI2C.h"

void init_I2C(char Address, char Clock) {
    TWAR = Address;
    TWBR = 18; // temporarly to get 100Khz
}

void I2C_Send_Start() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
}

void I2C_wait() {
    while (!(TWCR & (1 << TWINT)));
}

char I2C_Check_Status(char Status_Code) {
    return (TWSR & 0xF8) == Status_Code ? 1 : 0;
}

void I2C_Send_SLA(char SLAVE_ADDRESS, char mode) {
    if (mode == I2C_WRITE) {
        TWDR = SLAVE_ADDRESS;
    } else {
        TWDR = (SLAVE_ADDRESS) | 0x01;
    }
    TWCR = (1 << TWINT) | (1 << TWEN);
}

void I2C_Send_Data(char data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
}

void I2C_Send_Stop() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void I2C_Prepare_ACK() {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
}

/* MASTER */

void I2C_Master_Transmit(char Slave_Address, char data) {
    I2C_Send_Start(); // send Start Condition
    I2C_wait(); // wait for TWINT to clear
    if (!I2C_Check_Status(I2C_STATUS_MT_START)) // if Status is right continue
        return;
    I2C_Send_SLA(Slave_Address, I2C_WRITE);
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_SLA_ACK)) // if Status is right continue
        return;
    I2C_Send_Data(data);
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_DATA_ACK)) // if Status is right continue
        return;
    I2C_Send_Stop();
}

char I2C_Master_Recieve(char Slave_Address) {
    I2C_Send_Start();
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MT_START)) // if Status is right continue
        return;
    I2C_Send_SLA(Slave_Address, I2C_READ);
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MR_SLA_ACK)) // if Status is right continue
        return -1;
    I2C_wait();
    if (!I2C_Check_Status(I2C_STATUS_MR_DATA_ACK)) // if Status is right continue
        return -1;
    char data = TWDR;
    
    I2C_Send_Stop();
    return data;
}

void I2C_Master_Transmit_Buffer(char Slave_Address, char* data) {

}

char* I2C_Master_Recieve_Buffer(char Slave_Address) {

}

/* SLAVE */

void I2C_Slave_Transmit(char data) {
    I2C_Prepare_ACK();
    I2C_wait();

    if (I2C_Check_Status(I2C_STATUS_ST_SLA_ACK)) {
        I2C_Send_Data(data);
        I2C_wait();
        if (!(I2C_Check_Status(I2C_STATUS_ST_DATA_ACK))) // if Status is right continue
            return;
        if (!(I2C_Check_Status(I2C_STATUS_ST_LAST_DATA)))
            return;
    }
}

char I2C_Slave_Recieve() {
    I2C_Prepare_ACK();
    I2C_wait();

    if ((I2C_Check_Status(I2C_STATUS_SR_SLA_ACK)) || (I2C_Check_Status(I2C_STATUS_SR_GEN_ACK))) {
        I2C_Prepare_ACK();
        I2C_wait();
        if (!(I2C_Check_Status(I2C_STATUS_SR_DATA_ACK)) || !(I2C_Check_Status(I2C_STATUS_SR_GEN_DATA_ACK))) // if Status is right continue
            return -1;
    }
    return TWDR;
}

void I2C_Slave_Transmit_Buffer(char* data) {

}

char* I2C_Slave_Recieve_Buffer() {

}
