
#ifndef UART_H_
#define UART_H_

#include <InterruptController/InterruptController.h>

#define UART_BUFFER_LENGTH 16

typedef volatile struct {
    uint8_t count;
    uint8_t write_index;
    uint8_t read_index;
    uint8_t data[UART_BUFFER_LENGTH];
} UARTBuffer;

typedef struct {
    InterruptController *intc;
    uint32_t rx_irq_mask, tx_irq_mask;
    volatile uint8_t *data;
    UARTBuffer tx_buffer, rx_buffer;
    volatile bool tx_busy;
} UART;

void UART_init(UART *dev);
void UART_putc(UART *dev, uint8_t c);
uint8_t UART_getc(UART *dev);
void UART_puts(UART *dev, const uint8_t *s);
void UART_irq_handler(UART *dev);

#endif
