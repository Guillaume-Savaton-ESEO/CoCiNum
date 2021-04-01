
    .set INTC_EVENTS,         0x81000004
    .set UART_DATA,           0x82000000
    .set INTC_EVENTS_UART_TX, 2

    .global main
main:
    la x1, str
    li x2, INTC_EVENTS
    li x3, UART_DATA

main_loop:
    lb x4, (x1)
    beqz x4, main_end

    sb x4, (x3)

main_polling_loop:
    lw x4, (x2)
    andi x4, x4, INTC_EVENTS_UART_TX
    beqz x4, main_polling_loop
    sw x4, (x2)

    addi x1, x1, 1
    j main_loop

main_end:
    ret

str:
    .asciz "Hello\n"
