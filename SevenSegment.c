#include "SevenSegment.h"

#include "LCD4.h"

void init_SSegment() {
    SS_DATA_DIR |= (1 << SS_A) | (1 << SS_B) | (1 << SS_C) | (1 << SS_D);
    SS_CTRl_DIR |= (1 << SS_EN1) | (1 << SS_EN2) | (1 << SS_DIP);
}

void SSegment_write(char Segment, char num) {
    // Clear the port and write the data
    SS_DATA &= 0xF0;
    switch (Segment) {
    case SS_SEG1:
        //enable Seg1 and disable Seg2
        SS_CTRl |= (1 << SS_EN1);
        SS_CTRl &= ~(1 << SS_EN2);
        // Clear the port and write the data
        SS_DATA |= (num << SS_A);
        break;
    case SS_SEG2:
        //enable Seg1 and disable Seg2
        SS_CTRl |= (1 << SS_EN2);
        SS_CTRl &= ~(1 << SS_EN1);
        // Clear the port and write the data
        SS_DATA |= (num<<SS_A);
        break;
    case SS_SEG12:
        //enable Seg1 and disable Seg2
        SS_CTRl |= (1 << SS_EN1);
        SS_CTRl |= (1 << SS_EN2);
        // Clear the port and write the data
        SS_DATA |= (num<<SS_A);
        break;
    default:
        break;

    }
}