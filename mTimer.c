#include "mTimer.h"

void Timer0_clk_select(char clk_mode) {

    TCCR0 &= ~(0x07); //reset the clk select
    TCCR0 |= (clk_mode << CS00);
}

void Timer0_mode_select(char mode) {

    TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
    switch (mode) {
        case(TIMER0_NORMAL_MODE):
            Timer0_OVF_int_en();
            break;

        case(TIMER0_PWM_MODE):
            TCCR0 |= (1 << WGM00);
            break;

        case(TIMER0_CTC_MODE):
            OCR0 = TIMER0_CTC0_DEFAULT_VALUE;
            TCCR0 |= (1 << WGM01);
            Timer0_OCM_int_en();
            break;

        case(TIMER0_FAST_PWM_MODE):
            TCCR0 |= ((1 << WGM00) | (1 << WGM01));
            break;

        default:
            break;
    }
}

void Timer0_OVF_int_en() {
    TIMSK |= (1 << TOIE0);
}

void Timer0_OCM_int_en() {
    TIMSK |= (1 << OCIE0);
}

void init_Timer0(char mode, char clk_mode) {

    TCNT0 = 0;
    Timer0_clk_select(clk_mode);
    Timer0_mode_select(mode);

}

void Timer0_OCR_set(char OCR_value) {
    OCR0 = OCR_value;
}

void Timer0_reset_prescaler() {
    SFIOR |= (1 << PSR10);
}

char Timer0_get_count() {
    return TCNT0;
}

// #############################    TIMER2     #################################

void Timer2_clk_select(char clk_mode) {
    TCCR2 &= ~(0x07);
    TCCR2 |= (clk_mode << CS20);
}

void Timer2_mode_select(char mode) {
    TCCR2 &= ~((1 << WGM20) | (1 << WGM21));

    switch (mode) {
        case(TIMER2_NORMAL_MODE):
            Timer2_OVF_int_en();
            break;

        case(TIMER2_PWM_MODE):
            TCCR2 |= (1 << WGM20);
            break;

        case(TIMER2_CTC_MODE):
            OCR2 = TIMER2_CTC2_DEFAULT_VALUE;
            TCCR2 |= (1 << WGM21);
            Timer2_OCM_int_en();
            break;

        case(TIMER2_FAST_PWM_MODE):
            TCCR2 |= ((1 << WGM20) | (1 << WGM21));
            break;

        default:
            break;
    }
}

void Timer2_OVF_int_en() {
    TIMSK |= (1 << TOIE2);
}

void Timer2_OCM_int_en() {
    TIMSK |= (1 << OCIE2);
}

void Timer2_OCR_set(char OCR_value) {
    OCR2 = OCR_value;
}

void init_Timer2(char mode, char clk_mode) {

    TCNT2 = 0;
    Timer2_clk_select(clk_mode);
    Timer2_mode_select(mode);

}

char Timer2_get_count() {
    return TCNT2;
}

void Timer2_reset_prescaler() {
    SFIOR |= (1 << PSR2);
}

void Timer2_disable_ints() {
    TIMSK &= ~((1 << OCIE2) | (1 << TOIE2));
}

void Timer2_async_en() {
    ASSR |= (1 << AS2);
}

void Timer2_sync_en() {
    ASSR &= ~(1 << AS2);
}

void Timer2_wait_busy() {
    while (ASSR & ((1 << TCR2UB) | (1 << OCR2UB) | (1 << TCN2UB)));
}

void Timer2_SwitchToAsync(char mode, char clk) {
    // Stop Timer2 by clearing the clock source bits and stop ints
    Timer2_clk_select(TIMER2_NO_CLK);
    Timer2_disable_ints();

    // Enable asynchronous mode
    Timer2_async_en();
    // Set the desired preScaler and mode
    Timer2_clk_select(clk);
    Timer2_mode_select(mode);

    // Wait for the ASSR flags to clear
    Timer2_wait_busy();

    // Clear the Timer2 counter
    TCNT2 = 0x00;
}

void Timer2_SwitchToSync(char mode, char clk) {
    // Stop Timer2 by clearing the clock source bits and stop ints
    Timer2_clk_select(TIMER2_NO_CLK);
    Timer2_disable_ints();

    // Disable asynchronous mode
    Timer2_sync_en();

    // Set the desired preScaler and mode
    Timer2_clk_select(clk);
    Timer2_mode_select(mode);

    // Wait for the ASSR flags to clear
    Timer2_wait_busy();

    // Clear the Timer2 counter
    TCNT2 = 0x00;
}
