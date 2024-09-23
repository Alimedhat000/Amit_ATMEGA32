#ifndef SEVENSEGMENT_H
#define	SEVENSEGMENT_H

#define SS_DATA PORTA
#define SS_DATA_DIR DDRA

#define SS_CTRl PORTB
#define SS_CTRl_DIR DDRB

#define SS_A PA4
#define SS_B PA5
#define SS_C PA6
#define SS_D PA7

#define SS_EN1 PB1
#define SS_EN2 PB2
#define SS_DIP PB3

#define SS_SEG1 1
#define SS_SEG2 2
#define SS_SEG12 3

void init_SSegment();
void SSegment_write(char Segment, char num);


#endif	/* SEVENSEGMENT_H */

